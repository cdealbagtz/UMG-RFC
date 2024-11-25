################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Modules/Status/commands.c \
../Core/Src/Modules/Status/flight_phase.c \
../Core/Src/Modules/Status/memory.c \
../Core/Src/Modules/Status/power.c \
../Core/Src/Modules/Status/status.c 

OBJS += \
./Core/Src/Modules/Status/commands.o \
./Core/Src/Modules/Status/flight_phase.o \
./Core/Src/Modules/Status/memory.o \
./Core/Src/Modules/Status/power.o \
./Core/Src/Modules/Status/status.o 

C_DEPS += \
./Core/Src/Modules/Status/commands.d \
./Core/Src/Modules/Status/flight_phase.d \
./Core/Src/Modules/Status/memory.d \
./Core/Src/Modules/Status/power.d \
./Core/Src/Modules/Status/status.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Modules/Status/%.o Core/Src/Modules/Status/%.su Core/Src/Modules/Status/%.cyclo: ../Core/Src/Modules/Status/%.c Core/Src/Modules/Status/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Modules-2f-Status

clean-Core-2f-Src-2f-Modules-2f-Status:
	-$(RM) ./Core/Src/Modules/Status/commands.cyclo ./Core/Src/Modules/Status/commands.d ./Core/Src/Modules/Status/commands.o ./Core/Src/Modules/Status/commands.su ./Core/Src/Modules/Status/flight_phase.cyclo ./Core/Src/Modules/Status/flight_phase.d ./Core/Src/Modules/Status/flight_phase.o ./Core/Src/Modules/Status/flight_phase.su ./Core/Src/Modules/Status/memory.cyclo ./Core/Src/Modules/Status/memory.d ./Core/Src/Modules/Status/memory.o ./Core/Src/Modules/Status/memory.su ./Core/Src/Modules/Status/power.cyclo ./Core/Src/Modules/Status/power.d ./Core/Src/Modules/Status/power.o ./Core/Src/Modules/Status/power.su ./Core/Src/Modules/Status/status.cyclo ./Core/Src/Modules/Status/status.d ./Core/Src/Modules/Status/status.o ./Core/Src/Modules/Status/status.su

.PHONY: clean-Core-2f-Src-2f-Modules-2f-Status

