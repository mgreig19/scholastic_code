/*  CS 480 Program to Illustrate set_sig().
 *  Press control-C three times.
 *  Also start the program with '&' and try sending various signals
 *    to it with 'kill'.
 */
#include <stdio.h>
#include <signal.h> 
#include <errno.h>
#include <stdlib.h>

/* Forward declarations */
static void set_sig(int signo, void (*)(int));
static void ctrl_c_handler(int signo);
static void gotcha_handler(int signo);
static void sigterm_handler(int signo);

/* Main: Set up ctrl-c signal handler, wait forever */
int main()
  {
    printf("\nSignal handler test\nPress ^C a few times\n");
    set_sig(SIGINT, ctrl_c_handler);
    set_sig(SIGILL, gotcha_handler);
    set_sig(5, gotcha_handler);
    set_sig(8, gotcha_handler);
    set_sig(SIGTERM, sigterm_handler); 
    /*set_sig(SIGKILL, gotcha_handler); */
    while(1);
  }

/* Field ctrl-c signals */
void ctrl_c_handler(int signo)
  {
    static int count=0;
    switch (++count)
      {
        case 1:
        case 2:
	  printf("  Going...\n");
	  break;
        case 3: printf("  Gone.\n");
	exit(1);
	break;
     }
  }


/* Refuse to be SIGTERMed.  Bwa ha ha! */
void sigterm_handler(int signo)
  {
    printf("I won't be terminated.\n");
  }


/* Gotcha! */
void gotcha_handler(int signo)
  {
    printf("You can't fool me!  That was signal number %d\n", signo);
  }


/* Install a signal handler using sigaction() */
void set_sig(int signo, void (*handler)(int))
  {
    struct sigaction act;

    act.sa_handler = handler;
    act.sa_flags = SA_RESTART;
    sigemptyset(&act.sa_mask);

    if (sigaction(signo, &act, NULL) == -1)
      {
        perror("sigaction");
        exit(1);
      }
  }
