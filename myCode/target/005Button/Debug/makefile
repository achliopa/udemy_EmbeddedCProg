################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
005Button.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
005Button.list \

OBJCOPY_BIN += \
005Button.bin \


# All Target
all: 005Button.elf secondary-outputs

# Tool invocations
005Button.elf: $(OBJS) $(USER_OBJS) C:\Users\achliopa\workspace\udemy\embedded_c\myCode\target\005Button\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "005Button.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\achliopa\workspace\udemy\embedded_c\myCode\target\005Button\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="005Button.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

005Button.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "005Button.list"
	@echo 'Finished building: $@'
	@echo ' '

005Button.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "005Button.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
