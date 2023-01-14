#include <stdio.h>
#include <stdlib.h>
#include "newLinkedList.h"

int main(){

    pNode head_pointer;
    initList(&head_pointer);
    addElem(head_pointer, 2);
    addElem(head_pointer, 22);
    addElem(head_pointer, 32);
    addElem(head_pointer, 62);
    addElem(head_pointer, 25);
    addElem(head_pointer, 72);
    showList(head_pointer);

    subElem(head_pointer);
    showList(head_pointer);

    insElem(head_pointer, 99, 4);
    showList(head_pointer);

    insElem(head_pointer, 992, 5);
    showList(head_pointer);

    insElem(head_pointer, 992, 10);
    showList(head_pointer);

    printf("===============================\n");
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, 0);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, 1);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, 2);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, 10);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    
    printf("===============================\n");
    delElem(head_pointer, getLength(head_pointer));
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, getLength(head_pointer));
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, getLength(head_pointer));
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));

    delElem(head_pointer, 1);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    delElem(head_pointer, 1);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));

    addElem(head_pointer, 2);
    addElem(head_pointer, 22);
    addElem(head_pointer, 32);
    addElem(head_pointer, 62);
    addElem(head_pointer, 25);
    addElem(head_pointer, 72);
    showList(head_pointer);
    printf("Length: %d\n", getLength(head_pointer));
    pNode hp;
    initList(&hp);
    insElem(hp, 9, 0);
    showList(hp);
    insElem(hp, 9, 1);
    showList(hp);
    insElem(hp, 9, 2);
    showList(hp);
    
    pNode hpp;
    initList(&hpp);
    
    mergeList(head_pointer, hp, &hpp);
    showList(hpp);
    addElem(head_pointer, 7242);
    insElem(hp, 9, 1);
    insElem(hp, 9, 1);
    insElem(hp, 9, 1);
    insElem(hp, 9, 5);
    insElem(hp, 9, 5);
    insElem(hp, 9, 5);

    insElem(hp, 9, 5);
    showList(hp);
    showList(head_pointer);
    showList(hpp);


    
return 0;
}