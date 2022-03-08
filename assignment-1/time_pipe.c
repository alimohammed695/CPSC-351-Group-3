//===========================================================================
// This program will be run as “./time <command [args]>” and will report the
// amount of elapsed time to run the specified command. The example output
// below reports the amount of time to run the command ls
//=============================================================================

#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

//#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1


int main( int argc, char **argv )
{

  typedef struct timeval timeval_t; // type of object to share
  int status;
  pid_t pid;
  int FD[2];
  
  // 2) create the pipe
  if (pipe(FD) == -1)
  {
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  // fork a child process
  pid =fork();

  if( pid < 0 ) // child process
  { 
    fprintf(stderr, "Fork failed");
    return 1;
  }

  if( pid == 0 ) // child process
  {
    // close the end of the pipe
    close(FD[READ_END]);

    // write the current time into the pipe,
    timeval_t startTime;
    gettimeofday( &startTime, 0 );
    write(FD[WRITE_END], &startTime, sizeof(startTime));

    // close the pipe,
    close(FD[WRITE_END]);

    //execute the command with arguments
    execvp( argv[1], &argv[1] );
}

  //wait for child to finish
  wait(&status);

  // get the end time
  timeval_t end_time;
  gettimeofday( &end_time, 0 );

  // close the end of the pipe
  close(FD[WRITE_END]);

  // get the start time
  timeval_t startTime;
  read(FD[READ_END], &startTime, sizeof(startTime));

  // close the pipe read end 
  close(FD[READ_END]);

  // calculate elapsed time
  timeval_t elapsed_time;
  timersub( &end_time, &startTime, &elapsed_time );


  // print microseconds right justified zero filled
  printf( "\nElapsed time: %ld.%06ld seconds\n", elapsed_time.tv_sec, elapsed_time.tv_usec );

  return 0;
}
