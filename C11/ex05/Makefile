CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = do-op
SRCS = main.c operator.c helper.c
OBJECTS = main.o operator.o helper.o

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(TARGET)