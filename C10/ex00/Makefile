CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = ft_display_file
SRCS = main.c
OBJECTS = main.o

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(TARGET)