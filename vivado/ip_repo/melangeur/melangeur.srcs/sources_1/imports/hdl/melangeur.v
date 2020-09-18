///////////////////////////////////////////////////////////////////////////////////////////////////
// Company: <Name>
//
// File: melangeur.v
// File history:
//      <Revision number>: <Date>: <Comments>
//      <Revision number>: <Date>: <Comments>
//      <Revision number>: <Date>: <Comments>
//
// Description: 
//
// <Description here>
//
// Targeted device: <Family::SmartFusion2> <Die::M2S010> <Package::484 FBGA>
// Author: <Name>
//
/////////////////////////////////////////////////////////////////////////////////////////////////// 

//`timescale <time_units> / <precision>

module melangeur( clk,voieA, voieB, entree_prete,sortieMelangeur,sortie_prete );
input [17:0]voieA, voieB;
input entree_prete;
input clk;
output [17:0]sortieMelangeur;
output reg sortie_prete;
//additionneur virgule fixe
assign sortieMelangeur = voieA + voieB;
reg  [17:0]a;

   
   always @(posedge clk)
    begin
    
    
    end
endmodule

