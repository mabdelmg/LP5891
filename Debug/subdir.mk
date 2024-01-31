################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Blinky_LED.c \
../CCU6_PWM_Generation.c \
../Cpu0_Main.c \
../Cpu1_Main.c \
../LP5891.c \
../SPI_CPU2.c 

OBJS += \
./Blinky_LED.o \
./CCU6_PWM_Generation.o \
./Cpu0_Main.o \
./Cpu1_Main.o \
./LP5891.o \
./SPI_CPU2.o 

COMPILED_SRCS += \
./Blinky_LED.src \
./CCU6_PWM_Generation.src \
./Cpu0_Main.src \
./Cpu1_Main.src \
./LP5891.src \
./SPI_CPU2.src 

C_DEPS += \
./Blinky_LED.d \
./CCU6_PWM_Generation.d \
./Cpu0_Main.d \
./Cpu1_Main.d \
./LP5891.d \
./SPI_CPU2.d 


# Each subdirectory must supply rules for building sources it contributes
%.src: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc "-fC:/Users/mabdelmg/AURIX-v1.8.0-workspace/Blinky_LED_1_KIT_TC367_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O1 --tradeoff=4 --compact-max-size=20000000 -g -Ctc36x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

%.o: ./%.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


