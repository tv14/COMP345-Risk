################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InteractiveMapCreator.cpp \
../src/MapManager.cpp \
../src/Test.cpp 

OBJS += \
./src/InteractiveMapCreator.o \
./src/MapManager.o \
./src/Test.o 

CPP_DEPS += \
./src/InteractiveMapCreator.d \
./src/MapManager.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


