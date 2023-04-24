# Déclaration des variables
CC = gcc                     # Le compilateur utilisé est gcc
CFLAGS = -Wall -Wextra -Werror  # Les options de compilation (avertissements et erreurs)
LDFLAGS = -lcunit             # Les bibliothèques liées lors de la compilation (CUnit dans ce cas)

SRC_DIR = src                 # Le répertoire où se trouvent les fichiers source (.c)
SRC = test.c main.c  # Les fichiers source
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))  # Ajoute le préfixe du répertoire source aux fichiers source

OBJ_DIR = obj                 # Le répertoire où se trouvent les fichiers objet (.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))  # Remplace l'extension .c par .o et ajoute le préfixe du répertoire objet

BIN_DIR = bin                 # Le répertoire où se trouve l'exécutable
EXEC = $(BIN_DIR)/jeu         # Le nom de l'exécutable

# Règle par défaut (all) qui dépend de l'exécutable
all: $(EXEC)

# Règle pour générer l'exécutable à partir des fichiers objet
$(EXEC): $(OBJ)
    @mkdir -p $(BIN_DIR)      # Crée le répertoire bin s'il n'existe pas
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)  # Compile et lie les fichiers objet pour créer l'exécutable

# Règle générique pour créer un fichier objet à partir d'un fichier source
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)      # Crée le répertoire obj s'il n'existe pas
    $(CC) $(CFLAGS) -c $< -o $@  # Compile le fichier source en fichier objet

# Règle pour nettoyer les fichiers intermédiaires et l'exécutable
clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)  # Supprime les répertoires obj et bin

# Les cibles sans rapport avec les fichiers
.PHONY: all clean
