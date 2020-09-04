//module vf_en_entier(nv_echantillon1, entier, virgule_fixe );
//    input [15:0]virgule_fixe;
//    output  reg[15:0]entier;
//    input nv_echantillon1;
//    always @ ( posedge nv_echantillon1)
//    begin
//    if(virgule_fixe[15] == 1)
//            entier <= (~virgule_fixe[15:0] & 'hEFFF);//negatif
//        else
//        begin
//            entier <= (virgule_fixe[15:0] | 'h8000);//positif
//        end
          
//end

//endmodule


module interface_DAC16bits( clk_in,audio_in0,SCLK, sync, audio_out ,nv_echantillon1,reset,LDAC);

output reg SCLK;
output reg sync;
output reg  audio_out;
output reg  LDAC;
input nv_echantillon1;
input [15:0]audio_in0;

input reset;
reg [3:0]commande_dac0;

wire [15:0] tampon_sortie1;
reg [15:0]data_audio0;
reg [10:0] cpt = 0;
reg [3:0]ctrl_dac;
input clk_in;
reg[7:0]cpt_clk,index_audio;
reg echantillon_pret;
reg demarre =0;
reg deb_transmission;
reg [7:0]cpt_conf = 0;
reg[15:0]entier;

     
assign    tampon_sortie1[0] =  entier[15];//bit de signe test 0;//audio_in0[15];
assign    tampon_sortie1[1] =  entier[14];
assign    tampon_sortie1[2] =  entier[13];
assign    tampon_sortie1[3] =  entier[12];
assign    tampon_sortie1[4] =  entier[11];
assign    tampon_sortie1[5] =  entier[10];
assign    tampon_sortie1[6] =  entier[09];
assign    tampon_sortie1[7] =  entier[08];
assign    tampon_sortie1[8] =  entier[07];
assign    tampon_sortie1[9] =  entier[06];
assign    tampon_sortie1[10] = entier[05];
assign    tampon_sortie1[11] = entier[04];
assign    tampon_sortie1[12] = entier[03];//audio_in0[11];//bit de signe test 0;//audio_in0[15];
assign    tampon_sortie1[13] = entier[02];//audio_in0[15];
assign    tampon_sortie1[14] = entier[01];
assign    tampon_sortie1[15] = entier[00];


// vf_en_entier convertit(nv_echantillon1,entier,audio_in0);

initial
    begin
        cpt_clk = 0;
        deb_transmission = 0;
        LDAC = 1;
        index_audio =0;
    end

always @ (posedge clk_in )
    begin
       
       if((nv_echantillon1 ==1)&&(reset ==1)&&(deb_transmission ==0) )
            begin
                
                deb_transmission <=1;
                cpt_clk <= 0;
                echantillon_pret <=0;
                index_audio <=0 ;
                
                if(audio_in0[15] == 1)
                    entier <= (audio_in0[15:0] & 'h7FFF);//negatif
                else
                begin
                    entier <= (audio_in0[15:0] | 'h8000);//positif
                end
//                    if(audio_out_temp(15) = '1') --passage en nombre signé
//                    then 
//                        audio_out <= (audio_out_temp and masque_pos);--positif
//                     else
//                        audio_out <= audio_out_temp or masque_neg;--negatif
//                     end if;
                     
        end
        if(deb_transmission ==1)
        begin
            case (cpt_clk)
            0:
                begin
                index_audio <=0;
                sync <=0;
                LDAC<=1;
           
                   $display("sortie DAC // = %x , ",entier);
                
                end
            16:
                begin
                    sync <=1;
                   
               end
            17:
                begin
                    LDAC<=0;
                end
            18:
                begin
                 LDAC<=1;
                deb_transmission <=0;
                
                end
            
            default:
                begin
                    index_audio <=index_audio+1 ;//compte quand cpt_clk fait 1,2,3,...,15
                end
            endcase //cpt_clk

        if( cpt_clk <20)
            begin
                cpt_clk <= cpt_clk + 1;
            end 
            else
            begin
                cpt_clk <= 0;
            end 
        end //if(deb_transmission ==1)
 end //case 4


always@(*)
begin
if(sync ==0)
    begin
        audio_out = tampon_sortie1[index_audio];// test 1 voie sortie_audio[cpt_clk];
        SCLK = clk_in ;
    end
end
endmodule


