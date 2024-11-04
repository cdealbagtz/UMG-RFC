################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BlackBox/blackbox.c 

OBJS += \
./Core/Src/BlackBox/blackbox.o 

C_DEPS += \
./Core/Src/BlackBox/blackbox.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BlackBox/%.o Core/Src/BlackBox/%.su Core/Src/BlackBox/%.cyclo: ../Core/Src/BlackBox/%.c Core/Src/BlackBox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-BlackBox

clean-Core-2f-Src-2f-BlackBox:
	-$(RM) ./Core/Src/BlackBox/blackbox.cyclo ./Core/Src/BlackBox/blackbox.d ./Core/Src/BlackBox/blackbox.o ./Core/Src/BlackBox/blackbox.su

.PHONY: clean-Core-2f-Src-2f-BlackBox

