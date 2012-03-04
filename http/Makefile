CC = gcc
SRC = main.c
OBJ = $(SRC:%.c=%.o)
CFLAG = -g -2

.c.o:
	$(CC) $(CFLAG) -c $<

sock: $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@
.PHONY : clean
clean:
	@rm -rf *.o *~ sock
