################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Modules/INS/actitude.c \
../Core/Src/Modules/INS/altitude.c \
../Core/Src/Modules/INS/geo.c 

OBJS += \
./Core/Src/Modules/INS/actitude.o \
./Core/Src/Modules/INS/altitude.o \
./Core/Src/Modules/INS/geo.o 

C_DEPS += \
./Core/Src/Modules/INS/actitude.d \
./Core/Src/Modules/INS/altitude.d \
./Core/Src/Modules/INS/geo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Modules/INS/%.o Core/Src/Modules/INS/%.su Core/Src/Modules/INS/%.cyclo: ../Core/Src/Modules/INS/%.c Core/Src/Modules/INS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Modules-2f-INS

clean-Core-2f-Src-2f-Modules-2f-INS:
	-$(RM) ./Core/Src/Modules/INS/actitude.cyclo ./Core/Src/Modules/INS/actitude.d ./Core/Src/Modules/INS/actitude.o ./Core/Src/Modules/INS/actitude.su ./Core/Src/Modules/INS/altitude.cyclo ./Core/Src/Modules/INS/altitude.d ./Core/Src/Modules/INS/altitude.o ./Core/Src/Modules/INS/altitude.su ./Core/Src/Modules/INS/geo.cyclo ./Core/Src/Modules/INS/geo.d ./Core/Src/Modules/INS/geo.o ./Core/Src/Modules/INS/geo.su

.PHONY: clean-Core-2f-Src-2f-Modules-2f-INS

