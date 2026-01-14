CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = student_result_processing_system

SRCS = main.c student.c validation.c file_io.c statistics.c display.c
OBJS = $(SRCS:.c=.o)
HDRS = constants.h student.h validation.h file_io.h statistics.h display.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	rm $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET) students_input.txt