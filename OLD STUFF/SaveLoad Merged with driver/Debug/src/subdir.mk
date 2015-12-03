################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Battle.cpp \
../src/Continent.cpp \
../src/Country.cpp \
../src/Fortification.cpp \
../src/InteractiveMapCreator.cpp \
../src/Map.cpp \
../src/MapManager.cpp \
../src/Observer.cpp \
../src/PlayerSubject.cpp \
../src/PlayerView.cpp \
../src/RiskMap.cpp \
../src/SelectandBattle.cpp \
../src/Subject.cpp \
../src/Test.cpp \
../src/driver.cpp \
../src/main.cpp \
../src/player.cpp \
../src/stdafx.cpp 

OBJS += \
./src/Battle.o \
./src/Continent.o \
./src/Country.o \
./src/Fortification.o \
./src/InteractiveMapCreator.o \
./src/Map.o \
./src/MapManager.o \
./src/Observer.o \
./src/PlayerSubject.o \
./src/PlayerView.o \
./src/RiskMap.o \
./src/SelectandBattle.o \
./src/Subject.o \
./src/Test.o \
./src/driver.o \
./src/main.o \
./src/player.o \
./src/stdafx.o 

CPP_DEPS += \
./src/Battle.d \
./src/Continent.d \
./src/Country.d \
./src/Fortification.d \
./src/InteractiveMapCreator.d \
./src/Map.d \
./src/MapManager.d \
./src/Observer.d \
./src/PlayerSubject.d \
./src/PlayerView.d \
./src/RiskMap.d \
./src/SelectandBattle.d \
./src/Subject.d \
./src/Test.d \
./src/driver.d \
./src/main.d \
./src/player.d \
./src/stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


