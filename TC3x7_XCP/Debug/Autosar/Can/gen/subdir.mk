################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Can/gen/Can_17_McmCan_PBCfg.c 

COMPILED_SRCS += \
./Autosar/Can/gen/Can_17_McmCan_PBCfg.src 

C_DEPS += \
./Autosar/Can/gen/Can_17_McmCan_PBCfg.d 

OBJS += \
./Autosar/Can/gen/Can_17_McmCan_PBCfg.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Can/gen/%.src: ../Autosar/Can/gen/%.c Autosar/Can/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/Can\/gen\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/Can/gen/%.o: ./Autosar/Can/gen/%.src Autosar/Can/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-Can-2f-gen

clean-Autosar-2f-Can-2f-gen:
	-$(RM) ./Autosar/Can/gen/Can_17_McmCan_PBCfg.d ./Autosar/Can/gen/Can_17_McmCan_PBCfg.o ./Autosar/Can/gen/Can_17_McmCan_PBCfg.src

.PHONY: clean-Autosar-2f-Can-2f-gen

