################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC36A/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Qspi/SpiSlave/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Ccu6/TimerWithTrigger/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Ccu6/Std/subdir.mk
-include Libraries/iLLD/TC36A/Tricore/Ccu6/PwmHl/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Service/CpuGeneric/If/subdir.mk
-include Libraries/Infra/Ssw/TC36A/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Blinky_LED_1_KIT_TC367_TFT
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
Blinky_LED_1_KIT_TC367_TFT.siz \


# All Target
all: main-build

# Main-build Target
main-build: Blinky_LED_1_KIT_TC367_TFT.elf secondary-outputs

# Tool invocations
Blinky_LED_1_KIT_TC367_TFT.elf: $(OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -lrt -lfp_fpu -lcs_fpu  -Wl-OC -Wl-OL -Wl-OT -Wl-Ox -Wl-Oy -Wl--map-file="Blinky_LED_1_KIT_TC367_TFT.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --exceptions --strict --anachronisms --force-c++ -Ctc36x   -o"Blinky_LED_1_KIT_TC367_TFT.elf" -Wl-o"Blinky_LED_1_KIT_TC367_TFT.hex:IHEX" --lsl-core=vtc  --lsl-file=../Lcf_Tasking_Tricore_Tc.lsl $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Blinky_LED_1_KIT_TC367_TFT.siz: Blinky_LED_1_KIT_TC367_TFT.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "Blinky_LED_1_KIT_TC367_TFT.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
