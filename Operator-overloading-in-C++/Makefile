CC = g++
APPNAME = OP
EXT =
SRCDIR = .
OBJDIR = .

OBJ = *.o
DEP = *.d
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)

#///////////////////////////////////////////////////////////////////
#///////////////////// Targets beginning here //////////////////////
#///////////////////////////////////////////////////////////////////
include MakeConfig
vfiles = $(files:.c=.o)

################### Build rules for Unix-based OS ###################
build: clean $(vfiles)
	$(CC) $(vfiles) -o $(APPNAME)$(EXT)

################### Cleaning rules for Unix-based OS ###################

# Cleans complete project
.PHONY: clean
clean:
ifneq ("$(wildcard $(DELOBJ))","")
	$(RM) $(DELOBJ)
endif
ifneq ("$(wildcard $(APPNAME))","")
	$(RM) $(APPNAME)
endif