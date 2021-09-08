################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Button/Button_driver.c 

OBJS += \
./ECUAL/Button/Button_driver.o 

C_DEPS += \
./ECUAL/Button/Button_driver.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Button/%.o: ../ECUAL/Button/%.c ECUAL/Button/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


