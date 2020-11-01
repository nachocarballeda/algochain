IDIR =../include
CCFLAGS= -Wall -I$(IDIR)
CC= g++

all: algochain

algochain: main.o sha256.o cmdline.o block.o block_body.o block_header.o
	$(CC) $(CCFLAGS) -o algochain.bin build/main.o build/sha256.o build/cmdline.o build/block.o build/block_body.o build/block_header.o
	
main.o: main.cpp include/sha256.h include/cmdline.h
	$(CC) $(CCFLAGS) -c main.cpp -o build/main.o 

sha256.o: src/sha256.cpp include/sha256.h
	$(CC) $(CCFLAGS) -c src/sha256.cpp -o build/sha256.o 

cmdline.o: src/cmdline.cpp include/cmdline.h
	$(CC) $(CCFLAGS) -c src/cmdline.cpp -o build/cmdline.o 

block.o:  src/block.cpp include/block.h
	$(CC) $(CCFLAGS) -c src/block.cpp -o build/block.o

block_header.o:  src/block_header.cpp include/block_header.h
	$(CC) $(CCFLAGS) -c src/block_header.cpp -o build/block_header.o

block_body.o:  src/block_body.cpp include/block_body.h
	$(CC) $(CCFLAGS) -c src/block_body.cpp -o build/block_body.o


clean:
	$(RM) build/*.o algochain
