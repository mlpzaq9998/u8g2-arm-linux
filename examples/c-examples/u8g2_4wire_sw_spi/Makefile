
# Chosse proper compiler for your PI
# NanoPi:             arm-linux-gnueabi-gcc
# Raspberry Pi Zero:  arm-linux-gnueabi-gcc

# Raspberry Pi 2:     arm-linux-gnueabihf-gcc
# OrangePi Zero:      arm-linux-gnueabihf-gcc
# NanoPi NEO:         arm-linux-gnueabihf-gcc
# NanoPi NEO Plus 2:  arm-linux-gnueabihf-gcc

# C-SKY Linux:  csky-linux-gcc
TOOLCHAIN_PATH = ~/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf
CROSS_COMPILER = arm-linux-gnueabihf
CC = $(TOOLCHAIN_PATH)/bin/$(CROSS_COMPILER)-gcc
# CC=arm-linux-gnueabi-gcc

# IP Address of your PI
PI=pi@raspberrypi.local

MARCH = armv7-a
TARGET=u8g2_4wire_sw_spi
IDIR= -I ../../../drivers -I ../../../csrc -I ../../../port
SRCDIR=../../../csrc
OBJDIR=../../../obj
OUTDIR=../../../bin
LDIR= -L ../../../lib
LIBS=  -lm

CFLAGS= $(IDIR) -march=$(MARCH) -W -Wall -D __ARM_LINUX__
#CFLAGS= $(IDIR) -W -Wall -D __ARM_LINUX__

OBJ+=u8g2_4wire_sw_spi.o\
	../../../port/u8g2port.o\
	../../../drivers/gpio.o\
	../../../drivers/spi.o\
	../../../drivers/i2c.o\

OBJ+=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.c))

all: directories $(TARGET) 

directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OUTDIR)

$(TARGET):$(OBJ)
	@echo Generating $(TARGET) ...
	@$(CC) -o $(OUTDIR)/$@ $(OBJ) $(LDIR) $(LIBS) -static

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(LDIR) $(LIBS) -static

clean:
	@echo RM -rf $(OBJDIR)/
	@rm -rf $(OBJ)
	@rm -rf $(OBJDIR)
	
	@echo RM -rf $(OUTDIR)/
	@rm -rf $(OUTDIR)

upload:
	scp $(OUTDIR)/$(TARGET) $(PI):~/

run:
	ssh $(PI)
