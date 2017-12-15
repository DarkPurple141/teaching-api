#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   char * token = "Jeff\nHello\n\nYou are cool!";
   char * string = NULL;
   char * tofree = NULL;

   tofree = string = strdup(token);
   assert(string != NULL);

   while ((token = strsep(&string, "\n")) != NULL)
         printf("%s\n", token);

   free(tofree);
}
