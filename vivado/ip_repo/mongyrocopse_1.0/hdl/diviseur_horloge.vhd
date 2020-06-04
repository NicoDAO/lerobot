----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 23.05.2020 17:02:35
-- Design Name: 
-- Module Name: diviseur_horloge - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity diviseur_horloge is

    Port ( entree_horloge : in STD_LOGIC;
           horloge_divisu : out STD_LOGIC;
           reset_n : in STD_LOGIC);
end diviseur_horloge;

architecture Behavioral of diviseur_horloge is

    begin 
    process (entree_horloge)
    variable cpt :INTEGER :=0;  
  
    begin
    if (reset_n = '0') then
        cpt:=0;
        horloge_divisu<='0';
    end if;
    if falling_edge (entree_horloge)
     then
     case cpt is
            when 0 =>
                  horloge_divisu<='0';
             when 10 =>
                horloge_divisu<='1';
              
            when others=> null;
            end case;     
            cpt:=cpt+1;
    
    if(cpt =20) then
        cpt:=0;
        end if;   
    end if;
    end process;

end Behavioral;
