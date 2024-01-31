################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Infra.c \
../Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc0.c \
../Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc1.c 

OBJS += \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Infra.o \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc0.o \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc1.o 

COMPILED_SRCS += \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Infra.src \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc0.src \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc1.src 

C_DEPS += \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Infra.d \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc0.d \
./Libraries/Infra/Ssw/TC36A/Tricore/Ifx_Ssw_Tc1.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Infra/Ssw/TC36A/Tricore/%.src: ../Libraries/Infra/Ssw/TC36A/Tricore/%.c Libraries/Infra/Ssw/TC36A/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc36x "-fC:/Users/mabdelmg/AURIX-v1.8.0-workspace/Blinky_LED_1_KIT_TC367_TFT/Release/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O3 --tradeoff=0 --compact-max-size=200000 -g -Wc-w544 -Wc-w557 -Ctc36x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Infra/Ssw/TC36A/Tricore/%.o: ./Libraries/Infra/Ssw/TC36A/Tricore/%.src Libraries/Infra/Ssw/TC36A/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


