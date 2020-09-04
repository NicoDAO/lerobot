`timescale 1 ns/100 ps

module echantillonneurRAM_2#(  
 	parameter num = 3,  //nombre de bits total
    parameter taille_mem=64,
    parameter taille_mot = 32
	)(clk,wr,raddr,din,waddr,dout1,reset);
input clk,reset;
input [taille_mot-1:0] din;
input wr;
input [7:0] waddr,raddr;

output reg[taille_mot-1:0] dout1  ;

reg [taille_mot-1:0] mem [taille_mem-1:0];
always@(posedge clk)
begin

       /* if(~reset)
        begin

        end
        else*/
        begin
            if(wr)// un nouvel echantillon est arriv
                begin
                mem[waddr] <= din;
                //   $display("     (%d)Ecrit ds mem[%d] = %x ",num,waddr,din);
                end
            else
                begin
                    dout1 <= mem[raddr];
                 //   $display("     (%d)lit mem[%d] = %x ",num,raddr,mem[raddr]);
             end
        end //reset
end

endmodule



