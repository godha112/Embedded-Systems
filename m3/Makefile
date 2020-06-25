#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This makefile is created to perform multiple source file compilation and 
# support two different platform targets.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - the preprocessed output of all c-program implementation 
#                  files
#      <FILE>.asm - the assembly output of c-program implementation files and 
#		            the finale output executable
#	   <FILE>.o - the object file for all c-source files but not linked
#	   compile-all - compile all object files.
#	   build - compile all files and link into a final executable.
#	   clean - remove all the compiled objects, preprocessed outputs, assembly outputs,
#		       executable files and buil option files.
#
# Platform Overrides:
#      HOST - Default platform which uses native compiler - gcc
#      MSP432 - Target cross-compiled platform which uses
#      cross compiler - arm-none-eabi-gcc
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
VERBOSE = DISABLE
COURSE = COURSE1

# general flags for both platforms
GEN_FLAGS =  \
	    -Wall \
	    -Werror \
	    -g \
	    -O0 \
	    -std=c99


TARGET = c1m2

ifeq($(VERBOSE), ENABLE)
	CPPFLAGS += -DVERBOSE
endif

ifeq($(COURSE), COURSE1)
	CPPFLAGS += -DCOURSE1
endif
			
# conditional check for switching between the platforms
ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
	LINKER_FILE = -T msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	EXTRA = -mthumb \
	        -mfloat-abi=hard \
		-mfpu=fpv4-sp-d16
			
	# Compiler Flags and Defines
	CC=arm-none-eabi-gcc
	LD=arm-none-eabi-ld
	LDFLAGS=-Wl, -Map = $(TARGET).map -T -L ../$(LINKER_FILE)
	CFLAGS=$(GEN_FLAGS) $(EXTRA) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	CPPFLAGs=-DMSP432 $(INCLUDES)
	
	#Architecture specific source files
	SOURCES = \
		  main.c \
		  memory.c \
		  interrupts_msp432p401r_gcc.c \
		  startup_msp432p401r_gcc.c \
		  system_msp432p401r.c

	SIZE=arm-none-eabi-size
	
	
	
else 
	# Compiler Flags and Defines
	CC=gcc
	LDFLAGS=-Wl,-Map=$(TARGET).map
	CFLAGS=$(GEN_FLAGS)
	CPPFLAGs=-DHOST $(INCLUDES)
	
	SIZE=size
	
	
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PREP = $(SOURCES:.c=.i)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGs) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGs) -o $@

%.i : %.c
	$(CC) -E $< $(CPPFLAGs) -o $@

%.d : %.c
	$(CC) -E -M $< $(CPPFLAGs) -o $@
		
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: Build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@


.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map 

