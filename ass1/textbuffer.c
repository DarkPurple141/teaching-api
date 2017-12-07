
#include "textbuffer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char * line;
typedef struct _node * Node;

typedef struct _node {
   line line;
   int size;
   Node next;
   Node prev;
} node;

typedef struct textbuffer {
   Node head;
   Node tail;
   int numLines;
   int numBytes;
} buffer;

static Node newNode(line line) {

   Node new = calloc(1, sizeof(node));
   new->line = strdup(line);
   new->size = strlen(line);

   return new;
}

#ifdef DEBUG

void printLines(Node n) {
   if (n) {
      printf("%s\n", n->line);
      printLines(n->next);
   } else {
      printf("**** EOF ****\n");
   }
}

void print(TB tb) {
   printLines(tb->head);
}

#endif

static void sanityCheck(TB tb, int pos1, int pos2, char* str) {
   if (pos1 < 0 || pos1 > tb->numLines || pos2 < 0 || pos2 > tb->numLines) {
      fprintf(stderr, "%s: attempt to write lines outside of range\n", str);
      abort();
   }
}

static void deleteNode(Node n) {
   free(n->line);
   free(n);
}

static void initLines(char * text, TB init) {
   char * str = strdup(text);
   line curr = strtok(str, "\n");
   Node head = NULL;
   Node tail = head;

   while (curr) {
      if (!head) {
         head = newNode(curr);
         tail = head;
      } else {
         tail->next = newNode(curr);
         tail = tail->next;
      }
      curr = strtok(NULL, "\n");
      init->numLines++;
      init->numBytes += tail->size;
   }

   init->head = head;
   init->tail = tail;
   //free(str);
}

/* Allocate a new textbuffer whose contents is initialised with the text given
 * in the array.
 */
TB newTB (char text[]) {
   TB new = calloc(1, sizeof(buffer));
   initLines(text, new);
   //printLines(new->head);

   return new;
}

/* Free the memory occupied by the given textbuffer.  It is an error to access
 * the buffer afterwards.
 */
void releaseTB (TB tb) {

   Node curr = tb->head;
   while (curr) {
      Node temp = curr->next;
      deleteNode(curr);
      curr = temp;
   }
   free(tb);
}

/* Allocate and return an array containing the text in the given textbuffer.
 */
char *dumpTB (TB tb) {

   char * array = malloc(tb->numBytes);
   Node head = tb->head;

   for (int i = 0; i < tb->numLines - 1; i++) {
      strcat(array, head->line);
      strcat(array, "\n");
      head = head->next;
   }
   strcat(array, head->line);

   return array;
}

/* Return the number of lines of the given textbuffer.
 */
int linesTB (TB tb) {
   return tb->numLines;
}

/* Swap the two given lines in the textbuffer.
 *
 * - The program is to abort() with an error message if line 'pos1' or line
 *   'pos2' is out of range.  The first line of a textbuffer is at position 0.
 */
void swapTB (TB tb, int pos1, int pos2) {
   sanityCheck(tb, pos1, pos2, "swapTB Error");

}

/* Merge 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' can not be used anymore (as if we had used
 *   releaseTB() on it).
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void mergeTB (TB tb1, int pos, TB tb2);

/* Copy 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' is unmodified and remains usable independent
 *   of 'tb1'.
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void pasteTB (TB tb1, int pos, TB tb2);

/* Cut the lines between and including 'from' and 'to' out of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The cut lines will be deleted from 'tb'.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB cutTB (TB tb, int from, int to) {
   sanityCheck(tb, from, to, "cutTB Error");
   return NULL;
}

/* Copy the lines between and including 'from' and 'to' of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The textbuffer 'tb' will remain unmodified.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB copyTB (TB tb, int from, int to) {
   sanityCheck(tb, from, to, "copyTB Error");
   Node curr = tb->head;
   int index = 0;
   while (index < from) {
      curr = curr->next;
      index++;
   }
   char *dest = NULL;
   while (index < to) {
      if (!dest) {
         dest = strdup(curr->line);
      } else {
         strcat(dest, curr->line);
      }
      curr = curr->next;
      index++;
   }
   //printf("HERE\n");
   TB copy = newTB(dest);

   return copy;
}

/* Remove the lines between and including 'from' and 'to' from the textbuffer
 * 'tb'.
 *
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
void deleteTB (TB tb, int from, int to);


/* Search every line of tb for each occurrence of str1 and replaces them
 * with str2
 */
void replaceText (TB tb, char* str1, char* str2) {

}

/* Bonus Challenges
 */

char* diffTB (TB tb1, TB tb2) ;

void undoTB (TB tb) ;

void redoTB (TB tb) ;


#ifdef DEBUG

int main() {
   printf("RUNNING SOME WHITEBOX STUFF\n");
   TB new = newTB("String");
   print(new);
   return 0;
}

#endif
