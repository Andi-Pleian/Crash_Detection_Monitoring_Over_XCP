################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/ComM/static/ComM.c \
../Autosar/ComM/static/ComM_ASR32_Rte.c \
../Autosar/ComM/static/ComM_ASR40_Rte.c \
../Autosar/ComM/static/ComM_Hsm.c \
../Autosar/ComM/static/ComM_HsmComMData.c \
../Autosar/ComM/static/ComM_HsmComMFnct.c \
../Autosar/ComM/static/ComM_HsmComMPncData.c \
../Autosar/ComM/static/ComM_HsmComMPncFnct.c \
../Autosar/ComM/static/ComM_Rte.c 

COMPILED_SRCS += \
./Autosar/ComM/static/ComM.src \
./Autosar/ComM/static/ComM_ASR32_Rte.src \
./Autosar/ComM/static/ComM_ASR40_Rte.src \
./Autosar/ComM/static/ComM_Hsm.src \
./Autosar/ComM/static/ComM_HsmComMData.src \
./Autosar/ComM/static/ComM_HsmComMFnct.src \
./Autosar/ComM/static/ComM_HsmComMPncData.src \
./Autosar/ComM/static/ComM_HsmComMPncFnct.src \
./Autosar/ComM/static/ComM_Rte.src 

C_DEPS += \
./Autosar/ComM/static/ComM.d \
./Autosar/ComM/static/ComM_ASR32_Rte.d \
./Autosar/ComM/static/ComM_ASR40_Rte.d \
./Autosar/ComM/static/ComM_Hsm.d \
./Autosar/ComM/static/ComM_HsmComMData.d \
./Autosar/ComM/static/ComM_HsmComMFnct.d \
./Autosar/ComM/static/ComM_HsmComMPncData.d \
./Autosar/ComM/static/ComM_HsmComMPncFnct.d \
./Autosar/ComM/static/ComM_Rte.d 

OBJS += \
./Autosar/ComM/static/ComM.o \
./Autosar/ComM/static/ComM_ASR32_Rte.o \
./Autosar/ComM/static/ComM_ASR40_Rte.o \
./Autosar/ComM/static/ComM_Hsm.o \
./Autosar/ComM/static/ComM_HsmComMData.o \
./Autosar/ComM/static/ComM_HsmComMFnct.o \
./Autosar/ComM/static/ComM_HsmComMPncData.o \
./Autosar/ComM/static/ComM_HsmComMPncFnct.o \
./Autosar/ComM/static/ComM_Rte.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/ComM/static/%.src: ../Autosar/ComM/static/%.c Autosar/ComM/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/ComM\/static\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/ComM/static/%.o: ./Autosar/ComM/static/%.src Autosar/ComM/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-ComM-2f-static

clean-Autosar-2f-ComM-2f-static:
	-$(RM) ./Autosar/ComM/static/ComM.d ./Autosar/ComM/static/ComM.o ./Autosar/ComM/static/ComM.src ./Autosar/ComM/static/ComM_ASR32_Rte.d ./Autosar/ComM/static/ComM_ASR32_Rte.o ./Autosar/ComM/static/ComM_ASR32_Rte.src ./Autosar/ComM/static/ComM_ASR40_Rte.d ./Autosar/ComM/static/ComM_ASR40_Rte.o ./Autosar/ComM/static/ComM_ASR40_Rte.src ./Autosar/ComM/static/ComM_Hsm.d ./Autosar/ComM/static/ComM_Hsm.o ./Autosar/ComM/static/ComM_Hsm.src ./Autosar/ComM/static/ComM_HsmComMData.d ./Autosar/ComM/static/ComM_HsmComMData.o ./Autosar/ComM/static/ComM_HsmComMData.src ./Autosar/ComM/static/ComM_HsmComMFnct.d ./Autosar/ComM/static/ComM_HsmComMFnct.o ./Autosar/ComM/static/ComM_HsmComMFnct.src ./Autosar/ComM/static/ComM_HsmComMPncData.d ./Autosar/ComM/static/ComM_HsmComMPncData.o ./Autosar/ComM/static/ComM_HsmComMPncData.src ./Autosar/ComM/static/ComM_HsmComMPncFnct.d ./Autosar/ComM/static/ComM_HsmComMPncFnct.o ./Autosar/ComM/static/ComM_HsmComMPncFnct.src ./Autosar/ComM/static/ComM_Rte.d ./Autosar/ComM/static/ComM_Rte.o ./Autosar/ComM/static/ComM_Rte.src

.PHONY: clean-Autosar-2f-ComM-2f-static

