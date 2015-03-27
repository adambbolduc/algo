################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ContratException.cpp \
../src/Metro.cpp \
../src/Station.cpp \
../src/TP2.cpp 

OBJS += \
./src/ContratException.o \
./src/Metro.o \
./src/Station.o \
./src/TP2.o 

CPP_DEPS += \
./src/ContratException.d \
./src/Metro.d \
./src/Station.d \
./src/TP2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


