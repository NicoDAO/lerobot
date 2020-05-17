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

entity spi_gyro is
    Port ( sdi_gyro : in STD_LOGIC;
           sdo_gyro : out STD_LOGIC;
           cs_gyro : out STD_LOGIC;
           clk_gyro : in STD_LOGIC;
           int1_gyro : out STD_LOGIC;
           int2_gyro : out STD_LOGIC;
           horloge : in STD_LOGIC;
           reset_n : in STD_LOGIC;
           donnee_X : out std_logic_vector (15 downto 0);
           donnee_Y : out std_logic_vector (15 downto 0);
           donnee_Z : out std_logic_vector (15 downto 0) );

end spi_gyro;

architecture Behavioral of spi_gyro is
signal        act_clk : std_logic;
signal        SPICLK : std_logic;
signal        SPIRESET : std_logic;
signal        SPICS : std_logic;
signal        MISO : std_logic;
signal        MOSI :  std_logic;     

begin

      -- I/O Connections assignments
    inerface_spi_inst : entity work.inerface_spi port map(SPICLK=>SPICLK,SPIRESET=>SPIRESET,SPICS=>SPICS,MISO=>MISO,MOSI=>MOSI);

   process (horloge)
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

        cpt:=0;
        
        cs_gyro<='1';
        act_clk<='1';
    end if;
     if rising_edge (horloge)
         then
         case cpt is
                when 0 =>
                     act_clk<='1'; 
                 when 1 to 4 => 
                     cs_gyro<='0'; 
                       cpt_test :=cpt_test + 1;
              --  when 1 to 4 => 
              --       act_clk<='1'; 
              
                when others=> null;

         end case;     
         cpt:=cpt+1;
        
        if(cpt = 100) then
            cpt:=0;
        end if;   
       end if;
end process;
    

end Behavioral;
