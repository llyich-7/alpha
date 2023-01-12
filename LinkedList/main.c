#include <stdio.h>
#include <stdlib.h>
#include "lkList.h"

int main(void){

    printf("Oh my friend!\n");
    printf("You are such a handsome man!\n");
    printf("Oh my God! I just can't believe this! Oh my...\n");

    Node *head;
    head = (Node *)malloc(sizeof(Node));
    
    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 1;
    head->next->next = (Node *)malloc(sizeof(Node));

    printf("i'm here!\n");

    Node newHead;
    initList(&newHead);
    if(addElem(&newHead, 2) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);

    if(addElem(&newHead, 22) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);
    
    if(addElem(&newHead, 222) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);

    subElem(&newHead);
    showList(&newHead);

    subElem(&newHead);
    showList(&newHead);

    subElem(&newHead);
    showList(&newHead);

    subElem(&newHead);
    showList(&newHead);

    if(addElem(&newHead, 222) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);

    if(addElem(&newHead, 22) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);

    if(addElem(&newHead, 2) == OK){
        printf("add done!\n");
    }else{
        printf("add failed!\n");
    }
    showList(&newHead);

    int reg;
    int index;
    
    getElem(&newHead, 2, &reg);
    printf("e = %d.\n", reg);
    getElem(&newHead, 22, &reg);
    printf("e = %d.\n", reg);
    getElem(&newHead, 1, &reg);
    printf("e = %d.\n", reg);
    getElem(&newHead, 3, &reg);
    printf("e = %d.\n", reg);

    if(locateElem(&newHead, &index, 22) == OK){
        printf("found! at position: %d\n", index);
    }else{
        printf("Not found!\n");
    }
    if(locateElem(&newHead, &index, 222) == OK){
        printf("found! at position: %d\n", index);
    }else{
        printf("Not found!\n");
    }
    if(locateElem(&newHead, &index, 22222) == OK){
        printf("found! at position: %d\n", index);
    }else{
        printf("Not found!\n");
    }

    if(getElem_B(&newHead, 1, &reg) == OK){
        printf("e = %d.\n", reg);
    }else{
        printf("error!\n");
    }
    if(getElem_B(&newHead, 2, &reg) == OK){
        printf("e = %d.\n", reg);
    }else{
        printf("error!\n");
    }
    if(getElem_B(&newHead, 3, &reg) == OK){
        printf("e = %d.\n", reg);
    }else{
        printf("error!\n");
    }
    if(getElem_B(&newHead, 4, &reg) == OK){
        printf("e = %d.\n", reg);
    }else{
        printf("error!\n");
    }
    if(getElem_B(&newHead, 11, &reg) == OK){
        printf("e = %d.\n", reg);
    }else{
        printf("error!\n");
    }

    Node jead;
    initList(&jead);
    addElem(&jead, 23);
    addElem(&jead, 1);
    addElem(&jead, 5);
    addElem(&jead, 3);
    showList(&newHead);
    showList(&jead);

    Node pead;
    initList(&pead);
    mergeList(&newHead, &jead, &pead);
    showList(&pead);

    Node qead;
    initList(&qead);
    sortList(&pead, &qead);

    showList(&qead);


    return 0;
}