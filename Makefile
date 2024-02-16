CFLAGS = -g -Wall -Wextra -std=c2x -lm

Source = $(wildcard *.c)
Object = ${Source:.c=.o}
Library = $(wildcard src/*.c)

%.o: %.c
	gcc $(CFLAGS) -c $< -o build/$@

main: main.o
	gcc $(CFLAGS) $(Library) $(Source) -o build/main

