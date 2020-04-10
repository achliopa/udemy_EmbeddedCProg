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
002Sizeof.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
002Sizeof.list \

OBJCOPY_BIN += \
002Sizeof.bin \


# All Target
all: 002Sizeof.elf secondary-outputs

# Tool invocations
002Sizeof.elf: $(OBJS) $(USER_OBJS) C:\Users\achliopa\workspace\udemy\embedded_c\myCode\target\002Sizeof\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "002Sizeof.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\achliopa\workspace\udemy\embedded_c\myCode\target\002Sizeof\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="002Sizeof.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

002Sizeof.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "002Sizeof.list"
	@echo 'Finished building: $@'
	@echo ' '

002Sizeof.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "002Sizeof.bin"
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
