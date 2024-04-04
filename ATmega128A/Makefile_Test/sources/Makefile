IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=.
LDIR =../lib

LIBS=-lm

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst %.c,%.o,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 