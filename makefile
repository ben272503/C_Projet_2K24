# Variables
CC = gcc                 # Compilateur
CFLAGS = -Wall -Wextra   # Options de compilation pour afficher les avertissements
TARGET = test_morse      # Nom de l'exécutable
SRC = test_morse.c morse.c sleep.c   # Fichiers source
HEADERS = morse.h sleep.h const.h    # Fichiers d'en-tête

# Règle par défaut (l'exécutable)
$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)

# Règle pour exécuter les tests
run: $(TARGET)
	./$(TARGET)
