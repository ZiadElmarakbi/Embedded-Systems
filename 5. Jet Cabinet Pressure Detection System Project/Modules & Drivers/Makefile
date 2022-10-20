CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
PROJECTNAME=Pressure_Detection_System


all: $(PROJECTNAME).bin
	@echo "------------Build Done Successfully------------"


%.o: %.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@


$(PROJECTNAME).elf: $(OBJ)
	$(CC)ld.exe -T linkerScript.ld $(OBJ) -o $@ -Map=Maped_file.map


$(PROJECTNAME).bin: $(PROJECTNAME).elf
	$(CC)objcopy.exe -O binary $<  $@
	$(CC)objdump.exe -D $< >>Pressure_Detection_System_Analysis.txt
	$(CC)objdump.exe -h $< >>System_VMA_LMA_Sections.txt
	$(CC)nm.exe $< >>System_Symbolic_Table.txt
	

clean_all:
	rm *.o *.elf *.bin *.txt *.map
	@echo "--------------------------All Files Removed Successfully !! --------------------------"


clean:
	rm *.elf *.bin



