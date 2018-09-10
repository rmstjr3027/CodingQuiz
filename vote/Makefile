SYS_LIB=
CC=g++
CFLAGS=
LDFLAGS=
LIBS=
PROGS=vote

all:    $(PROGS)

%: %.cpp
	$(CC) -g -o $@ $^

clean::
	-rm -f $(PROGS) *.o core
