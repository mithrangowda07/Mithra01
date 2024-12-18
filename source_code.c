#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <limits.h>


#define MAX_ARGS 4
#define MAX_FILENAME 100
#define MAX_KEY_SIZE 32  // Change this for different key sizes (must be a multiple of 16)

// Function prototypes for file operations
int createDir(char *dirname);
int moveDir(char *dirname);
void changeToHomeDirectory();
int createFile(char *filename);
int deleteFile(char *filename);
int copyFile(char *srcFilename, char *destFilename);
int moveFile(char *srcFilename, char *destFilename);
void listfiles();
void printworkingdirectory();

// Function prototypes for text manipulation (operating on text files)
int gedit(char *filename);
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
void displaytime();
void displaydate();

// Function prototypes for system maintenance (limited)
void rebootSystem();
void shutdownSystem();
void updateSystem();
void cleanSystem();

// Function prototypes for utilities
void clearScreen(); // Add this function to clear the screen
int exitScreen();

// Function prototypes for games
void guessNumberGame();
void rockPaperScissorsGame();

int main() {
    srand(time(NULL));
    char commands[256];

    while (1) {
        printf("\033[0;33mShell $ \033[0m");
        if (fgets(commands, sizeof(commands), stdin) == NULL) {
            break;
        }
        commands[strcspn(commands, "\n")] = 0;

        char *tokens[10];  // Array to store tokens
        int i = 0;
        char *token = strtok(commands, " ");
        while (token != NULL && i < 10) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        tokens[i] = NULL;

        int argc1 = i;  // Store the number of tokens

        char *command = tokens[0];

        if (command == NULL) {
            continue;  // Skip empty commands
        }

        // Help command
        if (strcmp(command, "help") == 0) {
            printf("\n\033[1mUsage: <command> [filename] [additional_argument]\033[0m\n\n");
            printf("\033[1mAvailable options:\033[0m\n\n");


            printf("  \033[1mFile Operations:\033[0m\n");

            printf("    createdir <directoryname> - Create a new directory.\n");
            printf("    movetodir <directoryname> - Move to respective directory.\n");
            printf("    movetohomedir - Redirected to the home directory.\n");
            printf("    presentdir - Print the present directory.\n");
            printf("    create <filename> - Creates a new empty file.\n");
            printf("    delete <filename> - Deletes a file.\n");
            printf("    copy <source_filename> <destination_filename> - Copies a file.\n");
            printf("    move <source_filename> <destination_filename> - Moves a file.\n");
            printf("    listfiles  -list all the files present in the directory\n\n");


            printf("  \033[1mText Manipulation (on text files):\033[0m\n");

            printf("    edit <filename> - Editing plain text or code files.\n");
            printf("    toupper <filename> - Converts text in a file to uppercase.\n");
            printf("    tolower <filename> - Converts text in a file to lowercase.\n");
            printf("    reverse <filename> - Reverses the order of characters in a file.\n");
            printf("    rmspaces <filename> - Removes spaces from text in a file.\n");
            printf("    countwords <filename> - Counts the number of words in a file.\n\n");


            printf("  \033[1mSystem Information:\033[0m\n");

            printf("    systemstatus - Displays system status (uptime and logged-in users).\n");
            printf("    diskusage - Displays disk usage.\n");
            printf("    networkinfo - Displays network information.\n");
            printf("    memoryusage - Displays memory usage.\n");
            printf("    cpuinfo - Displays CPU information.\n");
            printf("    time - Display the current time\n");
            printf("    date - Display the current date\n\n");


            printf("  \033[1mSystem Maintenance:\033[0m\n");

            printf("    reboot - Reboots the system (simulated).\n");
            printf("    shutdown - Shuts down the system (simulated).\n");
            printf("    update - Updates the system (simulated).\n");
            printf("    clean - Cleans the system (simulated).\n\n");


            printf("  \033[1mUtilities:\033[0m\n");

            printf("    clear - Clears the screen.\n");
            printf("    exit - Exit the screen.\n\n");


            printf("  \033[1mGames:\033[0m\n");

            printf("    guessnumber - Play the guess the number game.\n");
            printf("    rockpaperscissors - Play rock-paper-scissors.\n\n");
            continue; // Go back to the prompt
        }

        // File operations
        else if (strcmp(command, "createdir") == 0) {
            if (argc1 != 2) {
                printf("Usage: createdir <directoryname>\n");
                continue;
            }
            createDir(tokens[1]);
        }
        else if (strcmp(command, "movetodir") == 0) {
            if (argc1 != 2) {
                printf("Usage: movedir <directoryname>\n");
                continue;
            }
            moveDir(tokens[1]);
        }
        else if (strcmp(command, "homedir") == 0) {
            if (argc1 != 1) {
                printf("Usage: homedir\n");
                continue;
            }
            changeToHomeDirectory();
        }
        else if (strcmp(command, "create") == 0) {
            if (argc1 != 2) {
                printf("Usage: create <filename>\n");
                continue;
            }
            createFile(tokens[1]);
        } 
        else if (strcmp(command, "delete") == 0) {
            if (argc1 != 2) {
                printf("Usage: delete <filename>\n");
                continue;
            }
            deleteFile(tokens[1]);
        } 
        else if (strcmp(command, "copy") == 0) {
            if (argc1 != 3) {
                printf("Usage: copy <source_filename> <destination_filename>\n");
                continue;
            }
            copyFile(tokens[1], tokens[2]);
        }
        else if (strcmp(command, "move") == 0) {
            if (argc1 != 3) {
                printf("Usage: move <source_filename> <destination_filename>\n");
                continue;
            }
            moveFile(tokens[1], tokens[2]);
        }
        else if (strcmp(command, "listfiles") == 0) {
            listfiles();
        }
        else if (strcmp(command, "presentdir") == 0) {
            printworkingdirectory();
        }

        // Text manipulation (operating on text files)
        else if (strcmp(command, "edit") == 0) {
            if (argc1 != 2) {
                printf("Usage: edit <filename>\n");
                continue;
            }
            gedit(tokens[1]);
        }
        else if (strcmp(command, "toupper") == 0) {
            if (argc1 != 2) {
                printf("Usage: toupper <filename>\n");
                continue;
            }
            toupperFile(tokens[1]);
        } 
        else if (strcmp(command, "tolower") == 0) {
            if (argc1 != 2) {
                printf("Usage: tolower <filename>\n");
                continue;
            }
            tolowerFile(tokens[1]);
        } 
        else if (strcmp(command, "reverse") == 0) {
            if (argc1 != 2) {
                printf("Usage: reverse <filename>\n");
                continue;
            }
            reverseFile(tokens[1]);
        } 
        else if (strcmp(command, "rmspaces") == 0) {
            if (argc1 != 2) {
                printf("Usage: rmspaces <filename>\n");
                continue;
            }
            removeSpacesFile(tokens[1]);
        } 
        else if (strcmp(command, "countwords") == 0) {
            if (argc1 != 2) {
                printf("Usage: countwords <filename>\n");
                continue;
            }
            countWordsFile(tokens[1]);
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
        else if (strcmp(command, "time") == 0) {
            displaytime();
        }
        else if (strcmp(command, "date") == 0) {
            displaydate();
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

        // Exit the program
        else if (strcmp(command, "exit") == 0) {
            exit(0);  // Exit the program
        }

        // Games
        else if (strcmp(command, "guessnumber") == 0) {
            guessNumberGame();
        } 
        else if (strcmp(command, "rockpaperscissors") == 0) {
            rockPaperScissorsGame();
        }

        // Invalid command
        else {
            printf("Error: Invalid command.\n");
            printf("Tip: Use 'help' to view the available commands.\n");
        }
    }
    return 0;
}




// Function implementations for file operations
int createDir(char *dirname){
    int status = mkdir(dirname, 0777); 

    if (status == 0) {
        printf("Directory '%s' created successfully.\n", dirname);
    } else {
        perror("Creatation of directory failed\n"); 
    }
    return 0;
}


int moveDir(char *dirname){
    if (chdir(dirname) == 0) {
        printf("Directory changed to '%s'.\n", dirname);
    } else {
        perror("Failed to change the directory\n");
    }

    return 0;
}


void changeToHomeDirectory() {
    // Change to the home directory using the environment variable HOME
    const char *home_dir = getenv("HOME");
    
    if (home_dir == NULL) {
        printf("Error: Could not find the home directory.\n");
        return;
    }

    if (chdir(home_dir) != 0) {
        perror("Error changing to home directory");
    } else {
        printf("Changed to home directory: %s\n", home_dir);
    }
}

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

void listfiles() {
    DIR *d;
    struct dirent *de;
    struct stat buf;
    int i, j;
    char P[10] = "rwxrwxrwx", AP[10] = " ";
    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];

    d = opendir(".");
    readdir(d);
    readdir(d);

    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &buf);

        // File Type
        if (S_ISDIR(buf.st_mode)) {
            printf("d");
        } else if (S_ISREG(buf.st_mode)) {
            printf("-");
        } else if (S_ISCHR(buf.st_mode)) {
            printf("c");
        } else if (S_ISBLK(buf.st_mode)) {
            printf("b");
        } else if (S_ISLNK(buf.st_mode)) {
            printf("l");
        } else if (S_ISFIFO(buf.st_mode)) {
            printf("p");
        } else if (S_ISSOCK(buf.st_mode)) {
            printf("s");
        }

        // File Permissions
        for (i = 0, j = (1 << 8); i < 9; i++, j >>= 1) {
            AP[i] = (buf.st_mode & j) ? P[i] : '-';
        }
        printf("%s", AP);

        // No. of Hard Links
        printf("%5ld", buf.st_nlink);

        // User Name
        p = getpwuid(buf.st_uid);
        printf(" %.8s", p->pw_name);

        // Group Name
        g = getgrgid(buf.st_gid);
        printf(" %-8.8s", g->gr_name);

        // File Size
        printf(" %8ld", buf.st_size);

        // Date and Time of modification
        t = localtime(&buf.st_mtime);
        strftime(time, sizeof(time), "%b %d %H:%M", t);
        printf(" %s", time);

        // File Name
        printf(" %s\n", de->d_name);
    }
}

void printworkingdirectory(){
    char cwd[PATH_MAX]; // Buffer to store the current working directory

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd); // Print the working directory
    } else {
        perror("getcwd() error"); // Print an error message if getcwd fails
    }
}

// Function implementations for text manipulation (operating on text files)
int gedit(char *filename){
    char command[256];
    snprintf(command, sizeof(command), "gedit %s", filename);

    // Use the system() function to execute the gedit command
    int ret = system(command);

    // Check if the system call was successful
    if (ret == -1) {
        perror("Error executing gedit");
        return 1;
    }

    return 0; // Successful execution
}


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

void displaytime(){
    time_t t;
    struct tm *current_time;

    // Get the current time
    t = time(NULL);
    current_time = localtime(&t);

    // Print the current time in HH:MM:SS format
    printf("Current Time: %02d:%02d:%02d\n", 
           current_time->tm_hour, 
           current_time->tm_min, 
           current_time->tm_sec);
}

void displaydate(){
    time_t t;
    struct tm *current_time;

    // Get the current time
    t = time(NULL);
    current_time = localtime(&t);

    // Print the current date in YYYY-MM-DD format
    printf("Current Date: %02d-%02d-%04d\n",
           current_time->tm_mday,  
           current_time->tm_mon + 1, // Months are 0-11, so add 1
           current_time->tm_year + 1900 // Year since 1900, so add 1900   
           );
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

int exitScreen() {
    printf("terminating the shell....\n");
    sleep(2);
    // Get the parent process ID (terminal process)
    pid_t ppid = getppid();

    // Send a signal to kill the parent process
    char command[256];
    snprintf(command, sizeof(command), "kill -9 %d", ppid);
    system(command);

    return 0;
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
