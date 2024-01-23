CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c queue.c
OBJS = $(SRCS:.c=.o)
TARGET = myprogram

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
