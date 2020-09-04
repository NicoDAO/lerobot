library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity pmod_audio_v1_0 is
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
	
        out1 : out std_logic;
        out2 : out std_logic;
        out3 : out std_logic;
        out4 : out std_logic;
        --clk_i2s=>BCLK,pb_dat=>PBDAT,gain_ampli=>GAINAMPLI,clk_filtre=>S_AXI_ACLK,sortie_pwm=>SORTIEPWM,shd_ampli=>SHDAMPLI,audio1=>slv_reg0);
        gain_ampli: out std_logic;
        sortie_pwm: out std_logic;
        shd_ampli: out std_logic;
        
        entree_audio1 : in std_logic_vector(23 downto 0);
        entree_audio1_prete :in std_logic;
        
        clk_pwm:in std_logic;
        
        
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
end pmod_audio_v1_0;

architecture arch_imp of pmod_audio_v1_0 is

	-- component declaration
	component pmod_audio_v1_0_S00_AXI is
		generic (
		C_S_AXI_DATA_WIDTH	: integer	:= 32;
		C_S_AXI_ADDR_WIDTH	: integer	:= 4
		);
		port (
		  	
            OUT_1 : out std_logic;
            OUT_2 : out std_logic;
            OUT_3 : out std_logic;
            OUT_4 : out std_logic;
            
            GAINAMPLI :  out std_logic;
            SORTIEPWM : out std_logic;
            SHDAMPLI : out std_logic;

            ENTREEAUDIO1 : in std_logic_vector (23 downto 0);
            ENTREEAUDIO1PRETE : in std_logic;
            
            CLKPWM:in std_logic; 
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
	end component pmod_audio_v1_0_S00_AXI;

begin

-- Instantiation of Axi Bus Interface S00_AXI
pmod_audio_v1_0_S00_AXI_inst : pmod_audio_v1_0_S00_AXI
	generic map (
		C_S_AXI_DATA_WIDTH	=> C_S00_AXI_DATA_WIDTH,
		C_S_AXI_ADDR_WIDTH	=> C_S00_AXI_ADDR_WIDTH
	)
	port map (
        
    		OUT_1 	=> out1,
			OUT_2 	=> out2,
			OUT_3 	=> out3,
			OUT_4 	=> out4,

            GAINAMPLI   =>   gain_ampli,
            SORTIEPWM   =>   sortie_pwm,
            SHDAMPLI    =>   shd_ampli,
            
            ENTREEAUDIO1    =>  entree_audio1,
            ENTREEAUDIO1PRETE   =>  entree_audio1_prete,
            
            CLKPWM => clk_pwm,
            
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
