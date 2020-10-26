# lerobot

#project to run a robot with ultrasound sensor, 3 D gyrocsope and 2 DC electrical motors.
Project is running on Zybo card from digilent, with Pmod extensions.
The core of the system is a Zynq 7000 from xilinx.
I use Yocto to generate the linux minimal core, with gcc, gdb and ssh.
The bitstream of the FPGA part is used to drive the 2 DC motor, the ultrasound sensorand the gyroscope sensor.
Software is running inside the Robot on ARM CortexA9.
2 apps are running on the taget.
1 : apps Robot, goal is to run the robot with the differents informations from differents sensors, and drive the DC motors.Peripherals are drived by the HW part (VHDL), Software part is running with one thread for one peripheral. Thread communictions uses IPC SystemV librairies
2 : app Telecommande, is the interface to remote the robot from IP network with ssh protocol.


