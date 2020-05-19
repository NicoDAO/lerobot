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
		horloge : in std_logic;
        SPICLK : out std_logic;
        SPIRESET : in std_logic;
        SPICS : out std_logic;
        MISO : in std_logic;
        MOSI : out std_logic ;
        COMMANDE_SPI :  in std_logic_vector (15 downto 0);
        LECTURE_SPI :  out std_logic_vector (15 downto 0);
        RW : in std_logic;
        MS : in std_logic     );
end inerface_spi;

architecture Behavioral of inerface_spi is
signal LECTURE_spi_temp :  std_logic_vector (15 downto 0);
signal act_clk  : std_logic;
begin
    process (horloge)
    
        variable cpt :INTEGER :=0;  
        variable cpt_test : INTEGER :=0; 
        variable adresse_registre : INTEGER :=0; 
        variable valeur_registre : INTEGER :=0; 
       
     begin   
    
    if (SPIRESET = '0') then
          LECTURE_spi_temp<="0000000000000000";
          act_clk<='0';
          cpt:=0;
    end if;
    if rising_edge (horloge) then
        case cpt is
            when 0 =>
                SPICS <='0';
                MOSI <= RW;
                 act_clk<='1';
            when 1 =>
                MOSI <= MS;
            when 2 TO 7 =>
                SPICS <='0';
                MOSI <=COMMANDE_SPI(cpt-2);
            when 8 to 15 =>
                LECTURE_spi_temp(cpt-8)<=MISO;
            when 15 =>
                 SPICS <='1';
                  act_clk<='1';
                 LECTURE_SPI<=LECTURE_spi_temp;
            when others =>null  ; 
        end case;
    end if;
    cpt:=cpt+1;
    if(cpt = 100) then
        cpt:=0;
    end if;   

end process;
-- en mode concurrent
SPICLK<=horloge and act_clk;
end Behavioral;
