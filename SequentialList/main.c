#include <stdio.h>
#include <stdlib.h>
#include "sqList.h"

int main(){

    printf("Haha!\n");
    printf("You are so handsome! Oh my God! I can't believe this!\n");
    
    bool (*funPointer)(myTYPE, myTYPE);
    int position;
    myTYPE reg;
    SqList List;
    SqList ListPrime;
    if(init_List(&List) == OK){
        printf("OK!\n");
    }else{
        printf("ERROR!\n");
    }
    
    if(init_List(&ListPrime) == OK){
        printf("OK!\n");
    }else{
        printf("ERROR!\n");
    }

    if(insertElem(&List, 1, 9) == OK){
        printf("OK!\n");
    }else{
        printf("ERROR!\n");
    }
    showList(&List);
    insertElem(&List, 1, 6);
    showList(&List);
    insertElem(&List, 1, 2);
    showList(&List);
    insertElem(&List, 1, 5);
    showList(&List);
    insertElem(&List, 4, 522);
    showList(&List);

    deleteElem(&List, 4);
    showList(&List);
 
    funPointer = isEqual;
    
    if((*funPointer)(2, 3) == OK){
        printf("Equal!\n");
    }else{
        printf("Not equal!\n");
    }
    
    if(funPointer(2, 3) == OK){
        printf("Equal!\n");
    }else{
        printf("Not equal!\n");
    }
    int n = 20;
    getElem(&List, n, &reg);
    printf("the %d is %d!\n", n, reg);

    if(locateElem(&List, &position, 9, funPointer) == OK){
        printf("target found! in position: %d\n", position);
    }else{
        printf("target not found!");
    }
    insertElem(&ListPrime, 1, 522);
    showList(&ListPrime);
    insertElem(&ListPrime, 2, 7984);
    showList(&ListPrime);

    mergeList(&ListPrime, List);
    showList(&ListPrime);

    showList(&ListPrime);
    sortListMonotonicIncrease(&ListPrime);
    showList(&ListPrime);

    showList(&List);
    sortListMonotonicIncrease(&List);
    showList(&List);

    SqList ListPrimePrime;
    mergeListMonotonicIncrease(List, ListPrime, &ListPrimePrime);
    showList(&ListPrimePrime);

    printf("%d\n", sizeof(List));
    printf("%d\n", sizeof(SqList *));
    printf("%d\n", sizeof(myTYPE *));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(int *));
    getchar();   
    getchar();

    return 0;
}