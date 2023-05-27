################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autosar/Xcp/static/Xcp.c \
../Autosar/Xcp/static/Xcp_CommandProcessor.c \
../Autosar/Xcp/static/Xcp_EventProcessor.c \
../Autosar/Xcp/static/Xcp_EventReceiver.c \
../Autosar/Xcp/static/Xcp_ReceiveProcessor.c \
../Autosar/Xcp/static/Xcp_StimProcessor.c \
../Autosar/Xcp/static/Xcp_TransmitProcessor.c 

COMPILED_SRCS += \
./Autosar/Xcp/static/Xcp.src \
./Autosar/Xcp/static/Xcp_CommandProcessor.src \
./Autosar/Xcp/static/Xcp_EventProcessor.src \
./Autosar/Xcp/static/Xcp_EventReceiver.src \
./Autosar/Xcp/static/Xcp_ReceiveProcessor.src \
./Autosar/Xcp/static/Xcp_StimProcessor.src \
./Autosar/Xcp/static/Xcp_TransmitProcessor.src 

C_DEPS += \
./Autosar/Xcp/static/Xcp.d \
./Autosar/Xcp/static/Xcp_CommandProcessor.d \
./Autosar/Xcp/static/Xcp_EventProcessor.d \
./Autosar/Xcp/static/Xcp_EventReceiver.d \
./Autosar/Xcp/static/Xcp_ReceiveProcessor.d \
./Autosar/Xcp/static/Xcp_StimProcessor.d \
./Autosar/Xcp/static/Xcp_TransmitProcessor.d 

OBJS += \
./Autosar/Xcp/static/Xcp.o \
./Autosar/Xcp/static/Xcp_CommandProcessor.o \
./Autosar/Xcp/static/Xcp_EventProcessor.o \
./Autosar/Xcp/static/Xcp_EventReceiver.o \
./Autosar/Xcp/static/Xcp_ReceiveProcessor.o \
./Autosar/Xcp/static/Xcp_StimProcessor.o \
./Autosar/Xcp/static/Xcp_TransmitProcessor.o 


# Each subdirectory must supply rules for building sources it contributes
Autosar/Xcp/static/%.src: ../Autosar/Xcp/static/%.c Autosar/Xcp/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/Users/uif47623/AURIX-v1.9.0-workspace/TC387_XCP_ACC_MEAS/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Autosar\/Xcp\/static\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Autosar/Xcp/static/%.o: ./Autosar/Xcp/static/%.src Autosar/Xcp/static/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Autosar-2f-Xcp-2f-static

clean-Autosar-2f-Xcp-2f-static:
	-$(RM) ./Autosar/Xcp/static/Xcp.d ./Autosar/Xcp/static/Xcp.o ./Autosar/Xcp/static/Xcp.src ./Autosar/Xcp/static/Xcp_CommandProcessor.d ./Autosar/Xcp/static/Xcp_CommandProcessor.o ./Autosar/Xcp/static/Xcp_CommandProcessor.src ./Autosar/Xcp/static/Xcp_EventProcessor.d ./Autosar/Xcp/static/Xcp_EventProcessor.o ./Autosar/Xcp/static/Xcp_EventProcessor.src ./Autosar/Xcp/static/Xcp_EventReceiver.d ./Autosar/Xcp/static/Xcp_EventReceiver.o ./Autosar/Xcp/static/Xcp_EventReceiver.src ./Autosar/Xcp/static/Xcp_ReceiveProcessor.d ./Autosar/Xcp/static/Xcp_ReceiveProcessor.o ./Autosar/Xcp/static/Xcp_ReceiveProcessor.src ./Autosar/Xcp/static/Xcp_StimProcessor.d ./Autosar/Xcp/static/Xcp_StimProcessor.o ./Autosar/Xcp/static/Xcp_StimProcessor.src ./Autosar/Xcp/static/Xcp_TransmitProcessor.d ./Autosar/Xcp/static/Xcp_TransmitProcessor.o ./Autosar/Xcp/static/Xcp_TransmitProcessor.src

.PHONY: clean-Autosar-2f-Xcp-2f-static

