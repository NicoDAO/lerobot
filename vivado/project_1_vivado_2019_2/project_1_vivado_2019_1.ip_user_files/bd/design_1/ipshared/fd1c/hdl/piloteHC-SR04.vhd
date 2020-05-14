----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.01.2020 23:03:00
-- Design Name: 
-- Module Name: piloteHC-SR04 - Behavioral
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
use ieee.numeric_std.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity piloteHC_SR04 is
	generic (
		  C_S_AXI_DATA_WIDTH	: integer	:= 32
	);
    Port ( entree_echo : in STD_LOGIC;
           sortie_trig : out STD_LOGIC;
           horloge : in STD_LOGIC;
           reset : in STD_LOGIC;
           distance : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0)
           );
end piloteHC_SR04;

architecture Behavioral of piloteHC_SR04 is

begin
   process (horloge)
      variable cpt :INTEGER :=0; 
      variable sortie :INTEGER :=0; 
     
      begin
        if rising_edge (horloge) then
            if reset = '0' then
                sortie_trig<='0';
                cpt:=0;
                sortie :=0;
            else
                case cpt is
                   when 0 =>
                           sortie_trig<='0';
                           sortie :=0;
                 --  when 1 to 20 => --10us
                  when 1 to 1000 => --10us
                           sortie_trig<='1';
                --   when 21 to 200000 => --100 000 us
                 when 1001 to 30000000 => --100 000 us
                           sortie_trig<='0';  
                           if (entree_echo ='1') then
                                sortie := sortie+1;
                           end if;
                --   when 200001 =>
                when  30000001 =>
                            --distance  <="00000000000000000000000000000101";--<= std_logic_vector(to_unsigned(sortie,32));
                            distance  <= std_logic_vector(to_unsigned(sortie,32));
                   when  others => null;
                 end case;
                
                cpt:=cpt+1;
                if(cpt = 30000002) then
                    cpt:=0;
                end if;   
            end if;
    end if;
    end process;
end Behavioral;
