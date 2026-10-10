CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude

TARGET = build/programma.exe
OBJ = build/main.o build/funzioni.o

.PHONY: all clean

all: $(TARGET)

build:
	mkdir build

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/main.o: src/main.c include/funzioni.h | build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/funzioni.o: src/funzioni.c include/funzioni.h | build
	$(CC) $(CFLAGS) -c src/funzioni.c -o build/funzioni.o

clean:
	del /Q build\*.o build\*.exe 2>nul