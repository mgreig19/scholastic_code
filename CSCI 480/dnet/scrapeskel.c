
/* Screen Scraping skeleton for 480 class */
/* Reva Freedman, March 2014 */

/* Revisions: */
/* 3/28/2014 - replace 'void main' by 'int main'; add 'return 0' */

#include <stdio.h>

/* Needed for string subroutines */
#include <string.h>

/* Needed for malloc */
#include <stdlib.h>

/* forward declarations */
void scrape(char * buf);
void printurls(void);

/* Main program to test scraping */
int main() {
    char s[] = "hello http://www.niu.edu/niu.html\" I am a http://url.valpo.edu\"\n";
    scrape(s);
    printurls();
    return 0;
}

/*-------------*/ 
/* Scrape URLS */
/*-------------*/ 

/* Call scrape(buffer) with every buffer-full of web page source.
   It will save the scraped URLs in a static array, adding new URLs every
   time you call it */
/* Call printurls() to print the results */

/* These functions are used to pick URLs from web page source obtained
   from a networking program.
   In this assignment we will just call them from a driver to test them standalone.
   The purpose of the assignment is to practice basic C constructs - pointers, malloc,
   string functions and I/O - in a realistic context. */

#define MAXURLS 100
char *(urllist[MAXURLS]);	/* Array of pointers to char: extracted URLs */
int nurls = 0;			/* Number of extracted URLs */
char *bptr;			/* Pointer to beggining char of URL */
char *eptr;			/* Pointer to ending char of URL */
int urllen;			/* Length of extracted  URL */
char *urlmem;			/* Memory for extracted URL */

/* Scrape URLs from buffer into static list of extracted URLs */
void scrape(char *buf) {

   // printf(buf); 
   while (nurls < MAXURLS) {
   
      /* Find location of first "http:" (case insensitive) */
      /* 1. Here's a start - you can make it case insensitive */
      bptr = strstr(buf, "http:");
      if (bptr == NULL) break;

      /* Find location of '\"' double-quote character ending the URL using 
       * strchr(), starting from bptr address  */
      /* Be sure to break if eptr is NULL */
      // 2. Your code here
      
      /* Put a terminating zero at eptr, clobbering the double-quote */
      // 3. Your code here

      //printf("%s\n", bptr);  This should print the URL that you found
      
      /* Find length of the extracted URL, starting at bptr */
      // 4. Your code here
      
      /* Allocate urllen+1 bytes of memory using malloc(). */
      /* Be sure to error if malloc returns NULL */
      // 5. Your code here

      /* Copy the extracted URL from bptr to urlmem */
      // 6. Your code here

      /* The next entry in URLS array points to the new URL */
      // 7. Your code here

      /* Resume searching at the next address after etpr */
      buf = eptr+1;
    }
}

/* Print all the scraped URLS */
void printurls() {
   int i;
   for (i=0; i<nurls; i++) {
      printf("%s", urllist[i]);
   }
}
