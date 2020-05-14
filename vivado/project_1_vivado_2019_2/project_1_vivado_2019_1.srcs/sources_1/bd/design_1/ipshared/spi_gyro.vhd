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
           cs_gyro : in STD_LOGIC;
           clk_gyro : in STD_LOGIC;
           int1_gyro : out STD_LOGIC;
           int2_gyro : out STD_LOGIC);

end spi_gyro;

architecture Behavioral of spi_gyro is

begin


end Behavioral;
