
///////////////////////////////////////////////////////////////////////////////////////////////////
// Company: <NICDA>
//
// File: decodeur_d_adresses.v
// File history:
//      <Revision number>: <Date>: <Comments>
//      <Revision number>: <Date>: <Comments>
//      <Revision number>: <Date>: <Comments>
//
// Description: 
//
// Mise en oeuvre FIR utilisant les blocs RAM pour stocker les chantillons et les coeficients
//
// Targeted device: SM2 
// Author: Nicolas DAOUT
//
/////////////////////////////////////////////////////////////////////////////////////////////////// 



`timescale 1 ns/100 ps


module firRAM_3
#(  parameter ordreFir = 10,
	parameter Q = 8,  //nombre de bits apres le virgule
	parameter N = 16  //nombre de bits total
	
	)
(
    input clk,
    input [N-1:0]entree_fir,
    input nouvel_echantillon,
    output [N-1:0]sortie_fir,
    input [N-1:0]g0,
    input [7:0]waddrRAMCoef,
    output reg traitement_fini,
    input ecritRAM_coef,
    input  reset
);


localparam ATTENDE=0,ECRITURE_RAM=1,INIT_MACC=2,LANCEMENT_CALCUL_MACC=3,FIN_CALCUL_MACC=4,DATA_READY=5,DATA_READY2=6; 
localparam widtha = N-1;
localparam widthb = N-1;
localparam widthc = 2*N;
localparam width_out = 2*N;

wire [2*N-1:0] dout1RAM;
wire  [N-1:0] dout1RAM_Coef;
reg signed [2*N-1:0] ech_mult;
reg signed [2*N-1:0] coef_mult;
reg signed [4*N-1:0] dout_mult;
//reg signed [2*N-1:0] mult1_mult;

//instanciation des blocs RAM
reg [7:0]waddrRAM=0,raddrRAM_audio=0,raddrRAM_Coef=0;
reg [2*N-1:0] dinRAM;
reg ecritRAM_audio;
echantillonneurRAM_2 #(1,ordreFir,2*N) RAMAudio(clk,ecritRAM_audio,raddrRAM_audio,dinRAM,waddrRAM,dout1RAM,reset);
echantillonneurRAM_2 #(2,ordreFir,N) RAMCoef(clk,ecritRAM_coef,raddrRAM_Coef,g0,waddrRAMCoef,dout1RAM_Coef,reset);

reg [5:0] machine_d_etat=0;
assign sortie_fir[N-1:0] = dout_mult[N-1:0];//41 - N


always @(posedge clk or negedge reset)
	   begin
        if(~reset)
            begin
                machine_d_etat = ATTENDE;                
                waddrRAM =0;
            end
        else
        begin
   		case(machine_d_etat)
		ATTENDE:
            begin
               traitement_fini<=0;
             if(nouvel_echantillon=='b1)  //on ecrit l'ehantillon dans la RAM audio
                begin
                   //  traitement_fini<=0;//retir
                    $display("FIR Nouvel_echantillon = %x, waddrRAM = %d",entree_fir,waddrRAM);
                    dinRAM[2*N-1:N-1] <= entree_fir[N-1:0];//on rentre l echantillon FIR en 1er dans le buffer
                    dinRAM[N-1:0] <=0;
                    $display("       = %x",dinRAM);
                    raddrRAM_Coef=0;
                    machine_d_etat = ECRITURE_RAM;
                    raddrRAM_audio = waddrRAM;
  
               end
            end

        ECRITURE_RAM:   //on ecrit l echantillon en RAM
            begin
                ecritRAM_audio <=1;// on ecrit l ecahntillon en RAM
                machine_d_etat = INIT_MACC;

            end
        INIT_MACC:
            begin
                ecritRAM_audio <=0;//on passe la RAM audio en mode lecture
                $display("          Adresse ecriture = %d , lecture  = %d",waddrRAM,raddrRAM_audio);     
                machine_d_etat = LANCEMENT_CALCUL_MACC;
                ech_mult=0;
                coef_mult=0;
                dout_mult=0;
            end

        LANCEMENT_CALCUL_MACC://on lance le calcul
            begin
                machine_d_etat = FIN_CALCUL_MACC;
                dout_mult = (ech_mult[2*N-1:0]*coef_mult>> N) + dout_mult;
            end
        
        FIN_CALCUL_MACC://le calcul MACC est termin
            begin
            ech_mult = dout1RAM;
            coef_mult[2*N-1] = dout1RAM_Coef;
            $display("==>    [%d]   X [%d]   (%x  X %x) =  %x",raddrRAM_audio,raddrRAM_Coef,dout1RAM,dout1RAM_Coef,dout_mult);
                if(raddrRAM_audio> 0)raddrRAM_audio = raddrRAM_audio -1;
                else raddrRAM_audio = ordreFir -1;//49

                 raddrRAM_Coef = raddrRAM_Coef + 1;
                if(raddrRAM_Coef == (ordreFir))// on a fait les 50 multiplications
                    begin
                      
                        machine_d_etat =ATTENDE;
                        traitement_fini<=1;
                        
                        $display("Sortie FIR(%d) : mult: %x fir: %x",ordreFir,dout_mult,sortie_fir);
                        waddrRAM  = waddrRAM + 1;//l adresse d ecriture du buffer echantillon
                        if(waddrRAM == (ordreFir))waddrRAM = 0;
                    end
                else machine_d_etat =LANCEMENT_CALCUL_MACC;
                  
            end
    /*    DATA_READY:
            begin
                machine_d_etat =ATTENDE;
                traitement_fini<=0;
            end*/
      
    default:
            begin
                machine_d_etat =ATTENDE;
            end
	endcase
end
end


endmodule



module test_firRAM_3;
parameter MAX_SIZE =500;/* Set this to the maxium image size in bytes */
reg clk,nouvel_echantillon,CS;
wire[15:0]sortie_fir;
wire traitement_fini;
reg [15:0]entree_fir,g0;
reg [7:0] waddrRAMCoef=0;
reg start =1;
integer outfile;
integer i,ordre,nb_ech;
reg [15:0] coef_fir [0:100];
reg [15:0] echantillons[0:MAX_SIZE];	
initial $readmemh("/home/nicolas/vivado/FPGA_xilinx/donnees/coef_filtre_hexa.txt",coef_fir);//../../../outils/
initial $readmemh("/home/nicolas/vivado/FPGA_xilinx/donnees/stimulus_hexa.txt",echantillons);
firRAM_3 dut( clk,entree_fir,nouvel_echantillon,sortie_fir,g0,waddrRAMCoef,traitement_fini,CS,start);	

integer  nb_coef,cpt_horloge;
initial begin	

	outfile = $fopen("/home/nicolas/vivado/FPGA_xilinx/donnees/sortie_fir_hexa.txt");
       for(nb_coef=0;nb_coef<50;nb_coef = nb_coef +1)//on rempl la table des coefs du fir
        begin
            g0 = coef_fir[nb_coef];
            waddrRAMCoef = nb_coef;
            CS =1;//on ecrit dans la memeoire des coefs
            clk = 0;
            #1;
            clk = 1;
            #5;
            CS =0;
            #1;
            $display("coeficients %x = %x",nb_coef,g0);
        end
      
	nouvel_echantillon = 0;
	#20
	$display("\n\ntest FIR RAM3 echantillonage \n\n");

	for(nb_ech =0; nb_ech <MAX_SIZE; nb_ech = nb_ech +1)
		begin
        cpt_horloge = 0;
		entree_fir = echantillons[nb_ech]; 
		nouvel_echantillon = 1;
        $display("[%d] echantillon %x",nb_ech,entree_fir);
		#1
		clk = 0;
		#1;
		clk = 1;
		#1;
		clk = 0;
		#1;
		clk = 1;
		#1;
		nouvel_echantillon = 0;
		#10
		clk = 0;

		while(~traitement_fini)
			begin
				clk = 0;
				#5;
				clk = 1;
				#5;
                cpt_horloge = cpt_horloge + 1;
            end
        
        for(i = 0; i < 50; i = i + 1) //quelques coups d horloge supplemntaires
            begin
                clk = 0;
				#1;
				clk = 1;
				#1;
            end
		$fwrite(outfile, "%x \n",sortie_fir);
        $display("  sortie FIR :%x  (%d coups d horloge)",sortie_fir,cpt_horloge);
		
	end
	$fclose(outfile);
end
 
endmodule 
 