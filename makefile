all: main.c
	gcc -o prgrm main.c

run: prgrm
	./prgrm "ls -a -l"
