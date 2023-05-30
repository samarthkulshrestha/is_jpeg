CC=clang
CFLAGS=-Wall -g
EXE=is_jpeg

all: $(EXE)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.dSYM *.o $(EXE)
