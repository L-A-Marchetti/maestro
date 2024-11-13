TARGET = maestro
BUILD = build
CC = gcc
SRC = src/main.c src/maestro.c
FLAGS = -Wall -Wextra -Werror -pedantic -fstack-protector-strong

$(TARGET): $(SRC)
	@$(CC) $(FLAGS) -o $(BUILD)/$(TARGET) $(SRC)
	@chmod +x $(BUILD)/$(TARGET)
	@./$(BUILD)/$(TARGET)