codCC = gcc
CFLAGS = -Wall -I.
TARGET = mine_sweeper
SRCS = generate_grid.c

all: $(TARGET)

$(TARGET): mine_sweeper.c $(SRCS)

	$(CC) $(CFLAGS) -o $(TARGET) mine_sweeper.c $(SRCS)

clean:
	rm -f $(TARGET)
