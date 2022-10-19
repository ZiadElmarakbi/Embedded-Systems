CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=-I .
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
PROJECTNAME=ledtoggle_cortex-m4


all: $(PROJECTNAME).bin
	@echo "------------Build Done Successfully------------"


%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@


%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@


$(PROJECTNAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Maped_file.map
	cp $(PROJECTNAME).elf $(PROJECTNAME).axf

$(PROJECTNAME).bin: $(PROJECTNAME).elf
	$(CC)objcopy.exe -O binary $<  $@


clean_all:
	rm *.o *.elf *.bin
	

clean:
	rm *.elf *.bin


