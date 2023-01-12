#include <stdbool.h>

#define INIT_LIST_SIZE 100
#define AUG_LIST_SIZE 10
#define ERROR -1
#define OK 0

typedef int myStatus;
typedef int myTYPE;

typedef struct _Node{
    myTYPE data;
    struct _Node *next;
}Node;

myStatus showList(Node *head);
myStatus initList(Node *head);
myStatus addElem(Node *head, myTYPE e);
myStatus subElem(Node *head);
myStatus getElem(Node *head, int position, myTYPE *e);
myStatus locateElem(Node *head, int *position, myTYPE e);
myStatus getElem_B(Node *head, int position, myTYPE *e);

myStatus insertElem(Node *head, int position, myTYPE e);
myStatus deleteElem(Node *head, int position, myTYPE e);

myStatus mergeList(Node *head1, Node *head2, Node *head);
myStatus sort_and_mergeList(Node *head1, Node *head2, Node *head);
myStatus sortList(Node *head1, Node *head);




