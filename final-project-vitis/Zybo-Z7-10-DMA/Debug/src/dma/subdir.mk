################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dma/dma.c 

OBJS += \
./src/dma/dma.o 

C_DEPS += \
./src/dma/dma.d 


# Each subdirectory must supply rules for building sources it contributes
src/dma/%.o: ../src/dma/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -ID:/Github/Zybo-Z7/sw/src/Zybo-Z7-10-DMA/src -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I/home/user/final-project/final-project-vitis/system_wrapper/export/system_wrapper/sw/system_wrapper/domain_ps7_cortexa9_0/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


