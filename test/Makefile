# Target microcontroller and clock frequency
MCU = atmega32
F_CPU = 16000000UL

# Programmer configuration
PROGRAMMER = usbasp
PORT = usb

# Compiler and tools
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Directories containing source code and headers
# Add any other folders you create (e.g., APP, LIB) to this list separated by spaces
SRC_DIRS = . MCAL HAL

# Find all .c files in the specified directories
SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# Generate the corresponding .o object file paths
OBJS = $(SRCS:.c=.o)

# Automatically generate the -I include flags for every directory
INC_FLAGS = $(foreach dir, $(SRC_DIRS), -I$(dir))

# Compiler flags
CFLAGS = -Os -Wall -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(INC_FLAGS)

# Project name
TARGET = main

# Default build target
all: $(TARGET).hex

# Compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into an ELF file
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Generate the HEX file from the ELF file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash the HEX file to the microcontroller
flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -U flash:w:$<:i

# Remove all compiled build files, including those inside subfolders
clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex

.PHONY: all flash clean