----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/03/2019 11:17:09 PM
-- Design Name: 
-- Module Name: gain - Behavioral
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

use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_SIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity gain is
    Port (  RESET : in STD_LOGIC;
            gain_audio : in STD_LOGIC_VECTOR (15 downto 0);
           audio : in STD_LOGIC_VECTOR (15 downto 0);
           horloge : in STD_LOGIC;
           entree_prete : in STD_LOGIC;
           sortie_prete : out STD_LOGIC;
           audio_out : out STD_LOGIC_VECTOR (15 downto 0);
           transparent : in STD_LOGIC
           );
end gain;



architecture Behavioral of gain is
signal audio_in_temp :  std_logic_vector (31 downto 0);
signal audio_out_temp :  std_logic_vector (47 downto 0);
begin
 
    process ( horloge)
   variable  cpt_audio  : INTEGER;
    begin
    if (RESET = '0') then
        cpt_audio :=0;
        sortie_prete<='0';
    end if;
    if rising_edge(horloge) then 
        case cpt_audio is
                when 0 =>
                    if (entree_prete ='1') then
                        audio_in_temp(31 downto 16) <=audio(15 downto 0);
                        audio_in_temp(15 downto 0)<="0000000000000000";
                        cpt_audio:=1;
                        sortie_prete<='0'; 
                    end if;
             
                when 1 =>
                    audio_out_temp <= audio_in_temp * gain_audio;
                   --  sortie_fir[N-1:0] <= dout_mult[47:32];
                    cpt_audio:=2;
                when 2 =>
                     sortie_prete <='1';
                     if (entree_prete ='0') then --on attend que lentree valide repasse à 0
                            cpt_audio:=0;
                      end if;
                when others =>null;
        
        end case;
    end if;
  audio_out(15 downto 0 ) <= audio_out_temp(47 downto 32);
    
    end process;
end Behavioral;
