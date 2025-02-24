#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_CMD_LENGTH 100 
#define MAX_ARGS 10 

// Funkce pro spuštění programu 
void run_program(char *program) { 
    char command[MAX_CMD_LENGTH]; 

    // Sestavení příkazu k provedení (například: ./Program1/Program1) 
    snprintf(command, sizeof(command), "./Program1/%s", program); 

    // Spuštění programu 
    if (system(command) == -1) { 
        printf("Chyba při spuštění programu %s\n", program); 
    } 
} 

// Funkce pro načítání a zpracování příkazu 
void process_input(char *input) { 
    char *args[MAX_ARGS]; 
    int arg_count = 0; 

    // Rozdělení vstupu na argumenty 
    char *token = strtok(input, " \t\n"); 
    while (token != NULL && arg_count < MAX_ARGS) { 
        args[arg_count++] = token; 
        token = strtok(NULL, " \t\n"); 
    } 

    // Pokud příkaz není prázdný 
    if (arg_count > 0) { 
        // Spuštění programu 
        run_program(args[0]); 
    } 
} 

int main() { 
    char input[MAX_CMD_LENGTH]; 

    // Hlavní smyčka 
    while (1) { 
        // Zobrazí prompt, podobný DOS 
        printf("C:\\> "); 

        // Načítání příkazu 
        if (fgets(input, sizeof(input), stdin) == NULL) { 
            continue;  // Pokud nastane chyba při načítání, pokračuj 
        } 

        // Pokud uživatel zadá příkaz 'exit', program se ukončí 
        if (strncmp(input, "exit", 4) == 0) { 
            break; 
        } 

        // Zpracování vstupu 
        process_input(input); 
    } 

    return 0; 
} 