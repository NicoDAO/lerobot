----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11.05.2020 23:24:40
-- Design Name: 
-- Module Name: spi_gyro - Behavioral
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

entity spi_gyro_commande is
	generic (
		DIVISEUR_HORLOGE	: integer	:= 32
		);
    Port ( 
           sdi_gyro : in STD_LOGIC;
           sdo_gyro : out STD_LOGIC;
           cs_gyro : out STD_LOGIC;
           clk_gyro : out STD_LOGIC;
           int1_gyro : in STD_LOGIC;
           int2_gyro : in STD_LOGIC;
           horloge_gyro : in STD_LOGIC;
           reset_n : in STD_LOGIC;
           adresse_registre : in std_logic_vector (7 downto 0);
           whoami :   out std_logic_vector (15 downto 0);
           donnee_X : out std_logic_vector (15 downto 0);
           donnee_Y : out std_logic_vector (15 downto 0);
           donnee_Z : out std_logic_vector (15 downto 0) );

end spi_gyro_commande;

architecture Behavioral of spi_gyro_commande is
    signal        act_clk : std_logic;
    --signal        SPICLK : std_logic;
    signal        SPIRESET : std_logic;
    signal        SPICS : std_logic;
    signal        MISO : std_logic;
    signal        MOSI :  std_logic;     
    signal        COMMANDE_SPI :  std_logic_vector (15 downto 0);
    signal        LECTURE_SPI :  std_logic_vector (15 downto 0);
    signal        RW : std_logic;
    signal        MS : std_logic  ;
    signal        horloge_g  : std_logic;

    begin

    -- I/O Connections assignments
--    diviseur_horloge_inst : entity work.diviseur_horloge port map (entree_horloge=>horloge_gyro,
--            horloge_divisu=>horloge_g,reset_n=>reset_n);
   diviseur_horloge_inst : entity work.diviseur_horloge port map (entree_horloge=>horloge_gyro,
            horloge_divisu=>horloge_g,reset_n=>reset_n);

    inerface_spi_inst : entity work.inerface_spi_materielle port map( horloge_spi=>horloge_gyro,SPICLK=>clk_gyro,
            SPIRESET=>SPIRESET,SPICS=>SPICS,MISO=>sdi_gyro,MOSI=>sdo_gyro,
            COMMANDE_SPI=>COMMANDE_SPI,LECTURE_SPI=>LECTURE_SPI,
            RW=>RW,MS=>MS);
-- end entity;   

--end entity;

 
  
process (horloge_gyro)
   variable cpt :INTEGER :=0;  
   variable cpt_test : INTEGER :=0; 
   variable adresse_registre : INTEGER :=0; 
    variable valeur_registre : INTEGER :=0; 
   begin
       
    if (reset_n = '0') then
       -- audio_out <="0000000000000000";
        donnee_X<="0000000000000000";
        donnee_Y<="0000000000000000";
        donnee_Z<="0000000000000000";
        whoami<="0000000000000000";
       -- spiclk<='0';
        horloge_g<='0';
        cpt:=0;

    end if;
     if rising_edge (horloge_gyro)
         then
         case cpt is
                when 0 =>
                   RW <='1'; --on place les données on ecrit
                   MS<='0';
                   COMMANDE_SPI<=x"0055" ; --WHO_AM_I
                   SPIRESET<='0';
                 when 1 =>  -- on lance le SPI
                    SPIRESET<='1';
                  when 50 =>  -- on attend
                     whoami<=LECTURE_SPI;
                     RW <='1'; --on lit
                     SPIRESET<='0';
                   when 51 =>  -- on attend
                  when others=> null;
                end case;     
            cpt:=cpt+1;
        
        if(cpt =51) then
            cpt:=0;
            end if;   
     end if;
end process;   

end Behavioral;




