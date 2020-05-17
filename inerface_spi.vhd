----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 17.05.2020 23:09:51
-- Design Name: 
-- Module Name: inerface_spi - Behavioral
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

entity inerface_spi is

port (
		-- Users to add ports here	
        SPICLK : in std_logic;
        SPIRESET : in std_logic;
        SPICS : out std_logic;
        MISO : in std_logic;
        MOSI : out std_logic  );
end inerface_spi;

architecture Behavioral of inerface_spi is

begin
    process (SPICLK)
    
        variable cpt :INTEGER :=0;  
        variable cpt_test : INTEGER :=0; 
        variable adresse_registre : INTEGER :=0; 
        variable valeur_registre : INTEGER :=0; 
     begin   
    
    if (SPIRESET = '0') then

        cpt:=0;
    end if;
    if rising_edge (SPICLK) then
     cpt:=0;
   
    end if;
    
 end process;

end Behavioral;
