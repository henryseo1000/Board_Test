FILENAME	= main
MCU			= atmega128a
F_CPU		= 16000000L
PROGRAMMER	= stk500
PORT		= /dev/cu.usbserial-0001
BAUD		= 115200

COMPILE		= avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -u vfprintf -lprintf_flt
#COMPILE		= avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -u vfprintf -lprintf_min
#COMPILE		= avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

default: compile upload clean

compile:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(MCU) $(FILENAME).elf

upload:
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex