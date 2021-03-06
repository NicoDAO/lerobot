#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2018.3 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Sat Apr 13 22:42:55 CEST 2019
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
#
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
ExecStep()
{
"$@"
RETVAL=$?
if [ $RETVAL -ne 0 ]
then
exit $RETVAL
fi
}
ExecStep xsim stimulus_func_synth -key {Post-Synthesis:sim_3:Functional:stimulus} -tclbatch stimulus.tcl -protoinst "protoinst_files/design_1.protoinst" -view /home/nicolas/vivado/vivado/FPGA_xilinx/projetZybo/stimulus_behav2.wcfg -log simulate.log
