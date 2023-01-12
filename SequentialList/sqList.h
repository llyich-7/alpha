#include <stdbool.h>

#define INIT_LIST_SIZE 100
#define AUG_LIST_SIZE 10
#define ERROR -1
#define OK 0

typedef int myStatus;
typedef int myTYPE;

typedef struct _list{

    myTYPE *head;
    int size;
    int length;

} SqList;

myStatus init_List(SqList *L);

myStatus insertElem(SqList *L, int i, myTYPE e);
myStatus deleteElem(SqList *L, int i);

bool isEqual(myTYPE a, myTYPE b);

myStatus getElem(SqList *L, int i, myTYPE *e);
myStatus locateElem(SqList *L, int *i, myTYPE e, bool (*funcP)(myTYPE, myTYPE));
myStatus showList(SqList *L);
myStatus mergeList(SqList *La, SqList Lb);

myStatus sortListMonotonicIncrease(SqList *L);
myStatus mergeListMonotonicIncrease(SqList La, SqList Lb, SqList *Lc);
