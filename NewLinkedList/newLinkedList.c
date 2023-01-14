#include <stdio.h>
#include <stdlib.h>
#include "newLinkedList.h"

MYSTATUS initList(pNode *pphead){

    (*pphead) = (Node*)malloc(sizeof(Node));
    
    if(*pphead == NULL){
        return ERROR;
    }
    
    (*pphead)->next = NULL;

return OK;
}

MYSTATUS showList(pNode phead){
    if(phead->next == NULL){
        printf("error showList()\n");    
        return ERROR;
    }

    pNode p = phead->next;
    
    while( p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    putchar('\n');

return OK;
}

// MYSTATUS addElem(pNode *phead, MYTYPE e){
//     pNode p;
//     pNode q;
//
//     p = *(phead);
//     while(p->next != NULL){
//         p = p->next;
//     }
//     p->next = (Node*)malloc(sizeof(Node));
//     p->next->data = e;
//     p->next->next = NULL;
//
//     return OK;
// }

MYSTATUS addElem(pNode phead, MYTYPE e){
    
    if(phead == NULL){
        printf("error addElem()\n");    
        return ERROR;
    }
    
    pNode p;
    pNode q;

    p = phead;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = (Node*)malloc(sizeof(Node));
    p->next->data = e;
    p->next->next = NULL;

    return OK;
}

MYSTATUS subElem(pNode phead){

    if(phead == NULL || phead->next == NULL){
        printf("error subElem()\n");
        return ERROR;
    }

    pNode p;
    p = phead->next;

    while(p->next->next != NULL){       //p point to the (n-1)th node at the end of while().
        p = p->next;
    }

    free(p->next);                      //free the nth node.
    
    p->next = NULL;

return OK;
}

MYSTATUS insElem(pNode phead, MYTYPE e, int location){
    if(phead == NULL || location <= 0){
        printf("error insElem()\n");
        return ERROR;
    }

    pNode p;
    pNode q;
    p = phead;

    if(p->next == NULL && location == 1){
        p->next = (Node*)malloc(sizeof(Node));
        p->next->data = e;
        p->next->next = NULL;
    }else{
        while(p->next != NULL){
            location--;
            if(location == 0){
                q = p->next;
                p->next = (Node*)malloc(sizeof(Node));
                p->next->data = e;
                p->next->next = q;
                break;
            }
            p = p->next;
        }

        if(location > 0){
            printf("error insElem()\n");
            return ERROR;
        }
    }

return OK;
}

MYSTATUS delElem(pNode phead, int location){
    if(phead == NULL || phead->next == NULL || location <= 0){
        printf("error delElem()\n");
        return ERROR;
    }

    pNode p = phead;
    pNode q;

    while(p->next != NULL){
        location--;
        if(location == 0){
            q = p->next->next;
            free(p->next);
            p->next = q;
            break;
        }
        p = p->next;
    }
    if(location > 0){
        printf("error delElem()\n");
        return ERROR;
    }

return OK;
}
getElem(pNode phead, MYTYPE e, int location){
    pNode p;


return OK;
}
MYSTATUS findElem(pNode phead, MYTYPE e, int location){



return OK;
}
MYSTATUS clearList(pNode phead){



return OK;
}
MYSTATUS destoryList(pNode *pphead){



return OK;
}
MYSTATUS sortList(pNode phead){



return OK;
}
MYSTATUS mergeList(pNode phead1, pNode phead2, pNode *pphead){

    pNode p;
    p = phead1;
    *pphead = phead1;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = phead2->next;

return OK;
}
MYSTATUS sort_and_merge_List(pNode phead1, pNode phead2, pNode phead){



return OK;
}

int getLength(pNode phead){
    int cnt = 0;
    pNode p = phead->next;

    while(p != NULL){
        cnt++;
        p = p->next;
    }

    return cnt;
}






