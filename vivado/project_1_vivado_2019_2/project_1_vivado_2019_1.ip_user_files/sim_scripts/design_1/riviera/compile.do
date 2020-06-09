vlib work
vlib riviera

vlib riviera/xilinx_vip
vlib riviera/xpm
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_vip_v1_1_7
vlib riviera/processing_system7_vip_v1_0_9
vlib riviera/xil_defaultlib
vlib riviera/lib_cdc_v1_0_2
vlib riviera/proc_sys_reset_v5_0_13
vlib riviera/generic_baseblocks_v2_1_0
vlib riviera/axi_register_slice_v2_1_21
vlib riviera/fifo_generator_v13_2_5
vlib riviera/axi_data_fifo_v2_1_20
vlib riviera/axi_crossbar_v2_1_22
vlib riviera/axi_protocol_converter_v2_1_21

vmap xilinx_vip riviera/xilinx_vip
vmap xpm riviera/xpm
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_7 riviera/axi_vip_v1_1_7
vmap processing_system7_vip_v1_0_9 riviera/processing_system7_vip_v1_0_9
vmap xil_defaultlib riviera/xil_defaultlib
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 riviera/proc_sys_reset_v5_0_13
vmap generic_baseblocks_v2_1_0 riviera/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_21 riviera/axi_register_slice_v2_1_21
vmap fifo_generator_v13_2_5 riviera/fifo_generator_v13_2_5
vmap axi_data_fifo_v2_1_20 riviera/axi_data_fifo_v2_1_20
vmap axi_crossbar_v2_1_22 riviera/axi_crossbar_v2_1_22
vmap axi_protocol_converter_v2_1_21 riviera/axi_protocol_converter_v2_1_21

vlog -work xilinx_vip  -sv2k12 "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -sv2k12 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"/opt/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/opt/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/opt/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"/opt/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_7  -sv2k12 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ce6c/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_9  -sv2k12 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_100M_0/sim/design_1_rst_ps7_0_100M_0.vhd" \
"../../../bd/design_1/ipshared/1611/entre_micro.vhd" \
"../../../bd/design_1/ip/design_1_PmodMIC3_0_1/sim/design_1_PmodMIC3_0_1.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_1/ipshared/d681/DAC16bits.v" \
"../../../bd/design_1/ip/design_1_interface_DAC8551_1_0/sim/design_1_interface_DAC8551_1_0.v" \
"../../../bd/design_1/ipshared/53a9/src/EchantilloneurRAM_2.v" \
"../../../bd/design_1/ipshared/53a9/src/FIRRAM_3.v" \
"../../../bd/design_1/ipshared/53a9/src/FIR_RAM_v1_0_S00_AXI.v" \
"../../../bd/design_1/ipshared/53a9/src/FIR_RAM_v1_0.v" \
"../../../bd/design_1/ip/design_1_FIR_0_0/sim/design_1_FIR_0_0.v" \
"../../../bd/design_1/ip/design_1_FIR_1_0/sim/design_1_FIR_1_0.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ipshared/b6d0/hdl/melangeur_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_melangeur_0_1/sim/design_1_melangeur_0_1.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_FIR_0_1/sim/design_1_FIR_0_1.v" \
"../../../bd/design_1/ip/design_1_FIR_0_2/sim/design_1_FIR_0_2.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ipshared/gain.vhd" \
"../../../bd/design_1/ipshared/d569/hdl/gainNvoies_v1_0_S00_AXI.vhd" \
"../../../bd/design_1/ipshared/d569/hdl/gainNvoies_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_gainNvoies_0_0/sim/design_1_gainNvoies_0_0.vhd" \
"../../../bd/design_1/ipshared/a183/audio_pwm.vhd" \
"../../../bd/design_1/ipshared/a183/hdl/pmod_audio_v1_0_S00_AXI.vhd" \
"../../../bd/design_1/ipshared/a183/hdl/pmod_audio_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_pmod_audio_0_0/sim/design_1_pmod_audio_0_0.vhd" \
"../../../bd/design_1/ip/design_1_pmod_audio_0_1/sim/design_1_pmod_audio_0_1.vhd" \
"../../../bd/design_1/ipshared/f2ec/hdl/piloteHC-SR04.vhd" \
"../../../bd/design_1/ipshared/f2ec/hdl/capteurDistanceUltrason_v1_0_S00_AXI.vhd" \
"../../../bd/design_1/ipshared/f2ec/hdl/capteurDistanceUltrason_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_GyrocsopeSPI_0_0/sim/design_1_GyrocsopeSPI_0_0.vhd" \
"../../../bd/design_1/ipshared/265b/hdl/diviseur_horloge.vhd" \
"../../../bd/design_1/ipshared/265b/src/interface_spi_materielle.vhd" \
"../../../bd/design_1/ipshared/265b/src/interface_spi_commande.vhd" \
"../../../bd/design_1/ipshared/265b/hdl/mongyrocopse_v1_0_S00_AXI.vhd" \
"../../../bd/design_1/ipshared/265b/hdl/mongyrocopse_v1_0.vhd" \
"../../../bd/design_1/ip/design_1_mongyrocopse_0_0/sim/design_1_mongyrocopse_0_0.vhd" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_21  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/2ef9/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5 -93 \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_20  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/47c9/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_22  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/b68e/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \

vlog -work axi_protocol_converter_v2_1_21  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/8dfa/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../project_1_vivado_2019_1.srcs/sources_1/bd/design_1/ipshared/6b56/hdl" "+incdir+/opt/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_pc_9/sim/design_1_auto_pc_9.v" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
"../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
"../../../bd/design_1/ip/design_1_auto_pc_2/sim/design_1_auto_pc_2.v" \
"../../../bd/design_1/ip/design_1_auto_pc_3/sim/design_1_auto_pc_3.v" \
"../../../bd/design_1/ip/design_1_auto_pc_4/sim/design_1_auto_pc_4.v" \
"../../../bd/design_1/ip/design_1_auto_pc_5/sim/design_1_auto_pc_5.v" \
"../../../bd/design_1/ip/design_1_auto_pc_6/sim/design_1_auto_pc_6.v" \
"../../../bd/design_1/ip/design_1_auto_pc_7/sim/design_1_auto_pc_7.v" \
"../../../bd/design_1/ip/design_1_auto_pc_8/sim/design_1_auto_pc_8.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/sim/design_1.vhd" \

vlog -work xil_defaultlib \
"glbl.v"

