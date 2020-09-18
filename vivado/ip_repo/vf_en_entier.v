`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2019 12:34:55 AM
// Design Name: 
// Module Name: vf_en_entier
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module vf_en_entier( entier, virgule_fixe );
    input [15:0]virgule_fixe;
    output  reg[15:0]entier;
    //assign entier[15:0] =virgule_fixe[17:2] ;//on tronque le bit de poids faible
    
    always @ ( virgule_fixe)
    begin
    if(virgule_fixe[15] == 1)
                entier <= (~virgule_fixe[15:0] & 'hEFFF);//negatif
        else
        begin
            entier <= (virgule_fixe[15:0] | 'h8000);//positif
        end
          
end



endmodule
