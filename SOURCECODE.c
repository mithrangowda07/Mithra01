#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>


#define MAX_ARGS 4
#define MAX_FILENAME 100
#define MAX_KEY_SIZE 32  // Change this for different key sizes (must be a multiple of 16)

// Function prototypes for file operations
int createFile(char *filename);
int deleteFile(char *filename);
int copyFile(char *srcFilename, char *destFilename);
int moveFile(char *srcFilename, char *destFilename);

// Function prototypes for text manipulation (operating on text files)
int toupperFile(char *filename);
int tolowerFile(char *filename);
int reverseFile(char *filename);
int removeSpacesFile(char *filename);
int countWordsFile(char *filename);

// Function prototypes for system information
void displaySystemStatus();
void displayDiskUsage();
void displayNetworkInfo();
void displayMemoryUsage();
void displayCPUInfo();

// Function prototypes for system maintenance (limited)
void rebootSystem();
void shutdownSystem();
void updateSystem();
void cleanSystem();

// Function prototypes for utilities
void clearScreen(); // Add this function to clear the screen

// Function prototypes for games
void guessNumberGame();
void rockPaperScissorsGame();

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc < 2 || argc > MAX_ARGS)  {
        printf("Usage: %s <command> [filename] [additional_argument]\n", argv[0]);
        printf("Available options:\n");
        printf("  File Operations:\n");
        printf("    create <filename> - Creates a new empty file.\n");
        printf("    delete <filename> - Deletes a file.\n");
        printf("    copy <source_filename> <destination_filename> - Copies a file.\n");
        printf("    move <source_filename> <destination_filename> - Moves a file.\n");
        printf("  Text Manipulation (on text files):\n");
        printf("    toupper <filename> - Converts text in a file to uppercase.\n");
        printf("    tolower <filename> - Converts text in a file to lowercase.\n");
        printf("    reverse <filename> - Reverses the order of characters in a file.\n");
        printf("    rmspaces <filename> - Removes spaces from text in a file.\n");
        printf("    countwords <filename> - Counts the number of words in a file.\n");
        printf("  System Information:\n");
        printf("    systemstatus - Displays system status (uptime and logged-in users).\n");
        printf("    diskusage - Displays disk usage.\n");
        printf("    networkinfo - Displays network information.\n");
        printf("    memoryusage - Displays memory usage.\n");
        printf("    cpuinfo - Displays CPU information.\n");
        printf("  System Maintenance:\n");
        printf("    reboot - Reboots the system (simulated).\n");
        printf("    shutdown - Shuts down the system (simulated).\n");
        printf("    update - Updates the system (simulated).\n");
        printf("    clean - Cleans the system (simulated).\n");
        printf("  Utilities:\n");
        printf("    clear - Clears the screen.\n");
        printf("  Games:\n");
        printf("    guessnumber - Play the guess the number game.\n");
        printf("    rockpaperscissors - Play rock-paper-scissors.\n");
        return 1;
    }

    char *command = argv[1];

    // File operations
    if (strcmp(command, "create") == 0) {
        if (argc != 3) {
            printf("Usage: create <filename>\n");
            return 1;
        }
        createFile(argv[2]);
    } 
    else if (strcmp(command, "delete") == 0) {
        if (argc != 3) {
            printf("Usage: delete <filename>\n");
            return 1;
        }
        deleteFile(argv[2]);
    } 
    else if (strcmp(command, "copy") == 0) {
    if (argc != 4) {
        printf("Usage: copy <source_filename> <destination_filename>\n");
        return 1;
    }
    copyFile(argv[2], argv[3]);
    }
    else if (strcmp(command, "move") == 0) {
    if (argc != 4) {
        printf("Usage: move <source_filename> <destination_filename>\n");
        return 1;
    }
    moveFile(argv[2], argv[3]);
} 


    // Text manipulation (operating on text files)
    else if (strcmp(command, "toupper") == 0) {
        if (argc != 3) {
            printf("Usage: toupper <filename>\n");
            return 1;
        }
        toupperFile(argv[2]);
    } 
    else if (strcmp(command, "tolower") == 0) {
        if (argc != 3) {
            printf("Usage: tolower <filename>\n");
            return 1;
        }
        tolowerFile(argv[2]);
    } 
    else if (strcmp(command, "reverse") == 0) {
        if (argc != 3) {
            printf("Usage: reverse <filename>\n");
            return 1;
        }
        reverseFile(argv[2]);
    } 
    else if (strcmp(command, "rmspaces") == 0) {
        if (argc != 3) {
            printf("Usage: rmspaces <filename>\n");
            return 1;
        }
        removeSpacesFile(argv[2]);
    } 
    else if (strcmp(command, "countwords") == 0) {
        if (argc != 3) {
            printf("Usage: countwords <filename>\n");
            return 1;
        }
        countWordsFile(argv[2]);
    } 
    // System information
    else if (strcmp(command, "systemstatus") == 0) {
        displaySystemStatus();
    } 
    else if (strcmp(command, "diskusage") == 0) {
        displayDiskUsage();
    } 
    else if (strcmp(command, "networkinfo") == 0) {
        displayNetworkInfo();
    } 
    else if (strcmp(command, "memoryusage") == 0) {
        displayMemoryUsage();
    } 
    else if (strcmp(command, "cpuinfo") == 0) {
        displayCPUInfo();
    } 
    // System maintenance
    else if (strcmp(command, "reboot") == 0) {
        rebootSystem();
    } 
    else if (strcmp(command, "shutdown") == 0) {
        shutdownSystem();
    } 
    else if (strcmp(command, "update") == 0) {
        updateSystem();
    } 
    else if (strcmp(command, "clean") == 0) {
        cleanSystem();
    } 
    // Utilities
    else if (strcmp(command, "clear") == 0) {
        clearScreen();
    } 
    // Games
    else if (strcmp(command, "guessnumber") == 0) {
        guessNumberGame();
    } 
    else if (strcmp(command, "rockpaperscissors") == 0) {
        rockPaperScissorsGame();
    }
    else {
               printf("Invalid command\n");

}


    return 0;
}




// Function implementations for file operations
int createFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        fclose(fp);
        printf("Error: File '%s' already exists.\n", filename);
        return 1;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file: %s\n", filename);
        return 1;
    }
    fclose(fp); // Close the file after creating it
    printf("File '%s' created successfully.\n", filename);
    return 0;
}


int deleteFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File '%s' does not exist.\n", filename);
        return 1;
    }
    fclose(fp);

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
        return 0;
    } else {
        printf("Error deleting file: %s\n", filename);
        return 1;
    }
}

int copyFile(char *srcFilename, char *destFilename) {
    FILE *srcFile = fopen(srcFilename, "rb");
    if (srcFile == NULL) {
        printf("Error opening source file: %s\n", srcFilename);
        return 1;
    }

    FILE *destFile = fopen(destFilename, "wb");
    if (destFile == NULL) {
        printf("Error creating destination file: %s\n", destFilename);
        fclose(srcFile);
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        if (fwrite(buffer, 1, bytesRead, destFile) != bytesRead) {
            printf("Error writing to destination file: %s\n", destFilename);
            fclose(srcFile);
            fclose(destFile);
            return 1;
        }
    }

    fclose(srcFile);
    fclose(destFile);

    printf("File '%s' copied to '%s' successfully.\n", srcFilename, destFilename);
    return 0;
}

#include <stdio.h>

int moveFile(char *srcFilename, char *destFilename) {
    int result = rename(srcFilename, destFilename);
    if (result != 0) {
        printf("Error moving file '%s' to '%s'\n", srcFilename, destFilename);
        return 1;
    }

    printf("File '%s' moved to '%s' successfully.\n", srcFilename, destFilename);
    return 0;
}


// Function implementations for text manipulation (operating on text files)
int toupperFile(char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    char *buffer = (char *)malloc(fileSize);

    if (buffer == NULL) {
        printf("Memory allocation error.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    fread(buffer, sizeof(char), fileSize, fp);

    for (int i = 0; i < fileSize; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    rewind(fp);
    fwrite(buffer, sizeof(char), fileSize, fp);

    free(buffer);
    fclose(fp);

    printf("Text in '%s' converted to uppercase.\n", filename);
    return 0;
}


int tolowerFile(char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    char *buffer = (char *)malloc(fileSize);

    if (buffer == NULL) {
        printf("Memory allocation error.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    fread(buffer, sizeof(char), fileSize, fp);

    for (int i = 0; i < fileSize; i++) {
        buffer[i] = tolower(buffer[i]);
    }

    rewind(fp);
    fwrite(buffer, sizeof(char), fileSize, fp);

    free(buffer);
    fclose(fp);

    printf("Text in '%s' converted to lowercase.\n", filename);
    return 0;
}

// Function implementations for text manipulation (operating on text files)
int reverseFile(char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    char *buffer = (char *)malloc(fileSize);

    if (buffer == NULL) {
        printf("Memory allocation error.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    fread(buffer, sizeof(char), fileSize, fp);

    for (int i = fileSize - 1; i >= 0; i--) {
        fseek(fp, i, SEEK_SET);
        fputc(buffer[fileSize - i - 1], fp);
    }

    free(buffer);
    fclose(fp);

    printf("Text in '%s' reversed successfully.\n", filename);
    return 0;
}

int removeSpacesFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return 1;
    }

    char ch;
    long spacesRemoved = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ') {
            fputc(ch, tempFile);
        } else {
            spacesRemoved++;
        }
    }

    fclose(fp);
    fclose(tempFile);

    remove(filename);            // Remove the original file
    rename("temp.txt", filename); // Rename the temporary file to the original filename

    printf("Removed %ld spaces from '%s'.\n", spacesRemoved, filename);
    return 0;
}


int countWordsFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int wordCount = 0;
    char word[MAX_FILENAME];
    char ch;

    while (fscanf(fp, "%s", word) == 1) {
        wordCount++;
    }

    fclose(fp);

    printf("Number of words in '%s': %d\n", filename, wordCount);
    return 0;
}

// Function implementations for system information
void displaySystemStatus() {
    printf("System Status\n");
    // Here you can implement code to display system status, e.g., using system commands like 'uptime' or 'who'.
    system("uptime");
    system("who");
}

void displayDiskUsage() {
    printf("Disk Usage\n");
    // Here you can implement code to display disk usage, e.g., using system commands like 'df'.
    system("df -h");
}

void displayNetworkInfo() {
    printf("Network Info\n");
    // Here you can implement code to display network information, e.g., using system commands like 'ifconfig'.
    system("ifconfig");
}

void displayMemoryUsage() {
    printf("Memory Usage\n");
    // Here you can implement code to display memory usage, e.g., using system commands like 'free'.
    system("free -m");
}

void displayCPUInfo() {
    printf("CPU Info\n");
    // Here you can implement code to display CPU information, e.g., using system commands like 'lscpu'.
    system("lscpu");
}

// Function implementations for system maintenance (limited)
void rebootSystem() {
    printf("Rebooting the system\n");
    // Here you can implement code to reboot the system, e.g., using system command like 'reboot'.
    system("reboot");
}

void shutdownSystem() {
    printf("Shutting down the system\n");
    // Here you can implement code to shut down the system, e.g., using system command like 'shutdown'.
    system("shutdown -h now");
}

void updateSystem() {
    printf("Updating the system\n");
    // Here you can implement code to update the system, e.g., using system command like 'apt update'.
    system("apt update");
    system("apt upgrade");
}

void cleanSystem() {
    printf("Cleaning the system\n");
    // Here you can implement code to clean the system, e.g., using system command like 'apt autoclean'.
    system("apt autoclean");
}

// Function implementations for utilities
void clearScreen() {
    printf("\033[2J\033[1;1H"); // ANSI escape sequence to clear screen
}

// Function implementations for games
void guessNumberGame() {
    srand(time(NULL));
    int numberToGuess = rand() % 100 + 1;
    int guess, attempts = 0;
    char input[100];

    printf("Welcome to the Guess the Number Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &guess);
        attempts++;

        if (guess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (guess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", numberToGuess, attempts);
        }
    } while (guess != numberToGuess);
}


void rockPaperScissorsGame() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    srand(time(NULL));

    printf("Welcome to the Rock-Paper-Scissors Game!\n");
    printf("Enter your choice (Rock, Paper, or Scissors): ");

    char input[100];
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    int isValidChoice = 0;
    int userChoiceIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(input, choices[i]) == 0) {
            isValidChoice = 1;
            userChoiceIndex = i;
            break;
        }
    }

    if (!isValidChoice) {
        printf("Invalid choice. Please enter either Rock, Paper, or Scissors.\n");
        return;
    }

    int computerChoice = rand() % 3;

    printf("You chose: %s\n", choices[userChoiceIndex]);
    printf("Computer chose: %s\n", choices[computerChoice]);

    if ((userChoiceIndex == 0 && computerChoice == 2) ||
        (userChoiceIndex == 1 && computerChoice == 0) ||
        (userChoiceIndex == 2 && computerChoice == 1)) {
        printf("Congratulations! You win!\n");
    } else if ((userChoiceIndex == 0 && computerChoice == 1) ||
               (userChoiceIndex == 1 && computerChoice == 2) ||
               (userChoiceIndex == 2 && computerChoice == 0)) {
        printf("Computer wins! Better luck next time.\n");
    } else {
        printf("It's a tie!\n");
    }
}

