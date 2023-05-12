################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/ComM/gen/ComM_BSW_Cfg.c \
../Autosar/ComM/gen/ComM_Lcfg.c \
../Autosar/ComM/gen/ComM_MainFunction.c \
../Autosar/ComM/gen/ComM_PBcfg.c \
../Autosar/ComM/gen/ComM_Rte_Cfg.c 

COMPILED_SRCS += \
./Autosar/ComM/gen/ComM_BSW_Cfg.src \
./Autosar/ComM/gen/ComM_Lcfg.src \
./Autosar/ComM/gen/ComM_MainFunction.src \
./Autosar/ComM/gen/ComM_PBcfg.src \
./Autosar/ComM/gen/ComM_Rte_Cfg.src 

C_DEPS += \
./Autosar/ComM/gen/ComM_BSW_Cfg.d \
./Autosar/ComM/gen/ComM_Lcfg.d \
./Autosar/ComM/gen/ComM_MainFunction.d \
./Autosar/ComM/gen/ComM_PBcfg.d \
./Autosar/ComM/gen/ComM_Rte_Cfg.d 

OBJS += \
./Autosar/ComM/gen/ComM_BSW_Cfg.o \
./Autosar/ComM/gen/ComM_Lcfg.o \
./Autosar/ComM/gen/ComM_MainFunction.o \
./Autosar/ComM/gen/ComM_PBcfg.o \
./Autosar/ComM/gen/ComM_Rte_Cfg.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/ComM/gen/%.src: ../Autosar/ComM/gen/%.c Autosar/ComM/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/ComM\/gen\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/ComM/gen/%.o: ./Autosar/ComM/gen/%.src Autosar/ComM/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-ComM-2f-gen

clean-Autosar-2f-ComM-2f-gen:
	-$(RM) ./Autosar/ComM/gen/ComM_BSW_Cfg.d ./Autosar/ComM/gen/ComM_BSW_Cfg.o ./Autosar/ComM/gen/ComM_BSW_Cfg.src ./Autosar/ComM/gen/ComM_Lcfg.d ./Autosar/ComM/gen/ComM_Lcfg.o ./Autosar/ComM/gen/ComM_Lcfg.src ./Autosar/ComM/gen/ComM_MainFunction.d ./Autosar/ComM/gen/ComM_MainFunction.o ./Autosar/ComM/gen/ComM_MainFunction.src ./Autosar/ComM/gen/ComM_PBcfg.d ./Autosar/ComM/gen/ComM_PBcfg.o ./Autosar/ComM/gen/ComM_PBcfg.src ./Autosar/ComM/gen/ComM_Rte_Cfg.d ./Autosar/ComM/gen/ComM_Rte_Cfg.o ./Autosar/ComM/gen/ComM_Rte_Cfg.src

.PHONY: clean-Autosar-2f-ComM-2f-gen

