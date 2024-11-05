################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Modules/BlackBox/blackbox.c 

OBJS += \
./Core/Src/Modules/BlackBox/blackbox.o 

C_DEPS += \
./Core/Src/Modules/BlackBox/blackbox.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Modules/BlackBox/%.o Core/Src/Modules/BlackBox/%.su Core/Src/Modules/BlackBox/%.cyclo: ../Core/Src/Modules/BlackBox/%.c Core/Src/Modules/BlackBox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Modules-2f-BlackBox

clean-Core-2f-Src-2f-Modules-2f-BlackBox:
	-$(RM) ./Core/Src/Modules/BlackBox/blackbox.cyclo ./Core/Src/Modules/BlackBox/blackbox.d ./Core/Src/Modules/BlackBox/blackbox.o ./Core/Src/Modules/BlackBox/blackbox.su

.PHONY: clean-Core-2f-Src-2f-Modules-2f-BlackBox
