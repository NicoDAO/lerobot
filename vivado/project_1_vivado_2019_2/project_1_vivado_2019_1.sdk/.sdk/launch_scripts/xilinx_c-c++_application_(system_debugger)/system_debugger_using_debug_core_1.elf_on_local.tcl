connect -url tcp:127.0.0.1:3121
source /home/nicolas/vivado/FPGA_xilinx/projetZybo/Leds.sdk/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279A42A72A"} -index 0
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent Zybo 210279A42A72A" && level==0} -index 1
fpga -file /home/nicolas/vivado/FPGA_xilinx/projetZybo/Leds.sdk/design_1_wrapper_hw_platform_0/design_1_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279A42A72A"} -index 0
loadhw -hw /home/nicolas/vivado/FPGA_xilinx/projetZybo/Leds.sdk/design_1_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279A42A72A"} -index 0
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279A42A72A"} -index 0
dow /home/nicolas/vivado/FPGA_xilinx/projetZybo/Leds.sdk/core0/Debug/core0.elf
targets -set -nocase -filter {name =~ "ARM*#1" && jtag_cable_name =~ "Digilent Zybo 210279A42A72A"} -index 0
dow /home/nicolas/vivado/FPGA_xilinx/projetZybo/Leds.sdk/core_1/Debug/core_1.elf
configparams force-mem-access 0
bpadd -addr &main
