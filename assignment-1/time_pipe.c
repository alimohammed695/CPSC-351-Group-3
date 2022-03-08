#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/time.h>


struct timeval_t
{

  time_t tv_sec;
  suseconds_t tv_usec;

timeval(int *elapsed_time)
{
  tv_sec = elapsed_time;
  tv_usec = elapsed_time;

}


//-----------------I just put this function inside the struck//
// I have to read teh chapther to understand it better. starting the program.
// the I will have to
// read the chapter to fully understand the better. .
// its not finished yet. you will get an error if you cimpile.  thank you




int main()
{
    pid = fork()

    if (pid < 0)
    {
      fprintf(stderr, "Fork Failed");
      return 1;
    }
    if (pid == 0)
    {
      timeval_t startTime;
      gettimeofday( &startTime, 0 );
    }
    wait(null);

    timeval_t end_time;
    end_time = gettimeofday( &end_time, 0 );


    timeval_t elapsed_time;
    timersub( &end_time, &startTime, &elapsed_time );

    timeval(*elapsed_time);

    printf( "\nElapsed time: %d.%06d seconds\n", elapsed_time.tv_sec, elapsed_time.tv_usec );

}
