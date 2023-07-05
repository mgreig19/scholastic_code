/*
 * udprcv.c
 *
 * Receive  UDP  datagram using recvfrom() function. 
 * 
 * Hacked up from Jamce C. Foster udp example program #4.
 *
 * -----
 * Revised 15 March 2014:
 *   Use received byte count instead of assuming zero-term. 
 *
 */

#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

# Change this to 3000 + 2 digits from your z number
#define UDP4_PORT 1234

char * escape_nonprintable(char *inbuf, int nbytes);

int main(int argc, char*argv[]) {
    struct sockaddr_in sin;
    char buf[100];
    int  sock = 0;
    int  ret  = 0;
    int  nbytes = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0) {
        perror("socket() failed.");
        return(1);
    }

    memset(&sin, 0x0, sizeof(sin));

    sin.sin_family   = AF_INET;
    sin.sin_port     = htons(UDP4_PORT);
    sin.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sock, (struct sockaddr *) &sin, sizeof(sin));
    if(ret < 0) {
        perror("bind() failed.");
        return(1);
    }

    while (1) {
        ret = recvfrom(sock, buf, 100, 0, NULL, NULL);
        if(ret < 0) {
            perror("recvfrom() failed.");
            return(1);
        }
	char * outbuf = escape_nonprintable(buf, ret);
        printf("Received=(%s)\n", outbuf);
        free(outbuf);
    }
    close (sock);

    return(0);
}

char * escape_nonprintable(char *inbuf, int nbytes) {

   char *outbuf = (char *)malloc(4*nbytes+1);
   *outbuf = '\000';
   char c;
   char temp[5];
   int pt;

   for (pt=0; pt<nbytes; pt++) {
      c = *inbuf++;
      if (isprint(c)) {
         strncat(outbuf, inbuf-1, 1); continue;
      }
      switch (c) {
      case '\n':
         strcat(outbuf, "\\n"); break;
      case '\r':
         strcat(outbuf, "\\r"); break;
      case '\t':
         strcat(outbuf, "\\t"); break;
      default:
         sprintf(temp, "\\x%02x", c);
         strcat(outbuf, temp);
         break;
      } /* switch */
   }
   return outbuf;      
}


