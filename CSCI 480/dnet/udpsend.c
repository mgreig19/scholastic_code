/*
* Send UDP  datagram  using socket descriptor and sendto().
*
* Hacked up from James C Foster udp example program #3.
*
* ---
*
* Revised 28 March 2014
*   Include <unistd.h>
*
* Revised 15 March 2014:
*   Read until EOF (don't stop at 100 bytes)
*   Print byte total at end
*   Break up sending into text lines (up to 100 buffer limit)
*/

#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define UDP3_DST_ADDR "127.0.0.1"
#define UDP3_DST_PORT 1234

int main(int argc, char * argv[]) {
    struct sockaddr_in sin;
    char buf[100];
    int  sock = 0;
    int  ret  = 0;
    int  nbytes;
    int  ch;
    int  total_bytes_sent = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0) {
        perror("socket() failed.");
        return(1);
    }

    memset(&sin, 0x0, sizeof(sin));

    sin.sin_family   = AF_INET;
    sin.sin_port     = htons(UDP3_DST_PORT);
    sin.sin_addr.s_addr = inet_addr(UDP3_DST_ADDR);

    printf("Message: ");
    nbytes = 0;
    do {
	ch = getchar();
        if (ch != EOF) buf[nbytes++] = (char) ch;
	if (nbytes==100 || ch=='\n' || ch==EOF) {
            ret = sendto(sock, buf, nbytes, 0, 
                         (struct sockaddr *) &sin, sizeof(sin));
            if(ret != nbytes) {
                printf("sendto(%d bytes) failed. Prior %d bytes succeeded\n",
			nbytes, total_bytes_sent);
                perror("Sending UDP");
            }
	    total_bytes_sent += nbytes;
	    nbytes = 0;
        }
    } while (ch != EOF);
    printf("Sent %d bytes\n", total_bytes_sent);
    close(sock);
    return(0);
}
