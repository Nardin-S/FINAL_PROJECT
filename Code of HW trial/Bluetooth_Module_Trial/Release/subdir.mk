################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Buzzer.c \
../DCMotor.c \
../DIO.c \
../LCD.c \
../LED.c \
../PWM0.c \
../Temp_Sensor.c \
../UART.c \
../bluetooth.c \
../main.c 

OBJS += \
./ADC.o \
./Buzzer.o \
./DCMotor.o \
./DIO.o \
./LCD.o \
./LED.o \
./PWM0.o \
./Temp_Sensor.o \
./UART.o \
./bluetooth.o \
./main.o 

C_DEPS += \
./ADC.d \
./Buzzer.d \
./DCMotor.d \
./DIO.d \
./LCD.d \
./LED.d \
./PWM0.d \
./Temp_Sensor.d \
./UART.d \
./bluetooth.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


