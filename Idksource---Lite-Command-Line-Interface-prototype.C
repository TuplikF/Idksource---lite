#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // Pro DOS specifické knihovny

#define MAX_FILES 100
#define FILENAME_LENGTH 100
#define FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int is_used;
} File;

File file_system[MAX_FILES];

// Inicializace file systému
void init_file_system() {
    for (int i = 0; i < MAX_FILES; i++) {
        file_system[i].is_used = 0;
    }
}

// Vytvoření souboru
int create_file(const char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!file_system[i].is_used) {
            strncpy(file_system[i].name, name, FILENAME_LENGTH);
            file_system[i].is_used = 1;
            return 0; // Úspěšně vytvořeno
        }
    }
    return -1; // File systém je plný
}

// Zápis do souboru
int write_file(const char *name, const char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used && strcmp(file_system[i].name, name) == 0) {
            strncpy(file_system[i].content, content, FILE_CONTENT_LENGTH);
            return 0; // Úspěšně zapsáno
        }
    }
    return -1; // Soubor nenalezen
}

// Čtení ze souboru
int read_file(const char *name, char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used && strcmp(file_system[i].name, name) == 0) {
            strncpy(content, file_system[i].content, FILE_CONTENT_LENGTH);
            return 0; // Úspěšně přečteno
        }
    }
    return -1; // Soubor nenalezen
}

// Smazání souboru
int delete_file(const char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used && strcmp(file_system[i].name, name) == 0) {
            file_system[i].is_used = 0;
            return 0; // Úspěšně smazáno
        }
    }
    return -1; // Soubor nenalezen
}

// Zobrazení seznamu souborů
void list_files() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used) {
            printf("%s\n", file_system[i].name);
        }
    }
}

// Command line interface
void command_line_interface() {
    char command[50];
    char name[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];

    while (1) {
        printf("DOS> ");
        gets(command);

        if (strncmp(command, "create", 6) == 0) {
            sscanf(command, "create %s", name);
            if (create_file(name) == 0) {
                printf("Soubor '%s' byl vytvořen.\n", name);
            } else {
                printf("Nelze vytvořit soubor.\n");
            }
        } else if (strncmp(command, "write", 5) == 0) {
            sscanf(command, "write %s %[^\n]", name, content);
            if (write_file(name, content) == 0) {
                printf("Data byla zapsána do souboru '%s'.\n", name);
            } else {
                printf("Nelze zapsat do souboru.\n");
            }
        } else if (strncmp(command, "read", 4) == 0) {
            sscanf(command, "read %s", name);
            if (read_file(name, content) == 0) {
                printf("Obsah souboru '%s': %s\n", name, content);
            } else {
                printf("Nelze číst soubor.\n");
            }
        } else if (strncmp(command, "delete", 6) == 0) {
            sscanf(command, "delete %s", name);
            if (delete_file(name) == 0) {
                printf("Soubor '%s' byl smazán.\n", name);
            } else {
                printf("Nelze smazat soubor.\n");
            }
        } else if (strncmp(command, "list", 4) == 0) {
            list_files();
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else {
            printf("Neznámý příkaz.\n");
        }
    }
}

int main() {
    init_file_system();
    command_line_interface();
    return 0;
}
