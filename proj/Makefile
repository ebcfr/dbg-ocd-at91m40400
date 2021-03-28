##############################################################################################
# Start of user section
#
# Define project name here
#PROJ = ex1
#PROJ = ex2
#PROJ = ex3
#PROJ = ex4
#PROJ = ex5
#PROJ = ex6
#PROJ = ex7
PROJ = ex8

# Define linker script file here
LDSCRIPT = config/sram.lds
#LDSCRIPT = config/flash.lds

# Define optimisation level here
OPT = -O0

# Debug
DEBUG = -g

# List all user C define here
UDEFS =

# Define ASM defines here
UADEFS = -D__ASSEMBLY__

# List C source files here
SRC  = src/$(PROJ).c \
       startup/board_lowlevel.c \
       startup/board_stubs.c \
       lib/io.c lib/irq.c lib/uart.c lib/util.c lib/termio.c lib/tc.c
       
# List ASM source files here
ASRC = startup/board_cstartup.s lib/irq_asm.s

# List all user directories here
UINCDIR =include lib

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS = 

#
# End of user defines
#############################################################################


#############################################################################
# Start of default section
#

TARGET  = arm-none-eabi-
CC      = $(TARGET)gcc
OBJCOPY = $(TARGET)objcopy
AS      = $(TARGET)gcc -x assembler-with-cpp -c
SIZE    = $(TARGET)size
OBJDUMP = $(TARGET)objdump

MCU  = arm7tdmi

# List all default C defines here, like -D_DEBUG=1
DDEFS =

# List all default ASM defines here, like -D_DEBUG=1
DADEFS =

# List all default directories to look for include files here
DINCDIR = 

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
DLIBS = 

#
# End of default section
##############################################################################################

INCDIR  = $(patsubst %,-I%,$(DINCDIR) $(UINCDIR))
LIBDIR  = $(patsubst %,-L%,$(DLIBDIR) $(ULIBDIR))
DEFS    = $(DDEFS) $(UDEFS)
ADEFS   = $(DADEFS) $(UADEFS)
OBJS    = $(SRC:.c=.o) $(ASRC:.s=.o)
LIBS    = $(DLIBS) $(ULIBS)

# In case THUMB code should be created, add "-mthumb" to the MCFLAGS too.
MCFLAGS = -mcpu=$(MCU)

ASFLAGS = $(INCDIR) -Wa,--gdwarf2 $(ADEFS)
CFLAGS = $(INCDIR) $(MCFLAGS) $(DEBUG) $(OPT) -fomit-frame-pointer -Wall -mlong-calls -ffunction-sections $(DEFS)
LDFLAGS = $(MCFLAGS) -nostartfiles -T$(LDSCRIPT) -Wl,-Map=$(PROJ).map,--gc-sections $(LIBDIR)

# Generate dependency information
CFLAGS += -MD -MP -MF .dep/$(@F).d
ASFLAGS += -MD -MP -MF .dep/$(@F).d

#
# makefile rules
#
all: $(OBJS) main.elf

%o: %c
	$(CC) -c $(CFLAGS) $< -o $@

%o: %s
	$(AS) $(ASFLAGS) $< -o $@

%.elf: $(OBJS) $(LDSCRIPT)
	$(CC) -o $@ $(filter-out %.lds, $^) $(LDFLAGS) $(LIBS)
	$(OBJDUMP) -h $@
	$(SIZE) $@
	
clean:
	-rm -f $(OBJS)
	-rm -f *.elf
	-rm -f *.map
	-rm -f *.bin
	-rm -f *.hex
	-rm -fR .dep

# 
# Include the dependency files, should be the last of the makefile
#
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY: clean

