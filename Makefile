# ===== CONFIG =====
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude -IZ:/SDL/x86_64-w64-mingw32/include
LDFLAGS = -LZ:/SDL/x86_64-w64-mingw32/lib -lSDL3

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = output/main.exe

# ===== BUILD =====
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# ===== COMPILAR CADA .c =====
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ===== LIMPIAR =====
clean:
	del /Q src\*.o 2>nul || rm -f src/*.o
	del /Q output\*.exe 2>nul || rm -f output/*.exe

# ===== REBUILD =====
rebuild: clean all

# ==== RUN ====

run: all
	$(TARGET)