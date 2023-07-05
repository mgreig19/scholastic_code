#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signo) {
   printf("Received signal number %d\n", signo);
}

void main() {
   int err = signal(SIGINT,  handler);
   int i;
   for (i=1; i<100; i++) {
      sleep(1);
   }
}


