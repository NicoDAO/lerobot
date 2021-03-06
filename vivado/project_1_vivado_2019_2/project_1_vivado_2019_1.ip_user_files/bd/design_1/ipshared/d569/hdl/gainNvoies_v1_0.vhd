library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity gainNvoies_v1_0 is
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
        audio_in_1: in std_logic_vector (15 downto 0);
        audio_in_2: in std_logic_vector (15 downto 0);
        audio_in_3: in std_logic_vector (15 downto 0);
        audio_in_4: in std_logic_vector (15 downto 0);
        
        audio_in_1_pret: in std_logic;
        audio_in_2_pret: in std_logic;
        audio_in_3_pret: in std_logic;
        audio_in_4_pret: in std_logic;
        
        audio_out_1: out std_logic_vector (15 downto 0);
        audio_out_2: out std_logic_vector (15 downto 0);
        audio_out_3: out std_logic_vector (15 downto 0);
        audio_out_4: out std_logic_vector (15 downto 0);
        
        sortie_out_1_pret: out std_logic;
        sortie_out_2_pret: out std_logic;
        sortie_out_3_pret: out std_logic;
        sortie_out_4_pret: out std_logic;
        
		-- User ports ends
		-- Do not modify the ports beyond this line


		-- Ports of Axi Slave Bus Interface S00_AXI
		s00_axi_aclk	: in std_logic;
		s00_axi_aresetn	: in std_logic;
		s00_axi_awaddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
		s00_axi_awprot	: in std_logic_vector(2 downto 0);
		s00_axi_awvalid	: in std_logic;
		s00_axi_awready	: out std_logic;
		s00_axi_wdata	: in std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
		s00_axi_wstrb	: in std_logic_vector((C_S00_AXI_DATA_WIDTH/8)-1 downto 0);
		s00_axi_wvalid	: in std_logic;
		s00_axi_wready	: out std_logic;
		s00_axi_bresp	: out std_logic_vector(1 downto 0);
		s00_axi_bvalid	: out std_logic;
		s00_axi_bready	: in std_logic;
		s00_axi_araddr	: in std_logic_vector(C_S00_AXI_ADDR_WIDTH-1 downto 0);
		s00_axi_arprot	: in std_logic_vector(2 downto 0);
		s00_axi_arvalid	: in std_logic;
		s00_axi_arready	: out std_logic;
		s00_axi_rdata	: out std_logic_vector(C_S00_AXI_DATA_WIDTH-1 downto 0);
		s00_axi_rresp	: out std_logic_vector(1 downto 0);
		s00_axi_rvalid	: out std_logic;
		s00_axi_rready	: in std_logic
	);
end gainNvoies_v1_0;

architecture arch_imp of gainNvoies_v1_0 is

	-- component declaration
	component gainNvoies_v1_0_S00_AXI is
		generic (
		C_S_AXI_DATA_WIDTH	: integer	:= 32;
		C_S_AXI_ADDR_WIDTH	: integer	:= 4
		);
		port (
		
         AUDIO_IN_1_h: in std_logic_vector (15 downto 0);
         AUDIO_IN_2_h: in std_logic_vector (15 downto 0);
         AUDIO_IN_3_h: in std_logic_vector (15 downto 0);
        AUDIO_IN_4_h: in std_logic_vector (15 downto 0);
         
        AUDIO_IN_1_pret_h: in std_logic;
        AUDIO_IN_2_pret_h: in std_logic;
        AUDIO_IN_3_pret_h: in std_logic;
        AUDIO_IN_4_pret_h: in std_logic;
         
        AUDIO_OUT_1_h: out std_logic_vector (15 downto 0);
        AUDIO_OUT_2_h: out std_logic_vector (15 downto 0);
        AUDIO_OUT_3_h: out std_logic_vector (15 downto 0);
        AUDIO_OUT_4_h: out std_logic_vector (15 downto 0);
         
        SORTIE_OUT_1_pret_h: out std_logic;
        SORTIE_OUT_2_pret_h: out std_logic;
        SORTIE_OUT_3_pret_h: out std_logic;
        SORTIE_OUT_4_pret_h: out std_logic;
        
         
		S_AXI_ACLK	: in std_logic;
		S_AXI_ARESETN	: in std_logic;
		S_AXI_AWADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		S_AXI_AWPROT	: in std_logic_vector(2 downto 0);
		S_AXI_AWVALID	: in std_logic;
		S_AXI_AWREADY	: out std_logic;
		S_AXI_WDATA	: in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		S_AXI_WSTRB	: in std_logic_vector((C_S_AXI_DATA_WIDTH/8)-1 downto 0);
		S_AXI_WVALID	: in std_logic;
		S_AXI_WREADY	: out std_logic;
		S_AXI_BRESP	: out std_logic_vector(1 downto 0);
		S_AXI_BVALID	: out std_logic;
		S_AXI_BREADY	: in std_logic;
		S_AXI_ARADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		S_AXI_ARPROT	: in std_logic_vector(2 downto 0);
		S_AXI_ARVALID	: in std_logic;
		S_AXI_ARREADY	: out std_logic;
		S_AXI_RDATA	: out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		S_AXI_RRESP	: out std_logic_vector(1 downto 0);
		S_AXI_RVALID	: out std_logic;
		S_AXI_RREADY	: in std_logic
		);
	end component gainNvoies_v1_0_S00_AXI;

begin

-- Instantiation of Axi Bus Interface S00_AXI
gainNvoies_v1_0_S00_AXI_inst : gainNvoies_v1_0_S00_AXI
	generic map (
		C_S_AXI_DATA_WIDTH	=> C_S00_AXI_DATA_WIDTH,
		C_S_AXI_ADDR_WIDTH	=> C_S00_AXI_ADDR_WIDTH
	)
	port map (
	
        AUDIO_IN_1_h => audio_in_1,
        AUDIO_IN_2_h => audio_in_2,
        AUDIO_IN_3_h => audio_in_3,
        AUDIO_IN_4_h => audio_in_4,
        
        AUDIO_IN_1_pret_h =>  audio_in_1_pret,
        AUDIO_IN_2_pret_h =>  audio_in_2_pret,
        AUDIO_IN_3_pret_h =>  audio_in_3_pret,
        AUDIO_IN_4_pret_h =>  audio_in_4_pret,
	
	    AUDIO_OUT_1_h => audio_out_1,
        AUDIO_OUT_2_h => audio_out_2,
        AUDIO_OUT_3_h => audio_out_3,
        AUDIO_OUT_4_h => audio_out_4,      

        SORTIE_OUT_1_pret_h =>sortie_out_1_pret,
        SORTIE_OUT_2_pret_h =>sortie_out_2_pret,
        SORTIE_OUT_3_pret_h =>sortie_out_3_pret,
        SORTIE_OUT_4_pret_h =>sortie_out_4_pret,

		S_AXI_ACLK	=> s00_axi_aclk,
		S_AXI_ARESETN	=> s00_axi_aresetn,
		S_AXI_AWADDR	=> s00_axi_awaddr,
		S_AXI_AWPROT	=> s00_axi_awprot,
		S_AXI_AWVALID	=> s00_axi_awvalid,
		S_AXI_AWREADY	=> s00_axi_awready,
		S_AXI_WDATA	=> s00_axi_wdata,
		S_AXI_WSTRB	=> s00_axi_wstrb,
		S_AXI_WVALID	=> s00_axi_wvalid,
		S_AXI_WREADY	=> s00_axi_wready,
		S_AXI_BRESP	=> s00_axi_bresp,
		S_AXI_BVALID	=> s00_axi_bvalid,
		S_AXI_BREADY	=> s00_axi_bready,
		S_AXI_ARADDR	=> s00_axi_araddr,
		S_AXI_ARPROT	=> s00_axi_arprot,
		S_AXI_ARVALID	=> s00_axi_arvalid,
		S_AXI_ARREADY	=> s00_axi_arready,
		S_AXI_RDATA	=> s00_axi_rdata,
		S_AXI_RRESP	=> s00_axi_rresp,
		S_AXI_RVALID	=> s00_axi_rvalid,
		S_AXI_RREADY	=> s00_axi_rready
	);

	-- Add user logic here

	-- User logic ends

end arch_imp;
