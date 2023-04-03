################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Task_Scheduler/Task_Scheduler.c 

COMPILED_SRCS += \
./Task_Scheduler/Task_Scheduler.src 

C_DEPS += \
./Task_Scheduler/Task_Scheduler.d 

OBJS += \
./Task_Scheduler/Task_Scheduler.o 


# Each subdirectory must supply rules for building sources it contributes
Task_Scheduler/%.src: ../Task_Scheduler/%.c Task_Scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc36x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC3x7_XCP/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Task_Scheduler\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Task_Scheduler/%.o: ./Task_Scheduler/%.src Task_Scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Task_Scheduler

clean-Task_Scheduler:
	-$(RM) ./Task_Scheduler/Task_Scheduler.d ./Task_Scheduler/Task_Scheduler.o ./Task_Scheduler/Task_Scheduler.src

.PHONY: clean-Task_Scheduler

