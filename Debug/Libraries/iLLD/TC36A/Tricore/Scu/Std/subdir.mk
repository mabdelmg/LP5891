################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuCcu.c \
../Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuEru.c \
../Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuLbist.c \
../Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuRcu.c \
../Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuWdt.c 

OBJS += \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuCcu.o \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuEru.o \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuLbist.o \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuRcu.o \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuWdt.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuCcu.src \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuEru.src \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuLbist.src \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuRcu.src \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuWdt.src 

C_DEPS += \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuCcu.d \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuEru.d \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuLbist.d \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuRcu.d \
./Libraries/iLLD/TC36A/Tricore/Scu/Std/IfxScuWdt.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC36A/Tricore/Scu/Std/%.src: ../Libraries/iLLD/TC36A/Tricore/Scu/Std/%.c Libraries/iLLD/TC36A/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc "-fC:/Users/mabdelmg/AURIX-v1.8.0-workspace/Blinky_LED_1_KIT_TC367_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O1 --tradeoff=4 --compact-max-size=20000000 -g -Ctc36x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC36A/Tricore/Scu/Std/%.o: ./Libraries/iLLD/TC36A/Tricore/Scu/Std/%.src Libraries/iLLD/TC36A/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '

