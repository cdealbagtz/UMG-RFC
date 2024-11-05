################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/RTOS/RTOS.c 

OBJS += \
./Core/Src/RTOS/RTOS.o 

C_DEPS += \
./Core/Src/RTOS/RTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/RTOS/%.o Core/Src/RTOS/%.su Core/Src/RTOS/%.cyclo: ../Core/Src/RTOS/%.c Core/Src/RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-RTOS

clean-Core-2f-Src-2f-RTOS:
	-$(RM) ./Core/Src/RTOS/RTOS.cyclo ./Core/Src/RTOS/RTOS.d ./Core/Src/RTOS/RTOS.o ./Core/Src/RTOS/RTOS.su

.PHONY: clean-Core-2f-Src-2f-RTOS

