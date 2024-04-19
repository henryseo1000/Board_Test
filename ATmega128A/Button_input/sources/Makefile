FILENAME	= main#생성 파일 이름
MCU			= atmega128a#보드의 MCU
F_CPU		= 16000000L#클록
PROGRAMMER	= stk500#ISP 다운로더를 사용하는 경우
PORT		= /dev/cu.usbserial-0001#포트(사용자에 따라 수정이 필요)
BAUD		= 115200#baudrate

IDIR 		= ../include#헤더파일 위치
CFLAGS		= -I$(IDIR)#헤더파일 디렉토리를 포함해줍니다.
ODIR		= ./obj#.o파일을 생성시킬 디렉토리
SDIR		= .#.c파일(소스파일)이 위치한 디렉토리
CC			= avr-gcc#컴파일러 명령어

DEPS = $(wildcard $(IDIR)/*.h) #헤더파일 디렉토리에서 .h 형태의 파일 경로를 뽑아냅니다.

SRCS = $(wildcard $(SDIR)/*.c) #.c 디렉토리에서 .c 형태의 파일 경로를 뽑아냅니다.
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS)) #.c 형태를 .o 형태의 경로로 변환합니다.

LIBS		= -u vfprintf -lprintf_flt

COMPILE		= $(CC) -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(LIBS)

$(ODIR)/%.o: %.c | $(DEPS)
	mkdir -p $(ODIR)
	$(COMPILE) -c -o $@ $< $(CFLAGS)

default: compile upload clean

compile: $(OBJ)
	$(COMPILE) -o $(FILENAME).elf $^ $(CFLAGS)
	avr-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(MCU) $(FILENAME).elf

upload:
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm -rf obj
	rm -f *.o
	rm -f *.elf
	rm -f *.hex