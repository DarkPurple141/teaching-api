
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _tree * Tree;
typedef int Item;

Tree newTree();
void destroyTree(Tree t);
void addToTree(Tree t, Item value);
void removeFromtTree(Tree t, Item value);
bool contains(Tree t, Item value);
