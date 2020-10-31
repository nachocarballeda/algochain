CCFLAGS= -Wall
CC= g++

all: sha

sha: main.o sha256.o cmdline.o
	$(CC) $(CCFLAGS) -o sha256 main.o sha256.o cmdline.o

main.o: main.cpp sha256.h cmdline.h
	$(CC) $(CCFLAGS) -c main.cpp -o main.o 

sha256.o: sha256.cpp sha256.h
	$(CC) $(CCFLAGS) -c sha256.cpp -o sha256.o 

cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc -o cmdline.o 

clean:
	$(RM) *.o sha256
