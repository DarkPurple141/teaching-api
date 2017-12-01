
#include <stdlib.h>

typedef char Item;

typedef struct _node *link;

typedef struct _node {
   Item item;
   link next;
} node;

typedef struct _listImpl *list;

typedef struct _listImpl {
   int size;
   link first;
   link last;
} listImpl;

typedef struct _dnode *dlink;

typedef struct _dnode {
    Item  item;
    dlink next;
    dlink prev;
} dnode;

link reverse (link ls);
void insertNext(link ls, link node);
void deleteNext(link ls);
dlink append (dlink list1, dlink list2);
// void append (dlink list1, dlink list2);
