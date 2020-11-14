IDIR = ../include
CCFLAGS = -Wall -I$(IDIR) -std=gnu++11
CC = g++

all: algochain

algochain: main.o sha256.o cmdline.o algochain.o block.o body.o header.o txn.o \
	input.o output.o outpoint.o errorlog.o arghandler.o
	$(CC) $(CCFLAGS) -o algochain.bin build/main.o build/sha256.o \
	build/cmdline.o build/txn.o build/algochain.o build/block.o build/body.o build/header.o \
	build/input.o build/output.o build/outpoint.o build/errorlog.o \
	build/arghandler.o
	
main.o: main.cpp include/sha256.h include/cmdline.h
	$(CC) $(CCFLAGS) -c main.cpp -o build/main.o 

sha256.o: src/sha256.cpp include/sha256.h
	$(CC) $(CCFLAGS) -c src/sha256.cpp -o build/sha256.o 

cmdline.o: src/cmdline.cpp include/cmdline.h
	$(CC) $(CCFLAGS) -c src/cmdline.cpp -o build/cmdline.o 

algochain.o:  src/algochain.cpp include/algochain.h
	$(CC) $(CCFLAGS) -c src/algochain.cpp -o build/algochain.o

block.o:  src/block.cpp include/block.h
	$(CC) $(CCFLAGS) -c src/block.cpp -o build/block.o

header.o:  src/header.cpp include/header.h
	$(CC) $(CCFLAGS) -c src/header.cpp -o build/header.o

body.o:  src/body.cpp include/body.h
	$(CC) $(CCFLAGS) -c src/body.cpp -o build/body.o

txn.o:  src/txn.cpp include/txn.h
	$(CC) $(CCFLAGS) -c src/txn.cpp -o build/txn.o

input.o:  src/input.cpp include/input.h
	$(CC) $(CCFLAGS) -c src/input.cpp -o build/input.o

output.o:  src/output.cpp include/output.h
	$(CC) $(CCFLAGS) -c src/output.cpp -o build/output.o

outpoint.o:  src/outpoint.cpp include/outpoint.h
	$(CC) $(CCFLAGS) -c src/outpoint.cpp -o build/outpoint.o

errorlog.o:  src/errorlog.cpp include/errorlog.h
	$(CC) $(CCFLAGS) -c src/errorlog.cpp -o build/errorlog.o

arghandler.o:  src/arghandler.cpp include/arghandler.h
	$(CC) $(CCFLAGS) -c src/arghandler.cpp -o build/arghandler.o
clean:
	$(RM) build/*.o algochain
