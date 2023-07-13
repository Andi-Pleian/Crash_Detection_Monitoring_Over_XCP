################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/BswM/gen/BswM_Cfg.c \
../Autosar/BswM/gen/BswM_Lcfg.c \
../Autosar/BswM/gen/BswM_PBcfg.c 

COMPILED_SRCS += \
./Autosar/BswM/gen/BswM_Cfg.src \
./Autosar/BswM/gen/BswM_Lcfg.src \
./Autosar/BswM/gen/BswM_PBcfg.src 

C_DEPS += \
./Autosar/BswM/gen/BswM_Cfg.d \
./Autosar/BswM/gen/BswM_Lcfg.d \
./Autosar/BswM/gen/BswM_PBcfg.d 

OBJS += \
./Autosar/BswM/gen/BswM_Cfg.o \
./Autosar/BswM/gen/BswM_Lcfg.o \
./Autosar/BswM/gen/BswM_PBcfg.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/BswM/gen/%.src: ../Autosar/BswM/gen/%.c Autosar/BswM/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC387_XCP_ACC_MEAS/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/BswM\/gen\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/BswM/gen/%.o: ./Autosar/BswM/gen/%.src Autosar/BswM/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-BswM-2f-gen

clean-Autosar-2f-BswM-2f-gen:
	-$(RM) ./Autosar/BswM/gen/BswM_Cfg.d ./Autosar/BswM/gen/BswM_Cfg.o ./Autosar/BswM/gen/BswM_Cfg.src ./Autosar/BswM/gen/BswM_Lcfg.d ./Autosar/BswM/gen/BswM_Lcfg.o ./Autosar/BswM/gen/BswM_Lcfg.src ./Autosar/BswM/gen/BswM_PBcfg.d ./Autosar/BswM/gen/BswM_PBcfg.o ./Autosar/BswM/gen/BswM_PBcfg.src

.PHONY: clean-Autosar-2f-BswM-2f-gen

