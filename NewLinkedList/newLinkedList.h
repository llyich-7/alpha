#define OK      0
#define ERROR   -1

typedef int MYSTATUS;
typedef int MYTYPE;
typedef struct _node{
    MYTYPE data;
    struct _node *next;
} Node, *pNode;

MYSTATUS initList(pNode *ppNode);
MYSTATUS showList(pNode phead);
MYSTATUS addElem(pNode phead, MYTYPE e);
MYSTATUS subElem(pNode phead);
MYSTATUS insElem(pNode phead, MYTYPE e, int location);
MYSTATUS delElem(pNode phead, int location);
MYSTATUS getElem(pNode phead, MYTYPE e, int location);
MYSTATUS findElem(pNode phead, MYTYPE e, int location);
MYSTATUS clearList(pNode phead);
MYSTATUS destoryList(pNode *pphead);
MYSTATUS sortList(pNode phead);
MYSTATUS mergeList(pNode phead1, pNode phead2, pNode *phead);
MYSTATUS sort_and_merge_List(pNode phead1, pNode phead2, pNode phead);
int getLength(pNode phead);

