################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Button.c \
../Buzzer.c \
../CHOOSE_APP.c \
../DIO.c \
../Keypad.c \
../LCD.c \
../LED.c \
../Password.c \
../SPI.c \
../UART.c \
../bluetooth.c \
../main.c 

OBJS += \
./Button.o \
./Buzzer.o \
./CHOOSE_APP.o \
./DIO.o \
./Keypad.o \
./LCD.o \
./LED.o \
./Password.o \
./SPI.o \
./UART.o \
./bluetooth.o \
./main.o 

C_DEPS += \
./Button.d \
./Buzzer.d \
./CHOOSE_APP.d \
./DIO.d \
./Keypad.d \
./LCD.d \
./LED.d \
./Password.d \
./SPI.d \
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


