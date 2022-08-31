################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Pointers\ Practice.c 

C_DEPS += \
./Code/Pointers\ Practice.d 

OBJS += \
./Code/Pointers\ Practice.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Pointers\ Practice.o: ../Code/Pointers\ Practice.c Code/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Code/Pointers Practice.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Code

clean-Code:
	-$(RM) ./Code/Pointers\ Practice.d ./Code/Pointers\ Practice.o

.PHONY: clean-Code

