# Make file generated with Waijung Blockset

CC = armcc
AS = armasm
LD = armlink
EF = fromelf

#---------------- Parameters ----------------
MODELNAME = download
INCLUDES = -I "D:\Keil5\ARM\ARMCC\include" -I "" 

OUTFILETYPE = bin
CFLAGS = -c --cpu Cortex-M4.fp -g -O3 --apcs=interwork --split_sections $(INCLUDES)  
AFLAGS = --cpu Cortex-M4.fp -g --apcs=interwork  --xref $(INCLUDES)  
LFLAGS = --cpu Cortex-M4.fp --strict --scatter "$(MODELNAME).sct" --summary_stderr --info summarysizes --map --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers  --list ".\$(MODELNAME).map" -o $(MODELNAME).axf 
EFOUTTYPE = --bin


EFLAGS = --output=$(MODELNAME).$(OUTFILETYPE) $(MODELNAME).axf
STARTUP = startup_stm32f4xx.o
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBS = 

#---------------- Rules ----------------
$(MODELNAME).$(OUTFILETYPE): $(MODELNAME).axf
	$(EF) $(EFOUTTYPE) $(EFLAGS)

$(MODELNAME).axf: $(OBJS) $(STARTUP)
	$(LD) $(OBJS) $(LIBS) $(STARTUP) $(LFLAGS) 

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

%.o : %.s
	$(AS) $(AFLAGS) $<
	
