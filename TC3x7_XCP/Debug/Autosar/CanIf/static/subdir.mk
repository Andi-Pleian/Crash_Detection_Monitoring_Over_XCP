################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/CanIf/static/CanIf.c 

COMPILED_SRCS += \
./Autosar/CanIf/static/CanIf.src 

C_DEPS += \
./Autosar/CanIf/static/CanIf.d 

OBJS += \
./Autosar/CanIf/static/CanIf.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/CanIf/static/%.src: ../Autosar/CanIf/static/%.c Autosar/CanIf/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/CanIf\/static\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/CanIf/static/%.o: ./Autosar/CanIf/static/%.src Autosar/CanIf/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-CanIf-2f-static

clean-Autosar-2f-CanIf-2f-static:
	-$(RM) ./Autosar/CanIf/static/CanIf.d ./Autosar/CanIf/static/CanIf.o ./Autosar/CanIf/static/CanIf.src

.PHONY: clean-Autosar-2f-CanIf-2f-static
