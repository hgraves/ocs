CC := g++

# internal flags
CCFLAGS     := -g
LDFLAGS     := -g
LIBRARIES   := -lm
################################################################################

# Target rules
all: build

build: ocs

ocs.o:ocs.cpp mytypes.h
	$(CC) $(CCFLAGS) -o $@ -c $<

mathops.o:mathops.cpp mathops.h mytypes.h
	$(CC) $(CCFLAGS) -o $@ -c $<

coords.o:coords.cpp coords.h mytypes.h mathops.o
	$(CC) $(CCFLAGS) -o $@ -c $<

sidereal.o:sidereal.cpp sidereal.h mytypes.h mathops.o
	$(CC) $(CCFLAGS) -o $@ -c $<

ocs: ocs.o mathops.o coords.o sidereal.o
	$(CC) $(LDFLAGS) -o $@ $+ $(LIBRARIES)

clean:
	rm -f ocs ocs.o mathops.o coords.o sidereal.o

clobber: clean
