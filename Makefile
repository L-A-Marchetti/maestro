TARGET = maestro.o
BUILD = build
CC = gcc
SRC = src/maestro.c
FLAGS = -Wall -Wextra -Werror -pedantic -fstack-protector-strong

$(TARGET): $(SRC)
	@$(CC) $(FLAGS) -c $(SRC) -o $(BUILD)/$(TARGET)
	@ar rcs $(BUILD)/libmaestro.a $(BUILD)/$(TARGET)
	@rm $(BUILD)/$(TARGET)