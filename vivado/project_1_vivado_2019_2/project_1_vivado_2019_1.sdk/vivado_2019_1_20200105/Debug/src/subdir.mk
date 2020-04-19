################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

CC_SRCS += \
../src/main.cc 

CPP_SRCS += \
../src/ConfigureFIRFPGA.cpp \
../src/ConfigureVolumes.cpp \
../src/GereLed.cpp \
../src/GereMoteur.cpp \
../src/GereMoteur_test.cpp \
../src/MonPWM.cpp \
../src/MonPWM_test.cpp \
../src/Tache.cpp \
../src/Testlibuart.cpp \
../src/TransfereAXI.cpp 

CC_DEPS += \
./src/main.d 

OBJS += \
./src/ConfigureFIRFPGA.o \
./src/ConfigureVolumes.o \
./src/GereLed.o \
./src/GereMoteur.o \
./src/GereMoteur_test.o \
./src/MonPWM.o \
./src/MonPWM_test.o \
./src/Tache.o \
./src/Testlibuart.o \
./src/TransfereAXI.o \
./src/main.o 

CPP_DEPS += \
./src/ConfigureFIRFPGA.d \
./src/ConfigureVolumes.d \
./src/GereLed.d \
./src/GereMoteur.d \
./src/GereMoteur_test.d \
./src/MonPWM.d \
./src/MonPWM_test.d \
./src/Tache.d \
./src/Testlibuart.d \
./src/TransfereAXI.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../vivado_2019_1_20200105_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../vivado_2019_1_20200105_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


