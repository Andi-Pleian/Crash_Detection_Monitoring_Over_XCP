################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EB_Stubs/CanIf_Cfg.c \
../EB_Stubs/CanIf_Lcfg.c \
../EB_Stubs/CanIf_MultiMF.c \
../EB_Stubs/CanIf_PBCfg.c \
../EB_Stubs/CanSM_Cfg.c \
../EB_Stubs/Can_17_McmCan_PBCfg.c \
../EB_Stubs/ComM_BSW_Cfg.c \
../EB_Stubs/ComM_Lcfg.c \
../EB_Stubs/ComM_MainFunction.c \
../EB_Stubs/ComM_Rte_Cfg.c 

COMPILED_SRCS += \
./EB_Stubs/CanIf_Cfg.src \
./EB_Stubs/CanIf_Lcfg.src \
./EB_Stubs/CanIf_MultiMF.src \
./EB_Stubs/CanIf_PBCfg.src \
./EB_Stubs/CanSM_Cfg.src \
./EB_Stubs/Can_17_McmCan_PBCfg.src \
./EB_Stubs/ComM_BSW_Cfg.src \
./EB_Stubs/ComM_Lcfg.src \
./EB_Stubs/ComM_MainFunction.src \
./EB_Stubs/ComM_Rte_Cfg.src 

C_DEPS += \
./EB_Stubs/CanIf_Cfg.d \
./EB_Stubs/CanIf_Lcfg.d \
./EB_Stubs/CanIf_MultiMF.d \
./EB_Stubs/CanIf_PBCfg.d \
./EB_Stubs/CanSM_Cfg.d \
./EB_Stubs/Can_17_McmCan_PBCfg.d \
./EB_Stubs/ComM_BSW_Cfg.d \
./EB_Stubs/ComM_Lcfg.d \
./EB_Stubs/ComM_MainFunction.d \
./EB_Stubs/ComM_Rte_Cfg.d 

OBJS += \
./EB_Stubs/CanIf_Cfg.o \
./EB_Stubs/CanIf_Lcfg.o \
./EB_Stubs/CanIf_MultiMF.o \
./EB_Stubs/CanIf_PBCfg.o \
./EB_Stubs/CanSM_Cfg.o \
./EB_Stubs/Can_17_McmCan_PBCfg.o \
./EB_Stubs/ComM_BSW_Cfg.o \
./EB_Stubs/ComM_Lcfg.o \
./EB_Stubs/ComM_MainFunction.o \
./EB_Stubs/ComM_Rte_Cfg.o 


# Each subdirectory must supply rules for building sources it contributes
EB_Stubs/%.src: ../EB_Stubs/%.c EB_Stubs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/EB_Stubs\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

EB_Stubs/%.o: ./EB_Stubs/%.src EB_Stubs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-EB_Stubs

clean-EB_Stubs:
	-$(RM) ./EB_Stubs/CanIf_Cfg.d ./EB_Stubs/CanIf_Cfg.o ./EB_Stubs/CanIf_Cfg.src ./EB_Stubs/CanIf_Lcfg.d ./EB_Stubs/CanIf_Lcfg.o ./EB_Stubs/CanIf_Lcfg.src ./EB_Stubs/CanIf_MultiMF.d ./EB_Stubs/CanIf_MultiMF.o ./EB_Stubs/CanIf_MultiMF.src ./EB_Stubs/CanIf_PBCfg.d ./EB_Stubs/CanIf_PBCfg.o ./EB_Stubs/CanIf_PBCfg.src ./EB_Stubs/CanSM_Cfg.d ./EB_Stubs/CanSM_Cfg.o ./EB_Stubs/CanSM_Cfg.src ./EB_Stubs/Can_17_McmCan_PBCfg.d ./EB_Stubs/Can_17_McmCan_PBCfg.o ./EB_Stubs/Can_17_McmCan_PBCfg.src ./EB_Stubs/ComM_BSW_Cfg.d ./EB_Stubs/ComM_BSW_Cfg.o ./EB_Stubs/ComM_BSW_Cfg.src ./EB_Stubs/ComM_Lcfg.d ./EB_Stubs/ComM_Lcfg.o ./EB_Stubs/ComM_Lcfg.src ./EB_Stubs/ComM_MainFunction.d ./EB_Stubs/ComM_MainFunction.o ./EB_Stubs/ComM_MainFunction.src ./EB_Stubs/ComM_Rte_Cfg.d ./EB_Stubs/ComM_Rte_Cfg.o ./EB_Stubs/ComM_Rte_Cfg.src

.PHONY: clean-EB_Stubs

