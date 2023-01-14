#include <stdio.h>
#include <stdlib.h>
#include "lkList.h"

myStatus addElem(Node *head, myTYPE e){
    if(head == NULL){
        return ERROR;
    }

    Node *p;
    p = head;
    
    while(p->next != NULL){
        p = p->next;
    }

    if((p->next = (Node *)malloc(sizeof(Node))) == NULL){
        return ERROR;
    }
    p->next->data = e;
    p->next->next = NULL;

    return OK;
}

myStatus showList(Node *head){
    if(head == NULL || head->next == NULL){
        return ERROR;
    }
    Node *p;
    p = head->next;

    printf("Show list: ");

    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');

    return OK;
}

myStatus initList(Node *head){
    if(head == NULL){
        return ERROR;
    }
    head->next = NULL;

    return OK;
}

myStatus subElem(Node *head){
    if(head == NULL || head->next == NULL){
        return ERROR;
    }
    Node *p;
    Node *q;
    p = head->next;
    q = head;
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    free(p);

    return OK;
}

myStatus getElem(Node *head, int position, myTYPE *e){
    if(head == NULL || head->next == NULL){
        return ERROR;
    }
    Node *p = head->next;
    Node *q;
    int cnt = 0;
    int length = 0;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    length = cnt;
    if(position > length){
        return ERROR;
    }

    p = head->next;
    cnt = 1;
    while(cnt < position){
        cnt++;
        p = p->next; 
    };
    *e = p->data;
    
    return OK;
}

myStatus getElem_B(Node *head, int position, myTYPE *e){

    Node *p = head->next;
    int cnt = 0;
    while(p != NULL){
        cnt++;
        if(cnt == position){
            *e = p->data;
            break;
        }
        p = p->next;
    }
    
    if(cnt < position){
        return ERROR;
    }

    return OK;
}

myStatus locateElem(Node *head, int *position, myTYPE e){
    if(head == NULL || head->next == NULL){
        return ERROR;
    }
    Node *p;
    int cnt = 0;
    p = head->next;
    while(p != NULL){
        cnt++;
        if(p->data == e){
            *position = cnt;
            return OK;
        }
        p = p->next;
    }

    return ERROR;
}

myStatus insertElem(Node *head, int position, myTYPE e){

    if(head->next == NULL){
        return ERROR;
    }

    int cnt = 0;
    Node *p;
    Node *q;
    Node *r;
    p = head->next;
    q = head;
    
    while(p != NULL){
        cnt++;
        if(cnt == position){
            r = (Node *)malloc(sizeof(Node));
            r->data = e;
            r->next = p;
            q->next = r;
            break;        
        }
        p = p->next;
        q = q->next;
    }

    if(cnt < position){
        return ERROR;
    }

    return OK;   
}

myStatus deleteElem(Node *head, int position, myTYPE e){
    if(head->next == NULL){
        return ERROR;
    }
    
    int cnt = 0;
    Node *p;
    Node *q;
    Node *r;
    p = head->next;
    q = head;

    while(p != NULL){
        cnt++;
        if(cnt == position){
            q->next = p->next;
            free(p);
            break;        
        }
        p = p->next;
        q = q->next;
    }

    if(cnt < position){
        return ERROR;
    }

    return OK;
}

// myStatus mergeList(Node *head1, Node *head2, Node *head){

//     Node *p;
//     Node *q;
//     Node *r;
    
//     q = head;
    
//     p = head1->next;
//     while(p->next != NULL){
//         r = (myTYPE*)malloc(sizeof(Node));
//         r->data = p->data;
//         r->next = NULL;             //create a new node.
//         q->next = r;                //let q->next point this new node.
//         q = r;                      //update q. 
        
//         p = p->next;
//     }
//     r = (myTYPE*)malloc(sizeof(Node));
//     r->data = p->data;
//     r->next = NULL;             //create a new node.
//     q->next = r;                //let q->next point this new node.
//     q = r;

//     p = head2->next;
//     while(p->next != NULL){
//         r = (myTYPE*)malloc(sizeof(Node));
//         r->data = p->data;
//         r->next = NULL;             //create a new node.
//         q->next = r;                //let q->next point this new node.
//         q = r;                      //update q. 
        
//         p = p->next;
//     }
    
//     r = (myTYPE*)malloc(sizeof(Node));
//     r->data = p->data;
//     r->next = NULL;             //create a new node.
//     q->next = r;                //let q->next point this new node.
//     q = r;

    
// return OK;
// }

myStatus mergeList(Node *head1, Node *head2, Node *head){

    if(head1->next == NULL || head2->next == NULL){
        return ERROR;
    }


    Node *p;
    Node *q;
    Node *r;
    
    q = head;
    
    p = head1->next;
    while(p != NULL){
        r = (Node*)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;             //create a new node.
        
        q->next = r;                //let q->next point this new node.
        q = r;                      //update q. 
        
        p = p->next;
    }

    p = head2->next;
    while(p != NULL){
        r = (Node*)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;             //create a new node.
        q->next = r;                //let q->next point this new node.
        q = r;                      //update q. 
        
        p = p->next;
    }
    
    
return OK;
}

// myStatus sortList(Node *head1, Node *head){

//     Node *p;
//     Node *q;
//     Node *r;

//     myTYPE reg;
    
//     r = head1->next;

//     while(r->next != NULL){
//         p = head1->next;
//         q = head1->next->next;
//         while(q != NULL){
//             if(p->data < q->data){
//                 reg = q->data;
//                 q->data = p->data;
//                 p->data = reg;
//             }            
//             p = p->next;
//             q = q->next;
//         }
//         r = r->next;
//     }

// return OK;
// }

myStatus sortList(Node *head1, Node *head){

    Node *p;
    Node *q;
    Node *r;

    myTYPE reg;
    
    p = head1->next;
    q = head;

    while(p != NULL){
        r = (Node*)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;

        q->next = r;
        q = r;

        p = p->next;
    }

    r = head->next;

    while(r->next != NULL){
        p = head->next;
        q = head->next->next;
        while(q != NULL){
            if(p->data < q->data){
                reg = q->data;
                q->data = p->data;
                p->data = reg;
            }            
            p = p->next;
            q = q->next;
        }
        r = r->next;
    }

return OK;
}

myStatus sort_and_mergeList(Node *head1, Node *head2, Node *head){

        
    
}