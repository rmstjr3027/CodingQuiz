SYS_LIB=
CC=g++
CFLAGS=
LDFLAGS=
LIBS=
PROGS=brackets

all:    $(PROGS)

%: %.cpp
	$(CC) -g -o $@ $^

clean::
	-rm -f $(PROGS) *.o core
