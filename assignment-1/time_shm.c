//============================================================================
//This program will be run as “./time <command [args]>” and will report the
//amount of elapsed time to run the specified command. The example output
//below reports the amount of time to run the command ls:
//============================================================================

#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/mman.h> 
#include <sys/shm.h>
#include <sys/time.h> 
#include <sys/wait.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv )
{
    int status; // variable created for wait() function
    typedef struct timeval timeval_t;
    // checking for command ls
    
    // name of the shared memory object
    pid_t pid;
    const char *name = "OS";
    
    
    const int SIZE =4096;

    // creating the shared memory object
    int FD = shm_open(name, O_CREAT | O_RDWR, 0666);

    //configure the size of the shared memory boject
    ftruncate(FD, SIZE);

    //memory map the shared memory object
    timeval_t *sMemory = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, FD, 0);

    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork Failed");
        return 1;
    }

    if( pid == 0 ) // child process
    {
        // Get and save the current time into shared memory,
        gettimeofday(sMemory, 0 );

        //execute the command with arguments
        execvp( argv[1], &argv[1] );
    }
         
        wait(&status);

        // get the end time
        timeval_t end_time;
        gettimeofday(&end_time, 0 );

        // get the start time
        timeval_t startTime;
        startTime = *sMemory;

        shm_unlink(name);

        // calculate elapsed time
        timeval_t elapsed_time;
        timersub( &end_time, &startTime, &elapsed_time );


    // print microseconds right justified zero filled
    printf( "\nElapsed time: %ld.%06ld seconds\n", elapsed_time.tv_sec, elapsed_time.tv_usec );
  
    
    return 0;
}
