CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror
LDFLAGS = -lcunit

SRC_DIR = src
SRC = joueuses.c personnages.c zones.c cartes.c interface.c main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

BIN_DIR = bin
EXEC = $(BIN_DIR)/jeu

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
