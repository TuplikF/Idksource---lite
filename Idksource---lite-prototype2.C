#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <dirent.h> 
#include <unistd.h> 

#define MAX_CMD_LENGTH 128 
#define PROGRAM_DIR "./Programy" 

// Funkce pro čtení příkazového řádku 
void read_input(char *input) { 
    printf("DOS-like> "); 
    if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) { 
        perror("Chyba při čtení vstupu"); 
        exit(1); 
    } 

    // Odstranění nového řádku na konci 
    input[strcspn(input, "\n")] = 0; 
} 

// Funkce pro spuštění programu z adresáře 
void execute_program(const char *program_name) { 
    char path[256]; 
    snprintf(path, sizeof(path), "%s/%s", PROGRAM_DIR, program_name); 

    // Zkontrolujeme, jestli soubor existuje 
    if (access(path, X_OK) != -1) { 
        printf("Spouštím %s...\n", program_name); 
        if (system(path) == -1) { 
            perror("Chyba při spouštění programu"); 
        } 
    } else { 
        printf("Program '%s' nenalezen nebo nemá spustitelná práva.\n", program_name); 
    } 
} 

int main() { 
    char input[MAX_CMD_LENGTH]; 

    // Nekonečná smyčka příkazového řádku 
    while (1) { 
        read_input(input); 

        if (strcmp(input, "exit") == 0) { 
            printf("Ukončuji systém.\n"); 
            break; 
        } 

        // Pokud je zadaný příkaz, spustíme příslušný program 
        execute_program(input); 
    } 

    return 0; 
}