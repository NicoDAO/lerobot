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
-- 23052020 1330
--test simu
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

entity inerface_spi_materielle is

port (
		-- Users to add ports here	
		horloge_spi : in std_logic;
        SPICLK : out std_logic;
        SPIRESET : in std_logic;
        SPICS : out std_logic;
        MISO : in std_logic;
        MOSI : out std_logic ;
        COMMANDE_SPI :  in std_logic_vector (15 downto 0);
        LECTURE_SPI :  out std_logic_vector (15 downto 0);
        RW : in std_logic;
        MS : in std_logic     );
end inerface_spi_materielle;

architecture Behavioral of inerface_spi_materielle is
signal LECTURE_spi_temp :  std_logic_vector (15 downto 0);
signal act_clk  : std_logic;
begin
    process (horloge_spi)
    
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
    if rising_edge (horloge_spi) then
        report "The value of 'cpt' is " & integer'image(cpt);
        case cpt is
            when 0 =>               
                 act_clk<='1'; -- on demarre l'horloge
            when 1 =>
                SPICS <='0';
                --MOSI <= RW;
                MOSI <=COMMANDE_SPI(15);
            when 2 =>
                --MOSI <= MS;
                MOSI <=COMMANDE_SPI(14);
            when 3  =>
                MOSI <=COMMANDE_SPI(13);
           when 4  =>
                MOSI <=COMMANDE_SPI(12);
           when 5  =>
                MOSI <=COMMANDE_SPI(11);
           when 6  =>
                MOSI <=COMMANDE_SPI(10);
           when 7  =>
                MOSI <=COMMANDE_SPI(9);
           when 8  =>
                MOSI <=COMMANDE_SPI(8);
           when 9 =>
                MOSI <=COMMANDE_SPI(7);
                LECTURE_spi_temp(7)<=MISO;
           when 10 =>
                MOSI <=COMMANDE_SPI(6);
                LECTURE_spi_temp(6)<=MISO;
           when 11 =>
                MOSI <=COMMANDE_SPI(5);
                LECTURE_spi_temp(5)<=MISO;
            when 12 =>
                MOSI <=COMMANDE_SPI(4);
                LECTURE_spi_temp(4)<=MISO;
            when 13 =>
                MOSI <=COMMANDE_SPI(3);
                LECTURE_spi_temp(3)<=MISO;
            when 14 =>
                MOSI <=COMMANDE_SPI(2);
                LECTURE_spi_temp(2)<=MISO;  
           when 15 =>
                MOSI <=COMMANDE_SPI(1);
                LECTURE_spi_temp(1)<=MISO;  
            when 16 =>
                MOSI <=COMMANDE_SPI(0);
                LECTURE_spi_temp(0)<=MISO;

            when 17 =>
                 SPICS <='1'; --on remonde le chip select
                 act_clk<='0'; --on coupe l'horloge     
                 LECTURE_SPI<=LECTURE_spi_temp;
                 report "couper l horloge 'cpt' is " & integer'image(cpt);
            when others =>null  ; 
        end case;

        cpt:=cpt+1;
        if(cpt = 30) then
            cpt:=0;
        end if;   
    end if;
end process;
-- en mode concurrent
SPICLK<=horloge_spi and act_clk;
end Behavioral;
