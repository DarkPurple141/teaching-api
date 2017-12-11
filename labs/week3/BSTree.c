
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _leaf *Leaf;

typedef struct _leaf {
   Item value;
   Leaf left;
   Leaf right;
} leaf;

typedef struct _tree {
   Leaf root;
   int size;
} tree;

Tree newTree() {
   Tree new = calloc(1, sizeof(tree));
   return new;
}

void destroyTree(Tree t);
void addToTree(Tree t, Item value);
void removeFromtTree(Tree t, Item value);
bool contains(Tree t, Item value);
