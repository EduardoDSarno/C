CC      = gcc
CFLAGS  = -Wall -Wextra

SRCS    = client/main.c client/sync.c shared/checksum.c shared/pseIPHeader.c
OBJS    = $(SRCS:.c=.o)
TARGET  = tcp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

client/main.o: client/main.c client/header.h shared/helpers.h shared/pseIPHeader.h
client/sync.o: client/sync.c client/header.h shared/helpers.h shared/pseIPHeader.h
shared/checksum.o: shared/checksum.c shared/helpers.h shared/pseIPHeader.h
shared/pseIPHeader.o: shared/pseIPHeader.c shared/pseIPHeader.h

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	sudo ./$(TARGET)

.PHONY: all clean run
