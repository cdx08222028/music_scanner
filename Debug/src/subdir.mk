################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/file_scanner.cpp \
../src/file_tracker.cpp \
../src/init.cpp \
../src/is_file_type.cpp 

OBJS += \
./src/file_scanner.o \
./src/file_tracker.o \
./src/init.o \
./src/is_file_type.o 

CPP_DEPS += \
./src/file_scanner.d \
./src/file_tracker.d \
./src/init.d \
./src/is_file_type.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -v -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


