
typedef char Item;
// Stack.h
typedef struct _stackImp *Stack;
//Function Prototypes
Stack createStack( void );
void destroyStack( Stack stack );
Item pop( Stack stack);
void push( Stack stack, Item data);
int stackSize( Stack stack);
