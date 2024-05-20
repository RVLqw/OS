.PHONY: clean run asm

OBJS = main.o fibonacci.o
CFLAGS =-Os -g3 -Wall

run: fibb
	./fibb

fibb: $(OBJS)
	gcc $(CFLAGS) -o fibb $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f fibb $(OBJS)

asm:
	gcc -S -o fibb.s fibb.c
	gcc -S -o hello.s hello.c
