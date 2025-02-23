# Text Based Shell
### Project Title 

Text based shell 

  

### Description 

The provided source code represents a command-line utility that offers a comprehensive set of functionalities. Here's a brief overview of what the project does: 

  

This command-line utility provides users with a versatile toolkit for performing various tasks efficiently. It encompasses functionalities in the following categories: 

  

1. **File Operations:** Users can create, delete, copy, and move files using simple command-line commands. 

  

2. **Text Manipulation:** The utility allows users to manipulate text files by converting text to uppercase or lowercase, reversing the text order, removing spaces, and counting words within a file. 

  

3. **System Information:** Users can retrieve essential system information such as system status (uptime and logged-in users), disk usage, network information, memory usage, and CPU information. 

  

4. **System Maintenance:** Although simulated, the utility offers basic system maintenance operations like rebooting, shutting down, updating, and cleaning the system. 

  

5. **Utilities:** It provides utilities like clearing the screen for improved user experience. 

  

6. **Games:** Users can enjoy simple command-line games like "Guess the Number" and "Rock-Paper-Scissors" within the same environment. 

  

This project aims to offer a comprehensive and user-friendly command-line interface for performing common tasks, managing system resources, and even providing entertainment through simple games—all accessible through a single executable. 

  

### Features 

Based on the functionalities implemented in the provided source code, here are the key features of the project: 

  

1. **File Operations:** 

   - CreateDirectory: Users can create new empty directory.

   - MoveToDirectory: Users can move to respective directory.

   - MoveToHomeDirectory: Users can move to home directory.

   - Create: Users can create new empty files. 

   - Delete: Files can be deleted. 

   - Copy: Users can copy files from one location to another. 

   - Move: Files can be moved from one location to another. 

   - Listfiles: List all the files present in the directory.

   - PrintPresentDirectory: Prints the current directly being accessed.

  

2. **Text Manipulation:** 

   - Edit: Editing plain text or code files.

   - Convert to Uppercase: Text in a file can be converted to uppercase. 

   - Convert to Lowercase: Text in a file can be converted to lowercase. 

   - Reverse: The order of characters in a file can be reversed. 

   - Remove Spaces: Spaces from text in a file can be removed. 

   - Count Words: The number of words in a file can be counted. 

  

3. **System Information:** 

   - Display System Status: Users can view system status, including uptime and logged-in users. 

   - Display Disk Usage: Users can check disk usage. 

   - Display Network Information: Network information, such as configurations, can be displayed. 

   - Display Memory Usage: Users can view memory usage statistics. 

   - Display CPU Information: Users can see CPU information. 
   
   - Display Time: Display the current time of system.

   - Display Date: Display the current date of system.

  

4. **System Maintenance:** 

   - Reboot: Simulated rebooting of the system. 

   - Shutdown: Simulated shutting down of the system. 

   - Update: Simulated system update. 

   - Clean: Simulated system cleaning operation. 

  

5. **Utilities:** 

   - Clear Screen: Users can clear the terminal screen for better readability. 

   - Exit Screen: Users can exit the terminal.

  

6. **Games:** 

   - Guess the Number: Users can play a game where they try to guess a randomly generated number. 

   - Rock-Paper-Scissors: Users can play a text-based version of the classic game against the computer. 

  

These features collectively offer users a versatile command-line utility for managing files, manipulating text, accessing system information, performing basic system maintenance, using utilities for better interaction, and enjoying simple games—all within a single executable. 

  

### Usage 

To use the command-line utility provided by the source code, follow these instructions for each available command: 


0. **Help command:**

   - **Help:** Display all the command, use the command:

     ```

      help

     ```

     Example: `help`

    - **Command Help:** The system will display a help message for the command:
  
       ```
  
        <command> help
  
       ```
  
       Example: `<command> help`

1. **File Operations:** 

   - **CreateDirectory:** To create a new empty directory, use the command:

     ```

     createdir <directoryname>

     ```

     Example: ` createdir pi `

  
   - **MoveToDirectory:** To move to the respective directory, use the command:

     ```

     movetodir <directoryname>

     ```

     Example: ` movetodir pi`


   - **MovetoHomeDirectory:** To move to the home directory, use the command:

     ```

     homedir

     ```

     Example: ` homedir `

   - **Create:** To create a new empty file, use the command: 

     ``` 

     create <filename> 

     ``` 

     Example: ` create new_file.txt` 

  

   - **Delete:** To delete a file, use the command: 

     ``` 

     delete <filename> 

     ``` 

     Example: `delete old_file.txt` 

  

   - **Copy:** To copy a file from one location to another, use the command: 

     ``` 

     copy <source_filename> <destination_filename> 

     ``` 

     Example: `copy source.txt destination.txt` 

  

   - **Move:** To move a file from one location to another, use the command: 

     ``` 

     move <source_filename> <destination_filename> 

     ``` 

     Example: `move old_file.txt new_location/`

   - **Listfiles:** List all the files present in the directory, use the command:

     ```
    
     listfiles
    
     ```

     Example: `listfiles`


   - **PrintPresentWorkingDirectory:** Prints the current directly being accessed, use the command:

     ```

      presentdir


     ```

     Example: `presentdir`


2. **Text Manipulation:** 

   - **Edit:** Editing plain text or code files, use the command:
     ```

     edit <filename>

     ```

     Example: `edit first.txt`


   - **Convert to Uppercase:** To convert text in a file to uppercase, use the command: 

     ``` 

     toupper <filename> 

     ``` 

     Example: `toupper input.txt` 

  

   - **Convert to Lowercase:** To convert text in a file to lowercase, use the command: 

     ``` 

     tolower <filename> 

     ``` 

     Example: `tolower input.txt` 

  

   - **Reverse:** To reverse the order of characters in a file, use the command: 

     ``` 

     reverse <filename> 

     ``` 

     Example: `reverse text.txt` 

  

   - **Remove Spaces:** To remove spaces from text in a file, use the command: 

     ``` 

     rmspaces <filename> 

     ``` 

     Example: `rmspaces document.txt` 

  

   - **Count Words:** To count the number of words in a file, use the command: 

     ``` 

     countwords <filename> 

     ``` 

     Example: `countwords essay.txt` 

  

3. **System Information:** 

   - **System Status:** To display system status, use the command: 

     ``` 

     systemstatus 

     ``` 

  

   - **Disk Usage:** To display disk usage, use the command: 

     ``` 

     diskusage 

     ``` 

  

   - **Network Information:** To display network information, use the command: 

     ``` 

     networkinfo 

     ``` 

  

   - **Memory Usage:** To display memory usage, use the command: 

     ``` 

     memoryusage 

     ``` 

  

   - **CPU Information:** To display CPU information, use the command: 

     ``` 

     cpuinfo 

     ```

   - **Time:** Display the current time of system, use the command:
    
     ```

     time 

     ```

   - **Date:** Display the current date of system, use the command:
    
     ```

     date

     ```
  

4. **System Maintenance:** 

   - **Reboot:** To reboot the system, use the command: 

     ``` 

     reboot 

     ``` 

  

   - **Shutdown:** To shut down the system, use the command: 

     ``` 

     shutdown 

     ``` 

  

   - **Update:** To update the system, use the command: 

     ``` 

     update 

     ``` 

  

   - **Clean:** To clean the system, use the command: 

     ``` 

     clean 

     ``` 

  

5. **Utilities:** 

   - **Clear Screen:** To clear the screen, use the command: 

     ``` 

     clear 

     ``` 

   - **Exit Screen:** To exit the screen, use the command:
     ```

     exit

     ```

  

6. **Games:** 

   - **Guess the Number:** To play the guess the number game, use the command: 

     ``` 

     guessnumber 

     ``` 

  

   - **Rock-Paper-Scissors:** To play rock-paper-scissors, use the command: 

     ``` 

     rockpaperscissors 

     ``` 

  

Replace `<filename>` , `<directoryname>` and other placeholders with actual filenames or values as needed. These instructions cover how to use each command provided by the command-line utility. 

  

### Installation 

To install and run the command-line utility provided by the source code, follow these instructions: 

  

  

1. **Clone the Repository:** 

   - Clone the repository containing the source code to your local machine using Git: 

     ``` 

     git clone <repository_url> 

     ``` 

   - Alternatively, download the repository as a ZIP file and extract it to a directory on your local machine. 

  

2. **Compile the Program:** 

   - Navigate to the directory where the source code is located. 

   - Compile the program using a C compiler (e.g., GCC): 

     ``` 

     gcc -o program_name source_code.c 

     ``` 

   - Replace `program_name` with the desired name for the executable file. 

  

### Running the Program: 

  

Once the program is compiled, you can run it from the command line using the following syntax: 

  

``` 

./program_name 

``` 

  

Replace `program_name` with the name of the compiled executable file. 

  

### Examples: 

  

1. **Run a Command:** 

   - To create a new file named `new_file.txt`, run: 

     ``` 

     create new_file.txt 

     ``` 

  

2. **Perform Text Manipulation:** 

   - To convert the text in a file named `input.txt` to uppercase, run: 

     ``` 

     toupper input.txt 

     ``` 

  

3. **View System Information:** 

   - To display system status, run: 

     ``` 

     systemstatus 

     ``` 

  

4. **Play a Game:** 

   - To play the guess the number game, run: 

     ``` 

     guessnumber 

     ``` 

  

### Notes: 

- Ensure that you have necessary permissions to create, delete, and modify files in the specified directories. 

- Some commands may require superuser (root) privileges to execute certain system operations. 

- Make sure to provide valid filenames and additional arguments as required by each command. 

  

Follow these steps to install and run the command-line utility on your system. Adjust the instructions based on your specific operating system and environment. 

  

### Dependencies 

Based on the provided source code, the command-line utility does not appear to have any external dependencies beyond the standard C libraries. Therefore, there are no specific dependencies required to run the program. 

  

The program should compile and run on any system with a C compiler (such as GCC) and standard C libraries installed. As such, it should be compatible with most Unix-like operating systems (e.g., Linux, macOS) as well as Windows systems with a compatible C compiler environment (e.g., MinGW, Cygwin). 

  

Ensure that you have a C compiler installed on your system to compile the source code into an executable. Once compiled, the resulting executable should be able to run without any additional dependencies. 

  

   

  

## Contact Information 

 

For any questions, feedback, or inquiries about the project, please feel free to contact us at mithrangowda.is23@rvce.edu.in We welcome your input and look forward to hearing from you! 
