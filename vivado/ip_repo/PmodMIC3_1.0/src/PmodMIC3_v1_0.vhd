library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PmodMIC3_v1_0 is
	generic (
		-- Users to add parameters here

		-- User parameters ends
		-- Do not modify the parameters beyond this line


		-- Parameters of Axi Slave Bus Interface S00_AXI
		C_S00_AXI_DATA_WIDTH	: integer	:= 32;
		C_S00_AXI_ADDR_WIDTH	: integer	:= 4
	);
	port (
		-- Users to add ports here
        sdi_mic     :   in std_logic;
        sck_mic     :   out std_logic;
        cs_mic      :   out std_logic;
        audio_out : out std_logic_vector (23 downto 0);
        audio_valid : out STD_LOGIC;
    
		s00_axi_aclk	: in std_logic;
		s00_axi_aresetn	: in std_logic
	
	);
end PmodMIC3_v1_0;

architecture arch_imp of PmodMIC3_v1_0 is

	

begin
entre_micro_inst : entity work.entre_micro port map(
                            clk_in=>s00_axi_aclk,
                            reset_n=>s00_axi_aresetn,
                             sdi_mic=>sdi_mic,
                             sckd_mic=>sck_mic,
                             cs_mic=>cs_mic,
                             audio_out=>audio_out,
                             audio_valid=>audio_valid);
                             

	-- User logic ends

end arch_imp;
