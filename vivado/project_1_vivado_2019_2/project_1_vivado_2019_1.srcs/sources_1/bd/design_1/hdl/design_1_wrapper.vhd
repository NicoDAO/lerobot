--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.2.1 (lin64) Build 2729669 Thu Dec  5 04:48:12 MST 2019
--Date        : Tue Mar 31 23:21:28 2020
--Host        : grosportable running 64-bit Ubuntu 18.04.4 LTS
--Command     : generate_target design_1_wrapper.bd
--Design      : design_1_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_wrapper is
  port (
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_cas_n : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    DIR_MOTEUR1 : out STD_LOGIC;
    DIR_MOTEUR2 : out STD_LOGIC;
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    LDAC_0 : out STD_LOGIC;
    LedC : out STD_LOGIC_VECTOR ( 3 downto 0 );
    cs_mic_0 : out STD_LOGIC;
    entree_echo_0 : in STD_LOGIC;
    gain_ampli_0 : out STD_LOGIC;
    gpio_io_i_0 : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_pwm : out STD_LOGIC_VECTOR ( 0 to 0 );
    sck_mic_0 : out STD_LOGIC;
    sdi_mic_0 : in STD_LOGIC;
    shd_ampli_0 : out STD_LOGIC;
    sortie_pwm_0 : out STD_LOGIC;
    sortie_pwm_1 : out STD_LOGIC;
    sortie_trig_0 : out STD_LOGIC
  );
end design_1_wrapper;

architecture STRUCTURE of design_1_wrapper is
  component design_1 is
  port (
    LedC : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gain_ampli_0 : out STD_LOGIC;
    sortie_pwm_0 : out STD_LOGIC;
    shd_ampli_0 : out STD_LOGIC;
    sck_mic_0 : out STD_LOGIC;
    cs_mic_0 : out STD_LOGIC;
    sdi_mic_0 : in STD_LOGIC;
    LDAC_0 : out STD_LOGIC;
    gpio_io_i_0 : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_pwm : out STD_LOGIC_VECTOR ( 0 to 0 );
    sortie_pwm_1 : out STD_LOGIC;
    DIR_MOTEUR1 : out STD_LOGIC;
    DIR_MOTEUR2 : out STD_LOGIC;
    entree_echo_0 : in STD_LOGIC;
    sortie_trig_0 : out STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    DDR_cas_n : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 )
  );
  end component design_1;
begin
design_1_i: component design_1
     port map (
      DDR_addr(14 downto 0) => DDR_addr(14 downto 0),
      DDR_ba(2 downto 0) => DDR_ba(2 downto 0),
      DDR_cas_n => DDR_cas_n,
      DDR_ck_n => DDR_ck_n,
      DDR_ck_p => DDR_ck_p,
      DDR_cke => DDR_cke,
      DDR_cs_n => DDR_cs_n,
      DDR_dm(3 downto 0) => DDR_dm(3 downto 0),
      DDR_dq(31 downto 0) => DDR_dq(31 downto 0),
      DDR_dqs_n(3 downto 0) => DDR_dqs_n(3 downto 0),
      DDR_dqs_p(3 downto 0) => DDR_dqs_p(3 downto 0),
      DDR_odt => DDR_odt,
      DDR_ras_n => DDR_ras_n,
      DDR_reset_n => DDR_reset_n,
      DDR_we_n => DDR_we_n,
      DIR_MOTEUR1 => DIR_MOTEUR1,
      DIR_MOTEUR2 => DIR_MOTEUR2,
      FIXED_IO_ddr_vrn => FIXED_IO_ddr_vrn,
      FIXED_IO_ddr_vrp => FIXED_IO_ddr_vrp,
      FIXED_IO_mio(53 downto 0) => FIXED_IO_mio(53 downto 0),
      FIXED_IO_ps_clk => FIXED_IO_ps_clk,
      FIXED_IO_ps_porb => FIXED_IO_ps_porb,
      FIXED_IO_ps_srstb => FIXED_IO_ps_srstb,
      LDAC_0 => LDAC_0,
      LedC(3 downto 0) => LedC(3 downto 0),
      cs_mic_0 => cs_mic_0,
      entree_echo_0 => entree_echo_0,
      gain_ampli_0 => gain_ampli_0,
      gpio_io_i_0(3 downto 0) => gpio_io_i_0(3 downto 0),
      s_pwm(0) => s_pwm(0),
      sck_mic_0 => sck_mic_0,
      sdi_mic_0 => sdi_mic_0,
      shd_ampli_0 => shd_ampli_0,
      sortie_pwm_0 => sortie_pwm_0,
      sortie_pwm_1 => sortie_pwm_1,
      sortie_trig_0 => sortie_trig_0
    );
end STRUCTURE;
