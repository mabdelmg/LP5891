################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC36A/Tricore/Geth/Std/IfxGeth.c 

OBJS += \
./Libraries/iLLD/TC36A/Tricore/Geth/Std/IfxGeth.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC36A/Tricore/Geth/Std/IfxGeth.src 

C_DEPS += \
./Libraries/iLLD/TC36A/Tricore/Geth/Std/IfxGeth.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC36A/Tricore/Geth/Std/%.src: ../Libraries/iLLD/TC36A/Tricore/Geth/Std/%.c Libraries/iLLD/TC36A/Tricore/Geth/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc36x "-fC:/Users/mabdelmg/AURIX-v1.8.0-workspace/Blinky_LED_1_KIT_TC367_TFT/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC36A/Tricore/Geth/Std/%.o: ./Libraries/iLLD/TC36A/Tricore/Geth/Std/%.src Libraries/iLLD/TC36A/Tricore/Geth/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


