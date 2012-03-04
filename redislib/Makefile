CC = gcc
CFLAGS = -Wall -pipe -O2
OBJ = redis-cli.o
TARGET = rds
LDFLAGS = -L/usr/local/lib
INCLUDE = -I/usr/local/include
LIB = -lhiredis

all:
	make $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) $(LIB) $^ -o $@

redis-cli.o: redis-cli.c

.Phony: clean
clean:
	rm *.o $(TARGET)
