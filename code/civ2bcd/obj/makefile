################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
civ2bcd.hex \

SECONDARY_LIST += \
civ2bcd.lst \

SECONDARY_SIZE += \
civ2bcd.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: civ2bcd.elf secondary-outputs

# Tool invocations
civ2bcd.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -T "/home/ra0sms/stm32/RiskV/civ2bcd/code/civ2bcd/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -Xlinker --print-memory-usage -Wl,-Map,"civ2bcd.map" --specs=nano.specs --specs=nosys.specs -o "civ2bcd.elf" $(OBJS)  $(LIBS) -lprintf
civ2bcd.hex: civ2bcd.elf
	@	riscv-none-embed-objcopy -O ihex "civ2bcd.elf" "civ2bcd.hex"
civ2bcd.lst: civ2bcd.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "civ2bcd.elf" > "civ2bcd.lst"
civ2bcd.siz: civ2bcd.elf
	riscv-none-embed-size --format=berkeley "civ2bcd.elf"

# Other Targets
clean:
	-$(RM) $(OBJS) $(EXPANDS) $(CALLGRAPH_DOT) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) civ2bcd.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets