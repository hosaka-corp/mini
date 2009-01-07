include ../toolchain.rules

CFLAGS = -mbig-endian -fomit-frame-pointer -Os -Wall -I.
ASFLAGS = -mbig-endian
LDFLAGS = -nostartfiles -nodefaultlibs -mbig-endian -Wl,-T,miniios.ld,-Map,miniios.map -n
LIBS = -lgcc

ELFLOADER = ../elfloader/elfloader.bin
MAKEBIN = python ../makebin.py

TARGET = miniios.bin
ELF = miniios.elf
OBJECTS = start.o main.o vsprintf.o string.o gecko.o memory.o memory_asm.o \
	utils_asm.o utils.o ff.o diskio.o sdhc.o powerpc_elf.o powerpc.o panic.o

$(TARGET) : $(ELF) $(ELFLOADER) 
	@echo  "MAKEBIN	$@"
	@$(MAKEBIN) $(ELFLOADER) $< $@

$(ELF) : miniios.ld $(OBJECTS)
	@echo  "LD	$@"
	@$(LD) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

%.o : %.S
	@echo  "AS	$@"
	@$(AS) $(ASFLAGS) -o $@ $<

%.o : %.c
	@echo  "CC	$@"
	@$(CC) $(CFLAGS) -c -o $@ $<

%.d: %.c
	@echo  "DEP	$@"
	@set -e; $(CC) -M $(CFLAGS) $< \
		| sed 's?\($*\)\.o[ :]*?\1.o $@ : ?g' > $@; \
		[ -s $@ ] || rm -f $@

%.d: %.S
	@echo	"DEP	$@"
	@touch $@

-include $(OBJECTS:.o=.d)

clean:
	-rm -f *.elf *.o *.bin *.d *.map

