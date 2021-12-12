################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/audio/audio.c 

OBJS += \
./src/audio/audio.o 

C_DEPS += \
./src/audio/audio.d 


# Each subdirectory must supply rules for building sources it contributes
src/audio/%.o: ../src/audio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -ID:/Github/Zybo-Z7/sw/src/Zybo-Z7-10-DMA/src -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -IC:/College/senior/fall/embedded-systems-2/final-project/final-project-vitis/Zybo-Z7-10-DMA/Debug/_sdk/bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


