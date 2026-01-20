CC = gcc
CFLAGS = -std=c89 -Wall -Wextra -Werror -pedantic -Iinclude
TARGET = quango
OBJS = main.o board.o moves.o render.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
