FILENAME	= main
MCU			= atmega128a
F_CPU		= 16000000L
PROGRAMMER	= stk500
PORT		= /dev/cu.usbserial-0001
BAUD		= 115200

IDIR 		= ../include
CFLAGS		= -I$(IDIR)
ODIR		= .
CC			= avr-gcc

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst %.c,%.o,$(_OBJ))

LIBS		= -u vfprintf -lprintf_flt

COMPILE		= $(CC) -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(LIBS)
#COMPILE		= avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -u vfprintf -lprintf_min
#COMPILE		= avr-gcc -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

default: compile upload clean

compile:
	$(COMPILE) -c $(_OBJ) $(CFLAGS)
	$(COMPILE) -o $(FILENAME).elf $(OBJ)
	avr-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(MCU) $(FILENAME).elf

upload:
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.hex