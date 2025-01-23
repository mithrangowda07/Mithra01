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
            if (strcmp(tokens[1], "help") == 0){
        		printf("1. The 'createdir' command is used to create new directories.\n");
				printf("2. Syntax: createdir [options] directory-name(s)\n");
				printf("3. Use 'createdir -p' to create parent directories if they don't exist.\n");
				printf("4. Example: 'createdir my_folder' creates a directory named 'my_folder'.\n");
				printf("5. Use 'createdir -v' to display a message for each directory created.\n");
        	}
        	else createDir(tokens[1]);
        }
        else if (strcmp(command, "movetodir") == 0) {
            if (argc1 != 2) {
                printf("Usage: movedir <directoryname>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
        		printf("1. The 'movetodir' command is used to change the current directory.\n");
				printf("2. Syntax: movetodir [directory-path]\n");
				printf("3. To move to the parent directory, use 'movetodir ..'.\n");
				printf("4. Use 'movetodir' without arguments to return to the home directory.\n");
				printf("5. Use absolute paths (e.g., '/home/user') or relative paths (e.g., './folder') with 'movetodir'.\n");
        	}
            else moveDir(tokens[1]);
        }
        else if (strcmp(command, "homedir") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'homedir' command is used to change the current directory.\n");
				printf("2. Syntax: homedir\n");
				printf("3. To move to the parent directory, use 'homedir ..'.\n");
				printf("4. Use 'homedir' without arguments to return to the home directory.\n");
				printf("5. Use absolute paths (e.g., '/home/user') or relative paths (e.g., './folder') with 'homedir'.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: homedir\n");
                continue;
            }
            else changeToHomeDirectory();
        }
        else if (strcmp(command, "create") == 0) {
            if (argc1 != 2) {
                printf("Usage: create <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
        		printf("1. Use the 'create' command to create an empty file.\n");
                printf("2. Syntax: create [file-name]\n");
                printf("3. Example: 'create myfile.txt' creates an empty file named 'myfile.txt'.\n");
                printf("4. If 'myfile.txt' already exists, 'create' updates its timestamp.\n");
                printf("5. This method is simple and efficient for creating files.\n");
        	}
            else createFile(tokens[1]);
        } 
        else if (strcmp(command, "delete") == 0) {
            if (argc1 != 2) {
                printf("Usage: delete <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. To delete a file, use the 'delete' command.\n");
                printf("2. Syntax: delete [file-name]\n");
                printf("3. Example: 'delete myfile.txt' deletes the file named 'myfile.txt'.\n");
                printf("4. Use 'delete -i myfile.txt' to get a confirmation prompt before deleting.\n");
                printf("5. Warning: Deleting a file with 'delete' is permanent and cannot be undone.\n");
            }
            else deleteFile(tokens[1]);
        } 
        else if (strcmp(command, "copy") == 0) {
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'copy' command is used to copy files or directories.\n");
                printf("2. Syntax: copy [options] source destination\n");
                printf("3. Use 'copy -r' to copy directories recursively.\n");
                printf("4. Example: 'copy file1.txt /destination/' copies file1.txt to the destination folder.\n");
                printf("5. Use 'copy -i' to prompt before overwriting files.\n");
            }
            else if (argc1 != 3) {
                printf("Usage: copy <source_filename> <destination_filename>\n");
                continue;
            }
            else copyFile(tokens[1], tokens[2]);
        }
        else if (strcmp(command, "move") == 0) {
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'move' command is used to move or rename files and directories.\n");
                printf("2. Syntax: move [source] [destination]\n");
                printf("3. Example to move: 'move myfile.txt /home/user/' moves 'myfile.txt' to '/home/user/'.\n");
                printf("4. Example to rename: 'move old_name.txt new_name.txt' renames the file.\n");
                printf("5. Warning: Be careful while overwriting files with the same name in the destination.\n");
            }
            else if (argc1 != 3) {
                printf("Usage: move <source_filename> <destination_filename>\n");
                continue;
            }
            else moveFile(tokens[1], tokens[2]);
        }
        else if (strcmp(command, "listfiles") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'listfiles' command is used to list the contents of a directory.\n");
                printf("2. Syntax: listfiles [options] [directory-path]\n");
                printf("3. Use 'listfiles -l' to display detailed information about files and directories.\n");
                printf("4. Use 'listfiles -a' to show hidden files.\n");
                printf("5. Use 'listfiles /path/to/directory' to list files in a specific directory.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: listfiles\n");
                continue;
            }
            else listfiles();
        }
        else if (strcmp(command, "presentdir") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'presentdir' command displays the current working directory.\n");
                printf("2. Syntax: presentdir\n");
                printf("3. It shows the full absolute path of the current directory.\n");
                printf("4. Use it to verify the directory before running commands like 'cd'.\n");
                printf("5. It is useful in shell scripts to log the current directory.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: presentdir\n");
                continue;
            }
            else printworkingdirectory();
        }

        // Text manipulation (operating on text files)
        else if (strcmp(command, "edit") == 0) {
            if (argc1 != 2) {
                printf("Usage: edit <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
        		printf("1. The 'edit' command opens a text editor for creating or editing files.\n");
                printf("2. Syntax: edit [file-name]\n");
                printf("3. Example: 'edit myfile.txt' opens or creates a file named 'myfile.txt'.\n");
                printf("4. Use 'edit &' to open it in the background while keeping the terminal usable.\n");
                printf("5. 'edit' is part of GNOME and requires a graphical environment to run.\n");
        	}
            else gedit(tokens[1]);
        }
        else if (strcmp(command, "toupper") == 0) {
            if (argc1 != 2) {
                printf("Usage: toupper <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'toupper' functionality is used to convert all text in a file to uppercase.\n");
                printf("2. Read the file specified by <filename>.\n");
                printf("3. Convert each character to uppercase using the 'toupper()' function from ctype.h.\n");
                printf("4. Save the result back to the file or to a new file.\n");
                printf("5. Example: 'toupper input.txt' reads 'input.txt' and converts its contents to uppercase.\n");
            }
            else toupperFile(tokens[1]);
        } 
        else if (strcmp(command, "tolower") == 0) {
            if (argc1 != 2) {
                printf("Usage: tolower <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'tolower' functionality is used to convert all text in a file to lowercase.\n");
                printf("2. Read the file specified by <filename>.\n");
                printf("3. Convert each character to lowercase using the 'tolower()' function from ctype.h.\n");
                printf("4. Save the result back to the file or to a new file.\n");
                printf("5. Example: 'tolower input.txt' reads 'input.txt' and converts its contents to lowercase.\n");
            }
            else tolowerFile(tokens[1]);
        } 
        else if (strcmp(command, "reverse") == 0) {
            if (argc1 != 2) {
                printf("Usage: reverse <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'reverse' functionality is used to reverse the content of a file.\n");
                printf("2. Read the file specified by <filename> line by line or as a whole.\n");
                printf("3. Reverse the text content (character-wise or line-wise) using appropriate logic.\n");
                printf("4. Save the reversed content back to the file or to a new file.\n");
                printf("5. Example: 'reverse input.txt' reads 'input.txt' and reverses its contents.\n");
            }
            else reverseFile(tokens[1]);
        } 
        else if (strcmp(command, "rmspaces") == 0) {
            if (argc1 != 2) {
                printf("Usage: rmspaces <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'rmspaces' functionality is used to remove all spaces from a file's content.\n");
                printf("2. Read the file specified by <filename> line by line.\n");
                printf("3. Remove all spaces (' ') from each line using appropriate logic (e.g., skipping spaces).\n");
                printf("4. Save the updated content back to the file or to a new file.\n");
                printf("5. Example: 'rmspaces input.txt' processes 'input.txt' and removes all spaces from its content.\n");
            }
            else removeSpacesFile(tokens[1]);
        } 
        else if (strcmp(command, "countwords") == 0) {
            if (argc1 != 2) {
                printf("Usage: countwords <filename>\n");
                continue;
            }
            if (strcmp(tokens[1], "help") == 0){
                printf("1. The 'countwords' functionality is used to count the total number of words in a file.\n");
                printf("2. Read the file specified by <filename> line by line.\n");
                printf("3. Split the content into words using spaces, tabs, or newline characters as delimiters.\n");
                printf("4. Count each word and keep a running total.\n");
                printf("5. Example: 'countwords input.txt' reads 'input.txt' and displays the total number of words.\n");
            }
            else countWordsFile(tokens[1]);
        } 

        // System information
        else if (strcmp(command, "systemstatus") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'systemstatus' functionality provides an overview of the system's current state.\n");
                printf("2. This includes information such as CPU usage, memory usage, disk space, and uptime.\n");
                printf("3. Common commands for checking system status:\n");
                printf("   - 'top': Displays real-time system performance.\n");
                printf("   - 'free -h': Shows memory usage in human-readable format.\n");
                printf("   - 'df -h': Displays disk space usage.\n");
                printf("   - 'uptime': Shows how long the system has been running.\n");
                printf("4. Example: Running 'systemstatus' could combine these commands to show a detailed summary.\n");
                printf("5. This command helps monitor system health and troubleshoot performance issues.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: systemstatus\n");
                continue;
            }
            else displaySystemStatus();
        } 
        else if (strcmp(command, "diskusage") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'diskusage' functionality provides information about disk space usage on the system.\n");
                printf("2. Common command: 'df' (disk free).\n");
                printf("3. Syntax: 'df [options]'\n");
                printf("   - 'df -h': Displays disk usage in human-readable format (e.g., GB, MB).\n");
                printf("   - 'df -T': Shows disk usage along with filesystem types.\n");
                printf("   - 'df -i': Displays inode usage.\n");
                printf("4. Example: 'diskusage' could internally run 'df -h' to summarize available and used disk space.\n");
                printf("5. Use this command to monitor and manage disk storage effectively.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: diskusage\n");
                continue;
            }
            else displayDiskUsage();
        } 
        else if (strcmp(command, "networkinfo") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'networkinfo' functionality provides details about the network interfaces and their statuses.\n");
                printf("2. Common commands to gather network information:\n");
                printf("   - 'ifconfig' or 'ip a': Displays network interfaces and their IP addresses.\n");
                printf("   - 'ping <hostname>': Checks connectivity to a host (e.g., 'ping google.com').\n");
                printf("   - 'netstat -tuln': Lists active network connections and listening ports.\n");
                printf("   - 'traceroute <hostname>': Traces the route packets take to a host.\n");
                printf("   - 'nslookup <domain>': Resolves domain names to IP addresses.\n");
                printf("3. Example: 'networkinfo' could internally run 'ifconfig' or 'ip a' to display current IP configurations.\n");
                printf("4. Use this command to troubleshoot network issues or monitor connectivity.\n");
                printf("5. Requires proper permissions or administrator privileges for some commands.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: networkinfo\n");
                continue;
            }
            else displayNetworkInfo();
        } 
        else if (strcmp(command, "memoryusage") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'memoryusage' functionality provides details about the system's memory (RAM) usage.\n");
                printf("2. Common commands to check memory usage:\n");
                printf("   - 'free -h': Displays total, used, and available memory in human-readable format (e.g., GB, MB).\n");
                printf("   - 'vmstat': Shows memory usage along with other system performance metrics.\n");
                printf("   - 'top': Provides real-time memory and CPU usage for processes.\n");
                printf("   - 'cat /proc/meminfo': Displays detailed memory information from the system file.\n");
                printf("3. Example: 'memoryusage' could internally run 'free -h' to show an easy-to-read summary of memory usage.\n");
                printf("4. Use this command to monitor available memory and troubleshoot system performance issues.\n");
                printf("5. Requires no additional privileges to run these commands.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: memoryusage\n");
                continue;
            }
            else displayMemoryUsage();
        } 
        else if (strcmp(command, "cpuinfo") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'cpuinfo' functionality provides detailed information about the system's CPU.\n");
                printf("2. Common commands to gather CPU information:\n");
                printf("   - 'lscpu': Displays an overview of CPU architecture, cores, threads, and speed.\n");
                printf("   - 'cat /proc/cpuinfo': Provides detailed information for each CPU core.\n");
                printf("   - 'top' or 'htop': Shows real-time CPU usage and process information.\n");
                printf("   - 'nproc': Displays the number of available processing units.\n");
                printf("3. Example: 'cpuinfo' could internally execute 'lscpu' to summarize the CPU's specifications.\n");
                printf("4. Use this command to monitor and understand the system's processor performance and capabilities.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: cpuinfo\n");
                continue;
            }
            else displayCPUInfo();
        }
        else if (strcmp(command, "time") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'time' functionality provides the current system time and date.\n");
                printf("2. Common commands to get the current time:\n");
                printf("   - 'date': Displays the current date and time in the system's timezone.\n");
                printf("   - 'timedatectl': Provides detailed time settings, including timezone and synchronization status.\n");
                printf("3. Syntax:\n");
                printf("   - Running 'time' will display the current system time.\n");
                printf("4. Example: 'time' could internally run the 'date' command to display the current time in HH:MM:SS format.\n");
                printf("5. Use this command to check the current time or troubleshoot time-related configurations.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: time\n");
                continue;
            }
            else displaytime();
        }
        else if (strcmp(command, "date") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'date' functionality provides the current system date and time.\n");
                printf("2. Common commands to get or set the date:\n");
                printf("   - 'date': Displays the current date and time in the system's timezone.\n");
                printf("   - 'date +\"%%Y-%%m-%%d\"': Shows the date in YYYY-MM-DD format.\n");
                printf("   - 'date +\"%%T\"': Displays only the current time (HH:MM:SS).\n");
                printf("3. To set the date (requires admin privileges):\n");
                printf("   - Syntax: 'date MMDDhhmmYYYY.ss'\n");
                printf("   - Example: 'date 012312452025.00' sets the date to January 23, 2025, 12:45:00.\n");
                printf("4. Example: Running 'date' will display the full current date and time.\n");
                printf("5. Use this command to check the system's current date or adjust it if needed.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: date\n");
                continue;
            }
            else displaydate();
        }

        // System maintenance
        else if (strcmp(command, "reboot") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'reboot' command is used to restart the system.\n");
                printf("2. Common scenarios for using 'reboot':\n");
                printf("   - To apply system updates.\n");
                printf("   - To resolve system performance issues.\n");
                printf("   - To restart after changes in hardware or software configurations.\n");
                printf("3. Requires superuser privileges to execute (e.g., 'sudo reboot').\n");
                printf("4. Example: Simply typing 'reboot' will initiate a restart of the system.\n");
                printf("5. Warning: Always ensure unsaved work is saved before using this command.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: reboot\n");
                continue;
            }
            else rebootSystem();
        } 
        else if (strcmp(command, "shutdown") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'shutdown' command is used to power off or restart the system safely.\n");
                printf("2. Common options for 'shutdown':\n");
                printf("   - 'shutdown now': Immediately powers off the system.\n");
                printf("   - 'shutdown -h <time>': Schedules a system halt at the specified time (e.g., 'shutdown -h +10' shuts down in 10 minutes).\n");
                printf("   - 'shutdown -r': Reboots the system instead of powering it off.\n");
                printf("3. Requires superuser privileges to execute (e.g., 'sudo shutdown').\n");
                printf("4. Example: Running 'shutdown -h now' will turn off the system immediately.\n");
                printf("5. Warning: Always ensure unsaved work is saved before using this command.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: shutdown\n");
                continue;
            }
            else shutdownSystem();
        } 
        else if (strcmp(command, "update") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'update' functionality is typically used to update the system's package list and software packages.\n");
                printf("2. Common commands for updating software packages:\n");
                printf("   - 'sudo apt update': Updates the list of available packages (for Debian-based systems like Ubuntu).\n");
                printf("   - 'sudo apt upgrade': Upgrades installed packages to their latest versions.\n");
                printf("   - 'sudo dnf update': Updates all packages on Red Hat-based systems.\n");
                printf("   - 'sudo pacman -Syu': Updates the system on Arch Linux.\n");
                printf("3. Running 'update' alone may refer to updating the package list or the entire system, depending on the distribution.\n");
                printf("4. Example: 'sudo apt update' fetches the latest package information from configured repositories.\n");
                printf("5. It's important to update regularly to ensure security patches and improvements are applied.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: update\n");
                continue;
            }
            else updateSystem();
        } 
        else if (strcmp(command, "clean") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'clean' functionality is typically used to remove unnecessary package files and free up disk space.\n");
                printf("2. Common commands for cleaning up package files:\n");
                printf("   - 'sudo apt clean': Removes downloaded package files that are no longer needed (for Debian-based systems like Ubuntu).\n");
                printf("   - 'sudo apt autoremove': Removes unused packages and dependencies that are no longer needed.\n");
                printf("   - 'sudo dnf clean all': Cleans up cached package data on Red Hat-based systems.\n");
                printf("   - 'sudo pacman -Rns $(pacman -Qdtq)': Removes unused packages and their dependencies on Arch Linux.\n");
                printf("3. Running 'clean' can help free up space by removing cached and unnecessary files.\n");
                printf("4. Example: 'sudo apt clean' will remove the local cache of downloaded packages.\n");
                printf("5. It's recommended to clean periodically to maintain disk space and system performance.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: clean\n");
                continue;
            }
            else cleanSystem();
        } 

        // Utilities
        else if (strcmp(command, "clear") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'clear' command is used to clear the terminal screen.\n");
                printf("2. It removes all previous text and outputs, providing a clean workspace in the terminal.\n");
                printf("3. This command does not delete any data, it simply scrolls the terminal display.\n");
                printf("4. Example: Running 'clear' will instantly clear all text from the terminal window.\n");
                printf("5. The 'clear' command can be used frequently to maintain a tidy terminal window during long sessions.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: clear\n");
                continue;
            }
            else clearScreen();
        }

        // Exit the program
        else if (strcmp(command, "exit") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'exit' command is used to terminate a shell session or program.\n");
                printf("2. It closes the current terminal window or logs the user out of a session.\n");
                printf("3. The 'exit' command can also take an optional exit status code, where '0' generally indicates success and non-zero values indicate errors.\n");
                printf("   - Syntax: 'exit [status]'\n");
                printf("4. Example: Running 'exit' will close the terminal session, or 'exit 1' will terminate with an error status.\n");
                printf("5. The 'exit' command is commonly used in scripts to end execution or after completing tasks in the shell.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: exit\n");
                continue;
            }
            else exit(0);  // Exit the program
        }

        // Games
        else if (strcmp(command, "guessnumber") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'guessnumber' functionality is a game or program where the user is prompted to guess a number within a specified range.\n");
                printf("2. Common implementation includes the following steps:\n");
                printf("   - The system randomly selects a number.\n");
                printf("   - The user is asked to input guesses.\n");
                printf("   - After each guess, the system informs the user whether the guess was too high, too low, or correct.\n");
                printf("3. Syntax:\n");
                printf("   - A common format for the command could be: 'guessnumber [min] [max]'\n");
                printf("   - Example: 'guessnumber 1 100' would prompt the user to guess a number between 1 and 100.\n");
                printf("4. Example: If the system selects 42, the user would input guesses, and after each guess, the system gives feedback.\n");
                printf("5. This command is often used for simple game implementations or as a practice for input validation and loops in programming.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: guessnumber\n");
                continue;
            }
            else guessNumberGame();
        } 
        else if (strcmp(command, "rockpaperscissors") == 0) {
            if (tokens[1] && strcmp(tokens[1], "help") == 0){
        		printf("1. The 'rockpaperscissors' functionality implements the classic game between two players: one choosing Rock, Paper, or Scissors.\n");
                printf("2. Common rules of the game:\n");
                printf("   - Rock beats Scissors.\n");
                printf("   - Scissors beat Paper.\n");
                printf("   - Paper beats Rock.\n");
                printf("3. The game can be played between two users or with the computer generating a random choice.\n");
                printf("4. Example:\n");
                printf("   - Player 1 selects Rock and the computer selects Scissors. Player 1 wins.\n");
                printf("   - Player 2 selects Paper and Player 1 selects Rock. Player 2 wins.\n");
                printf("5. The 'rockpaperscissors' game is a great exercise for learning about conditionals, loops, and user input in programming.\n");
        	}
            else if (argc1 != 1) {
                printf("Usage: rockpaperscissors\n");
                continue;
            }
            else rockPaperScissorsGame();
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
