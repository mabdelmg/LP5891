################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsEvr.c \
../Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsPm.c 

OBJS += \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsEvr.o \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsPm.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsEvr.src \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsPm.src 

C_DEPS += \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsEvr.d \
./Libraries/iLLD/TC36A/Tricore/Pms/Std/IfxPmsPm.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC36A/Tricore/Pms/Std/%.src: ../Libraries/iLLD/TC36A/Tricore/Pms/Std/%.c Libraries/iLLD/TC36A/Tricore/Pms/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc "-fC:/Users/mabdelmg/AURIX-v1.8.0-workspace/Blinky_LED_1_KIT_TC367_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O1 --tradeoff=4 --compact-max-size=20000000 -g -Ctc36x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC36A/Tricore/Pms/Std/%.o: ./Libraries/iLLD/TC36A/Tricore/Pms/Std/%.src Libraries/iLLD/TC36A/Tricore/Pms/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


