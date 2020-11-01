IDIR =../include
CCFLAGS= -Wall -I$(IDIR)
CC= g++

all: algochain

algochain: main.o sha256.o cmdline.o
	$(CC) $(CCFLAGS) -o algochain build/main.o build/sha256.o build/cmdline.o
	
main.o: main.cpp include/sha256.h include/cmdline.h
	$(CC) $(CCFLAGS) -c main.cpp -o build/main.o 

sha256.o: src/sha256.cpp include/sha256.h
	$(CC) $(CCFLAGS) -c src/sha256.cpp -o build/sha256.o 

cmdline.o: src/cmdline.cpp include/cmdline.h
	$(CC) $(CCFLAGS) -c src/cmdline.cpp -o build/cmdline.o 

clean:
	$(RM) build/*.o algochain
