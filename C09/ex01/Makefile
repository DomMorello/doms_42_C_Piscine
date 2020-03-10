CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a
SRCDIR = srcs
INCLUDE = includes
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c -I$(INCLUDE) $(SRCS)
	ar rc $(TARGET) $(OBJECTS)
	mv $(OBJECTS) $(SRCDIR)

clean:
	RM $(OBJECTS)

fclean: clean
	RM $(TARGET)

re: fclean all