
set_property PACKAGE_PIN M14 [get_ports LedC[0]]
set_property PACKAGE_PIN M15 [get_ports LedC[1]]
set_property PACKAGE_PIN G14 [get_ports LedC[2]]
set_property PACKAGE_PIN D18 [get_ports LedC[3]]

set_property IOSTANDARD LVCMOS33 [get_ports LedC[0]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[1]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[2]]
set_property IOSTANDARD LVCMOS33 [get_ports LedC[3]]

#JA
set_property PACKAGE_PIN N15 [get_ports sortie_pwm_0]
set_property PACKAGE_PIN L14 [get_ports gain_ampli_0]
set_property PACKAGE_PIN K14 [get_ports shd_ampli_0]

set_property IOSTANDARD LVCMOS33 [get_ports sortie_pwm_0]
set_property IOSTANDARD LVCMOS33 [get_ports gain_ampli_0]
set_property IOSTANDARD LVCMOS33 [get_ports shd_ampli_0]

set_property IOSTANDARD LVCMOS33 [get_ports LDAC_0]
set_property PACKAGE_PIN K16 [get_ports LDAC_0]
#JB
set_property PACKAGE_PIN T20 [get_ports cs_mic_0]
set_property IOSTANDARD LVCMOS33 [get_ports cs_mic_0]
set_property PACKAGE_PIN V20 [get_ports sdi_mic_0]
set_property IOSTANDARD LVCMOS33 [get_ports sdi_mic_0]
set_property PACKAGE_PIN W20 [get_ports sck_mic_0]
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

#set_property MARK_DEBUG true [get_nets design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/s00_nouvel_echantillon]
#set_property MARK_DEBUG true [get_nets design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/s00_traitement_fini]
#set_property MARK_DEBUG true [get_nets design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/filtre/s00_axi_aresetn]
#connect_debug_port u_ila_0/clk [get_nets [list design_1_i/processing_system7_0/inst/FCLK_CLK0]]
#connect_debug_port u_ila_0/probe0 [get_nets [list design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/filtre/s00_axi_aresetn]]
#connect_debug_port u_ila_0/probe1 [get_nets [list design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/s00_nouvel_echantillon]]
#connect_debug_port u_ila_1/clk [get_nets [list design_1_i/processing_system7_0/inst/FCLK_CLK1]]
#connect_debug_port u_ila_1/probe0 [get_nets [list design_1_i/FIR_RAM_0/inst/FIR_RAM_v1_0_S00_AXI_inst/s00_traitement_fini]]
#connect_debug_port dbg_hub/clk [get_nets u_ila_1_FCLK_CLK1]


#connect_debug_port u_ila_0/probe6 [get_nets [list {design_1_i/FIR_0/inst/FIR_RAM_v1_0_S00_AXI_inst/filtre/raddrRAM_Coef[5]_i_2_n_0}]]

