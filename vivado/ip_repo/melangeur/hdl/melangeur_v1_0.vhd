----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.03.2018 22:19:54
-- Design Name: 
-- Module Name: entre_micro - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use std.textio.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity melangeur is
    Port ( 
         clk_in  :in STD_LOGIC;
         reset_n : in STD_LOGIC;
         audio_in_1: in std_logic_vector (15 downto 0);
         audio_in_2: in std_logic_vector (15 downto 0);
         audio_in_3: in std_logic_vector (15 downto 0);
         audio_in_4: in std_logic_vector (15 downto 0);
         audio_valid_in_1 : in STD_LOGIC;
         audio_valid_in_2 : in STD_LOGIC;
         audio_valid_in_3 : in STD_LOGIC;
         audio_valid_in_4 : in STD_LOGIC;
         audio_out : out std_logic_vector (15 downto 0);
         audio_valid_out : out STD_LOGIC
         );
end melangeur;

architecture Behavioral of melangeur is


signal audio_in_1_temp :  std_logic_vector (15 downto 0);
signal audio_in_2_temp :  std_logic_vector (15 downto 0);
signal audio_in_3_temp :  std_logic_vector (15 downto 0);
signal audio_in_4_temp :  std_logic_vector (15 downto 0);

-- signal clk_lente :std_logic;

begin
         
   process (clk_in)
   variable cpt :INTEGER :=0;  
   variable addition_faite : INTEGER :=0; 
     
   begin
     
    if (reset_n = '0') then

        audio_valid_out<='0';
        cpt:=0;
        addition_faite :=0;

    end if;
     if rising_edge (clk_in)
         then
         if (audio_valid_in_1='1')-- and audio_valid_in_1 = '1')
             then
             audio_in_1_temp <= audio_in_1;
         end if;
         if (audio_valid_in_2='1')-- and audio_valid_in_1 = '1')
             then
             audio_in_2_temp <= audio_in_2;
         end if;
         if (audio_valid_in_3='1')-- and audio_valid_in_1 = '1')
             then
             audio_in_3_temp <= audio_in_3;
         end if;
         if (audio_valid_in_4='1')-- and audio_valid_in_1 = '1')
             then
             audio_in_4_temp <= audio_in_4;
         end if;
         case cpt is
            when 0 =>
                audio_valid_out<='0';  
               
            when 1 =>
                audio_out <= audio_in_1_temp + audio_in_2_temp + audio_in_3_temp + audio_in_4_temp;
               
                addition_faite := 1;
             when 2 =>
                 audio_valid_out<='1';   
            
            when others=> null;

            end case;  
         cpt:=cpt + 1; 
         if(cpt = 50) then
            cpt:=0;
          end if;
         end if;
end process;
    
-- en mode concurrent
-- audio_out <= audio_in_1 + audio_in_2;
--sck_mic<=clk_in and act_clk;

end Behavioral;
