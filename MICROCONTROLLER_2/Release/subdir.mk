################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Buzzer.c \
../CHOOSE_APP_RX.c \
../DCMotor.c \
../DIO.c \
../Keypad.c \
../LCD.c \
../LED.c \
../PWM0.c \
../SPI.c \
../Temp_Sensor.c \
../main.c 

OBJS += \
./ADC.o \
./Buzzer.o \
./CHOOSE_APP_RX.o \
./DCMotor.o \
./DIO.o \
./Keypad.o \
./LCD.o \
./LED.o \
./PWM0.o \
./SPI.o \
./Temp_Sensor.o \
./main.o 

C_DEPS += \
./ADC.d \
./Buzzer.d \
./CHOOSE_APP_RX.d \
./DCMotor.d \
./DIO.d \
./Keypad.d \
./LCD.d \
./LED.d \
./PWM0.d \
./SPI.d \
./Temp_Sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


