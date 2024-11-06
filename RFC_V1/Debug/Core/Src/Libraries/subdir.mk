################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Libraries/BMP280.c \
../Core/Src/Libraries/Flash.c \
../Core/Src/Libraries/MPU6050.c \
../Core/Src/Libraries/NRF24.c 

OBJS += \
./Core/Src/Libraries/BMP280.o \
./Core/Src/Libraries/Flash.o \
./Core/Src/Libraries/MPU6050.o \
./Core/Src/Libraries/NRF24.o 

C_DEPS += \
./Core/Src/Libraries/BMP280.d \
./Core/Src/Libraries/Flash.d \
./Core/Src/Libraries/MPU6050.d \
./Core/Src/Libraries/NRF24.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Libraries/%.o Core/Src/Libraries/%.su Core/Src/Libraries/%.cyclo: ../Core/Src/Libraries/%.c Core/Src/Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Libraries

clean-Core-2f-Src-2f-Libraries:
	-$(RM) ./Core/Src/Libraries/BMP280.cyclo ./Core/Src/Libraries/BMP280.d ./Core/Src/Libraries/BMP280.o ./Core/Src/Libraries/BMP280.su ./Core/Src/Libraries/Flash.cyclo ./Core/Src/Libraries/Flash.d ./Core/Src/Libraries/Flash.o ./Core/Src/Libraries/Flash.su ./Core/Src/Libraries/MPU6050.cyclo ./Core/Src/Libraries/MPU6050.d ./Core/Src/Libraries/MPU6050.o ./Core/Src/Libraries/MPU6050.su ./Core/Src/Libraries/NRF24.cyclo ./Core/Src/Libraries/NRF24.d ./Core/Src/Libraries/NRF24.o ./Core/Src/Libraries/NRF24.su

.PHONY: clean-Core-2f-Src-2f-Libraries

