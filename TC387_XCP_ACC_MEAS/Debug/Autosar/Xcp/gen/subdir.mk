################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Xcp/gen/Xcp_Cfg.c \
../Autosar/Xcp/gen/Xcp_Runnables.c \
../Autosar/Xcp/gen/Xcp_Wrapper.c 

COMPILED_SRCS += \
./Autosar/Xcp/gen/Xcp_Cfg.src \
./Autosar/Xcp/gen/Xcp_Runnables.src \
./Autosar/Xcp/gen/Xcp_Wrapper.src 

C_DEPS += \
./Autosar/Xcp/gen/Xcp_Cfg.d \
./Autosar/Xcp/gen/Xcp_Runnables.d \
./Autosar/Xcp/gen/Xcp_Wrapper.d 

OBJS += \
./Autosar/Xcp/gen/Xcp_Cfg.o \
./Autosar/Xcp/gen/Xcp_Runnables.o \
./Autosar/Xcp/gen/Xcp_Wrapper.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Xcp/gen/%.src: ../Autosar/Xcp/gen/%.c Autosar/Xcp/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC387_XCP_ACC_MEAS/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/Xcp\/gen\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/Xcp/gen/%.o: ./Autosar/Xcp/gen/%.src Autosar/Xcp/gen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-Xcp-2f-gen

clean-Autosar-2f-Xcp-2f-gen:
	-$(RM) ./Autosar/Xcp/gen/Xcp_Cfg.d ./Autosar/Xcp/gen/Xcp_Cfg.o ./Autosar/Xcp/gen/Xcp_Cfg.src ./Autosar/Xcp/gen/Xcp_Runnables.d ./Autosar/Xcp/gen/Xcp_Runnables.o ./Autosar/Xcp/gen/Xcp_Runnables.src ./Autosar/Xcp/gen/Xcp_Wrapper.d ./Autosar/Xcp/gen/Xcp_Wrapper.o ./Autosar/Xcp/gen/Xcp_Wrapper.src

.PHONY: clean-Autosar-2f-Xcp-2f-gen

