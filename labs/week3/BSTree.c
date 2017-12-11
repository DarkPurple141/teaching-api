
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

// STATICS
static Leaf newLeaf(Item value) {
   Leaf new = calloc(1, sizeof(leaf));
   new->value = value;

   return new;
}

Tree newTree() {
   Tree new = calloc(1, sizeof(tree));
   return new;
}

void destroyHelper(Leaf l) {
   if (l == NULL) {
      return;
   } else {
      destroyHelper(l->left);
      destroyHelper(l->right);
      free(l);
   }
}

void destroyTree(Tree t) {
   destroyHelper(t->root);
}

void addHelper(Leaf l, Item value) {
   if (l->value < value) {
      if (l->right) {
         addHelper(l->right, value);
      } else {
         l->right = newLeaf(value);
      }
   } else {
      if (l->left) {
         addHelper(l->left, value);
      } else {
         l->left = newLeaf(value);
      }
   }
}

void addToTree(Tree t, Item value) {
   if (!t->root) {
      t->root = newLeaf(value);
   } else {
      addHelper(t->root, value);
   }
   t->size++;
}

static void printHelper(Leaf l) {
   if (l) {
      printHelper(l->left);
      printf("\n%d\n", l->value);
      printHelper(l->right);
   }
}

void printTree(Tree t) {
   printf("===============\n");
   printHelper(t->root);
   printf("===============\n");
}

void removeFromtTree(Tree t, Item value);

bool contains(Tree t, Item value) {
   return true;
}
