################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/CanSM/static/CanSM.c \
../Autosar/CanSM/static/CanSM_Cbk.c \
../Autosar/CanSM/static/CanSM_GetCurrentComMode.c \
../Autosar/CanSM/static/CanSM_GetVersionInfo.c \
../Autosar/CanSM/static/CanSM_Init.c \
../Autosar/CanSM/static/CanSM_MainFunction.c \
../Autosar/CanSM/static/CanSM_RequestComMode.c \
../Autosar/CanSM/static/CanSM_SetBaudrate.c \
../Autosar/CanSM/static/CanSM_StateMachine.c 

COMPILED_SRCS += \
./Autosar/CanSM/static/CanSM.src \
./Autosar/CanSM/static/CanSM_Cbk.src \
./Autosar/CanSM/static/CanSM_GetCurrentComMode.src \
./Autosar/CanSM/static/CanSM_GetVersionInfo.src \
./Autosar/CanSM/static/CanSM_Init.src \
./Autosar/CanSM/static/CanSM_MainFunction.src \
./Autosar/CanSM/static/CanSM_RequestComMode.src \
./Autosar/CanSM/static/CanSM_SetBaudrate.src \
./Autosar/CanSM/static/CanSM_StateMachine.src 

C_DEPS += \
./Autosar/CanSM/static/CanSM.d \
./Autosar/CanSM/static/CanSM_Cbk.d \
./Autosar/CanSM/static/CanSM_GetCurrentComMode.d \
./Autosar/CanSM/static/CanSM_GetVersionInfo.d \
./Autosar/CanSM/static/CanSM_Init.d \
./Autosar/CanSM/static/CanSM_MainFunction.d \
./Autosar/CanSM/static/CanSM_RequestComMode.d \
./Autosar/CanSM/static/CanSM_SetBaudrate.d \
./Autosar/CanSM/static/CanSM_StateMachine.d 

OBJS += \
./Autosar/CanSM/static/CanSM.o \
./Autosar/CanSM/static/CanSM_Cbk.o \
./Autosar/CanSM/static/CanSM_GetCurrentComMode.o \
./Autosar/CanSM/static/CanSM_GetVersionInfo.o \
./Autosar/CanSM/static/CanSM_Init.o \
./Autosar/CanSM/static/CanSM_MainFunction.o \
./Autosar/CanSM/static/CanSM_RequestComMode.o \
./Autosar/CanSM/static/CanSM_SetBaudrate.o \
./Autosar/CanSM/static/CanSM_StateMachine.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/CanSM/static/%.src: ../Autosar/CanSM/static/%.c Autosar/CanSM/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/CanSM\/static\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/CanSM/static/%.o: ./Autosar/CanSM/static/%.src Autosar/CanSM/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-CanSM-2f-static

clean-Autosar-2f-CanSM-2f-static:
	-$(RM) ./Autosar/CanSM/static/CanSM.d ./Autosar/CanSM/static/CanSM.o ./Autosar/CanSM/static/CanSM.src ./Autosar/CanSM/static/CanSM_Cbk.d ./Autosar/CanSM/static/CanSM_Cbk.o ./Autosar/CanSM/static/CanSM_Cbk.src ./Autosar/CanSM/static/CanSM_GetCurrentComMode.d ./Autosar/CanSM/static/CanSM_GetCurrentComMode.o ./Autosar/CanSM/static/CanSM_GetCurrentComMode.src ./Autosar/CanSM/static/CanSM_GetVersionInfo.d ./Autosar/CanSM/static/CanSM_GetVersionInfo.o ./Autosar/CanSM/static/CanSM_GetVersionInfo.src ./Autosar/CanSM/static/CanSM_Init.d ./Autosar/CanSM/static/CanSM_Init.o ./Autosar/CanSM/static/CanSM_Init.src ./Autosar/CanSM/static/CanSM_MainFunction.d ./Autosar/CanSM/static/CanSM_MainFunction.o ./Autosar/CanSM/static/CanSM_MainFunction.src ./Autosar/CanSM/static/CanSM_RequestComMode.d ./Autosar/CanSM/static/CanSM_RequestComMode.o ./Autosar/CanSM/static/CanSM_RequestComMode.src ./Autosar/CanSM/static/CanSM_SetBaudrate.d ./Autosar/CanSM/static/CanSM_SetBaudrate.o ./Autosar/CanSM/static/CanSM_SetBaudrate.src ./Autosar/CanSM/static/CanSM_StateMachine.d ./Autosar/CanSM/static/CanSM_StateMachine.o ./Autosar/CanSM/static/CanSM_StateMachine.src

.PHONY: clean-Autosar-2f-CanSM-2f-static

