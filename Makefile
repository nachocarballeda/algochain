IDIR =../include
CCFLAGS= -Wall -I$(IDIR)
CC= g++

all: algochain

algochain: main.o sha256.o cmdline.o block.o body.o header.o txns.o \
	inputs.o outputs.o outpoint.o
	$(CC) $(CCFLAGS) -o algochain.bin build/main.o build/sha256.o \
	build/cmdline.o build/txns.o build/block.o build/body.o build/header.o \
	build/inputs.o build/outputs.o build/outpoint.o
	
main.o: main.cpp include/sha256.h include/cmdline.h
	$(CC) $(CCFLAGS) -c main.cpp -o build/main.o 

sha256.o: src/sha256.cpp include/sha256.h
	$(CC) $(CCFLAGS) -c src/sha256.cpp -o build/sha256.o 

cmdline.o: src/cmdline.cpp include/cmdline.h
	$(CC) $(CCFLAGS) -c src/cmdline.cpp -o build/cmdline.o 

block.o:  src/block.cpp include/block.h
	$(CC) $(CCFLAGS) -c src/block.cpp -o build/block.o

header.o:  src/header.cpp include/header.h
	$(CC) $(CCFLAGS) -c src/header.cpp -o build/header.o

body.o:  src/body.cpp include/body.h
	$(CC) $(CCFLAGS) -c src/body.cpp -o build/body.o

txns.o:  src/txns.cpp include/txns.h
	$(CC) $(CCFLAGS) -c src/txns.cpp -o build/txns.o

inputs.o:  src/inputs.cpp include/inputs.h
	$(CC) $(CCFLAGS) -c src/inputs.cpp -o build/inputs.o

outputs.o:  src/outputs.cpp include/outputs.h
	$(CC) $(CCFLAGS) -c src/outputs.cpp -o build/outputs.o

outpoint.o:  src/outpoint.cpp include/outpoint.h
	$(CC) $(CCFLAGS) -c src/outpoint.cpp -o build/outpoint.o

clean:
	$(RM) build/*.o algochain
