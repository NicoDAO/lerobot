
set_property PACKAGE_PIN M14 [get_ports LedC[0]]
set_property PACKAGE_PIN M15 [get_ports LedC[1]]
set_property PACKAGE_PIN G14 [get_ports LedC[2]]
set_property PACKAGE_PIN D18 [get_ports LedC[3]]

set_property IOSTANDARD LVCMOS33 [get_ports LedC[0]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[1]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[2]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[3]]

JA
#JA1 P broche1
 set_property PACKAGE_PIN N15 [get_ports sortie_pwm_0]
set_property IOSTANDARD LVCMOS33 [get_ports sortie_pwm_0]
#JA2_P broche2
set_property PACKAGE_PIN L14 [get_ports gain_ampli_0]
set_property IOSTANDARD LVCMOS33 [get_ports gain_ampli_0]
#JA3_P broche3 K16
set_property PACKAGE_PIN K16 [get_ports LDAC_0]
set_property IOSTANDARD LVCMOS33 [get_ports shd_ampli_0]
#JA4_P broche4
set_property PACKAGE_PIN K14 [get_ports shd_ampli_0]
set_property IOSTANDARD LVCMOS33 [get_ports LDAC_0]


#JB
#JB1
#set_property PACKAGE_PIN T20 [get_ports cs_mic_0]
#set_property IOSTANDARD LVCMOS33 [get_ports cs_mic_0]
##JB3
#set_property PACKAGE_PIN V20 [get_ports sdi_mic_0]
#set_property IOSTANDARD LVCMOS33 [get_ports sdi_mic_0]
##JB4
#set_property PACKAGE_PIN W20 [get_ports sck_mic_0]
#set_property IOSTANDARD LVCMOS33 [get_ports sck_mic_0]

#micro PMOD MIC3
#JD1
set_property PACKAGE_PIN T14 [get_ports cs_mic_0]
set_property IOSTANDARD LVCMOS33 [get_ports cs_mic_0]
#JD3
set_property PACKAGE_PIN P14 [get_ports sdi_mic_0]
set_property IOSTANDARD LVCMOS33 [get_ports sdi_mic_0]
#JD4
set_property PACKAGE_PIN V17 [get_ports sck_mic_0]
set_property IOSTANDARD LVCMOS33 [get_ports sck_mic_0]




#debug
#set_property IOSTANDARD LVCMOS33 [get_ports sortie_debug1]
#set_property PACKAGE_PIN V15 [get_ports sortie_debug1]
#set_property PACKAGE_PIN E8 [get_ports sortie_debug1]
#set_property IOSTANDARD LVCMOS33 [get_ports sortie_debug2]
#set_property PACKAGE_PIN W15 [get_ports sortie_debug2]


set_property IOSTANDARD LVCMOS33 [get_ports gpio_io_i_0[0]]
set_property PACKAGE_PIN G15 [get_ports  gpio_io_i_0[0]]

set_property IOSTANDARD LVCMOS33 [get_ports  gpio_io_i_0[1]]
set_property PACKAGE_PIN P15 [get_ports  gpio_io_i_0[1]]

set_property IOSTANDARD LVCMOS33 [get_ports  gpio_io_i_0[2]]
set_property PACKAGE_PIN W13 [get_ports  gpio_io_i_0[2]]

set_property IOSTANDARD LVCMOS33 [get_ports  gpio_io_i_0[3]]
set_property PACKAGE_PIN T16 [get_ports  gpio_io_i_0[3]]


#moteur1
set_property IOSTANDARD LVCMOS33 [get_ports  s_pwm]
set_property PACKAGE_PIN V12 [get_ports  s_pwm]

set_property IOSTANDARD LVCMOS33 [get_ports  DIR_MOTEUR1]
set_property PACKAGE_PIN W16 [get_ports  DIR_MOTEUR1]

#moteur2
set_property IOSTANDARD LVCMOS33 [get_ports  sortie_pwm_1]
set_property PACKAGE_PIN V13 [get_ports  sortie_pwm_1]

set_property IOSTANDARD LVCMOS33 [get_ports  DIR_MOTEUR2]
set_property PACKAGE_PIN U17 [get_ports  DIR_MOTEUR2]


#capteur distance
#JF1
set_property IOSTANDARD LVCMOS33 [get_ports  sortie_trig_0]
#set_property PACKAGE_PIN E8 [get_ports  sortie_trig_0]
set_property PACKAGE_PIN V15 [get_ports  sortie_trig_0]


#JF3
set_property IOSTANDARD LVCMOS33 [get_ports  entree_echo_0]
#set_property PACKAGE_PIN C6 [get_ports  entree_echo_0]
set_property PACKAGE_PIN T11 [get_ports  entree_echo_0]


#accelerometre
#JF1
#set_property IOSTANDARD LVCMOS33 [get_ports  cs_gyro_pmod_0]
#set_property PACKAGE_PIN E8 [get_ports  cs_gyro_pmod_0]
##JF2
#set_property IOSTANDARD LVCMOS33 [get_ports  sdi_gyro_pmod_0]
#set_property PACKAGE_PIN E9 [get_ports  sdi_gyro_pmod_0]
# #JF3
# set_property IOSTANDARD LVCMOS33 [get_ports  sdo_gyro_pmod_0]
#set_property PACKAGE_PIN C6 [get_ports  sdo_gyro_pmod_0]
##JF4
#set_property IOSTANDARD LVCMOS33 [get_ports  clk_gyr_pmod_0]
#set_property PACKAGE_PIN D9 [get_ports  clk_gyr_pmod_0]
##JF7
#set_property IOSTANDARD LVCMOS33 [get_ports  int1_gyro_pmod_0]
#set_property PACKAGE_PIN E6 [get_ports  int1_gyro_pmod_0]
##JF8   
#set_property IOSTANDARD LVCMOS33 [get_ports  int2_gyro_pmod_0]
#set_property PACKAGE_PIN B5 [get_ports  int2_gyro_pmod_0]

#accelerometre
#JD1P 1
#set_property IOSTANDARD LVCMOS33 [get_ports  cs_gyro_pmod_0]
#set_property PACKAGE_PIN T14 [get_ports  cs_gyro_pmod_0]
##JD1N 2
#set_property IOSTANDARD LVCMOS33 [get_ports  sdi_gyro_pmod_0]
#set_property PACKAGE_PIN P14 [get_ports  sdi_gyro_pmod_0]
# #JD2P 3
# set_property IOSTANDARD LVCMOS33 [get_ports  sdo_gyro_pmod_0]
#set_property PACKAGE_PIN U14 [get_ports  sdo_gyro_pmod_0]
##JD2N 4
#set_property IOSTANDARD LVCMOS33 [get_ports  clk_gyr_pmod_0]
#set_property PACKAGE_PIN V17 [get_ports  clk_gyr_pmod_0]
##JD3P 7
#set_property IOSTANDARD LVCMOS33 [get_ports  int1_gyro_pmod_0]
#set_property PACKAGE_PIN E6 [get_ports  int1_gyro_pmod_0]
##JD3N 8
#set_property IOSTANDARD LVCMOS33 [get_ports  int2_gyro_pmod_0]
#set_property PACKAGE_PIN B5 [get_ports  int2_gyro_pmod_0]

#pmod GYRO
#JB1N 1
set_property IOSTANDARD LVCMOS33 [get_ports  cs_gyro_pmod_0]
set_property PACKAGE_PIN T20 [get_ports  cs_gyro_pmod_0]
#JB1N 2
set_property IOSTANDARD LVCMOS33 [get_ports  sdi_gyro_pmod_0]
set_property PACKAGE_PIN P1 U20 [get_ports  sdi_gyro_pmod_0]
 #JD2P 3
 set_property IOSTANDARD LVCMOS33 [get_ports  sdo_gyro_pmod_0]
set_property PACKAGE_PIN V20 [get_ports  sdo_gyro_pmod_0]
#JD2N 4
set_property IOSTANDARD LVCMOS33 [get_ports  clk_gyr_pmod_0]
set_property PACKAGE_PIN W20 [get_ports  clk_gyr_pmod_0]
#JD3P 7
set_property IOSTANDARD LVCMOS33 [get_ports  int1_gyro_pmod_0]
set_property PACKAGE_PIN Y18 [get_ports  int1_gyro_pmod_0]
#JD3N 8
set_property IOSTANDARD LVCMOS33 [get_ports  int2_gyro_pmod_0]
set_property PACKAGE_PIN Y19 [get_ports  int2_gyro_pmod_0]



