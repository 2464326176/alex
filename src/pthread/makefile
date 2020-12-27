src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

all: thread

thread: saleTicket.o threadMain.o
	gcc saleTicket.o threadMain.o -o server -Wall -lpthread

%.o:%.c
	gcc -c $< -Wall

.PHONY: clean all
clean:
	-rm -rf server client $(obj)

