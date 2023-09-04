#include <stdio.h>
#include <stdlib.h>
//  you may need other standard header files


//  CITS2002 Project 1 2023
//  Student1:   23443635  Vittorio Panaia
//  Student2:   STUDENT-NUMBER2   Leon Thomas


//  myscheduler (v1.0)
//  Compile with:  cc -std=c11 -Wall -Werror -o myscheduler myscheduler.c

`
//  THESE CONSTANTS DEFINE THE MAXIMUM SIZE OF sysconfig AND command DETAILS
//  THAT YOUR PROGRAM NEEDS TO SUPPORT.  YOU'LL REQUIRE THESE //  CONSTANTS
//  WHEN DEFINING THE MAXIMUM SIZES OF ANY REQUIRED DATA STRUCTURES.

#define MAX_DEVICES                     4
#define MAX_DEVICE_NAME                 20
#define MAX_COMMANDS                    10
#define MAX_COMMAND_NAME                20
#define MAX_SYSCALLS_PER_PROCESS        40
#define MAX_RUNNING_PROCESSES           50

//  NOTE THAT DEVICE DATA-TRANSFER-RATES ARE MEASURED IN BYTES/SECOND,
//  THAT ALL TIMES ARE MEASURED IN MICROSECONDS (usecs),
//  AND THAT THE TOTAL-PROCESS-COMPLETION-TIME WILL NOT EXCEED 2000 SECONDS
//  (SO YOU CAN SAFELY USE 'STANDARD' 32-BIT ints TO STORE TIMES).

#define DEFAULT_TIME_QUANTUM            100

#define TIME_CONTEXT_SWITCH             5
#define TIME_CORE_STATE_TRANSITIONS     10
#define TIME_ACQUIRE_BUS                20


//  ----------------------------------------------------------------------

#define CHAR_COMMENT                    '#'

void read_sysconfig(char argv0[], char filename[])
{
    FILE *fptr;
    fptr = fopen(filename, "r");
    
}

void read_commands(char argv0[], char filename[])
{

}

//  ----------------------------------------------------------------------

void execute_commands(void)
{
    Process* process = (Process*)arg;
    
    // Simulate execution, I/O, sleep, and waiting
    // You would need to implement the logic for each state transition here
    
    // Example: Simulate execution for a certain time quantum
    if (process->remainingTimeQuantum > 0) {
        process->state = 'R'; // Set state to Ready
        process->remainingTimeQuantum--;
    } else {
        // Time quantum expired, switch to the next process
        // ...
    }
    
    // Example: Simulate I/O operation
    if (process->state == 'B') {
        // Process is blocked, check if the I/O device is available
        if (!ioDevices[process->ioDevice].busy) {
            // Assign the I/O device to the process
            ioDevices[process->ioDevice].busy = true;
            ioDevices[process->ioDevice].currentProcessId = process->id;
            // Simulate I/O operation
            // ...
        }
    }
    
    // Example: Simulate sleep
    if (process->state == 'S' && process->sleepTime > 0) {
        sleep(process->sleepTime);
        process->state = 'R'; // Set state to Ready after sleep
    }
    
    // Example: Simulate waiting for child processes
    if (process->state == 'W') {
        // Check if all child processes have terminated
        // ...
    }
    
    return NULL;
}

//  ----------------------------------------------------------------------

int main(int argc, char *argv[])
{
//  ENSURE THAT WE HAVE THE CORRECT NUMBER OF COMMAND-LINE ARGUMENTS
    if(argc != 3) {
        printf("Usage: %s sysconfig-file command-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

//  READ THE SYSTEM CONFIGURATION FILE
    read_sysconfig(argv[0], argv[1]);

//  READ THE COMMAND FILE
    read_commands(argv[0], argv[2]);

//  EXECUTE COMMANDS, STARTING AT FIRST IN command-file, UNTIL NONE REMAIN
    execute_commands();

//  PRINT THE PROGRAM'S RESULTS
    printf("measurements  %i  %i\n", 0, 0);

    exit(EXIT_SUCCESS);
}

//  vim: ts=8 sw=4