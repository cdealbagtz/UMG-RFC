################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Modules/Telemetry/payload.c \
../Core/Src/Modules/Telemetry/telemetry.c 

OBJS += \
./Core/Src/Modules/Telemetry/payload.o \
./Core/Src/Modules/Telemetry/telemetry.o 

C_DEPS += \
./Core/Src/Modules/Telemetry/payload.d \
./Core/Src/Modules/Telemetry/telemetry.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Modules/Telemetry/%.o Core/Src/Modules/Telemetry/%.su Core/Src/Modules/Telemetry/%.cyclo: ../Core/Src/Modules/Telemetry/%.c Core/Src/Modules/Telemetry/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Modules-2f-Telemetry

clean-Core-2f-Src-2f-Modules-2f-Telemetry:
	-$(RM) ./Core/Src/Modules/Telemetry/payload.cyclo ./Core/Src/Modules/Telemetry/payload.d ./Core/Src/Modules/Telemetry/payload.o ./Core/Src/Modules/Telemetry/payload.su ./Core/Src/Modules/Telemetry/telemetry.cyclo ./Core/Src/Modules/Telemetry/telemetry.d ./Core/Src/Modules/Telemetry/telemetry.o ./Core/Src/Modules/Telemetry/telemetry.su

.PHONY: clean-Core-2f-Src-2f-Modules-2f-Telemetry

