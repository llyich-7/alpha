#include <stdio.h>
#include <stdlib.h>

#include "sqList.h"


//O = 1
myStatus init_List(SqList *L){
    myTYPE *p = NULL;
    if((p = (myTYPE *)malloc(sizeof(myTYPE)*INIT_LIST_SIZE)) == NULL){
        return ERROR;
    }else{
        L->head = p;
        L->size = INIT_LIST_SIZE;
        L->length = 0;
        return OK;
    }
}

//O = 0.5 * L->length
myStatus insertElem(SqList *L, int i, myTYPE e){
    
    if((i > L->length + 1) || (i <= 0)){ 
         return ERROR;
    }

    if(L->length >= L->size){
        myTYPE *newSpace;
        newSpace = (myTYPE *)realloc(L->head, sizeof(myTYPE)*((L->size)+AUG_LIST_SIZE));
        L->size = L->size + AUG_LIST_SIZE;
    }

    myTYPE *p;
    myTYPE *q;

    
    if(L->length == 0){
        L->head[i-1] = e;
    }else{
        p = &(L->head[i-1]);    
        for(q = &((L->head)[L->length - 1]); p <= q; q--){
        *(q + 1) = *q;
        }
        
        *p = e;
    }

    L->length++;    

    return OK;
}

//O = 0.5 * L->length
myStatus deleteElem(SqList *L, int i){
    if(L->length == 0 || i > L->length || i < 1){
        return ERROR;
    }
    myTYPE *p;
    myTYPE *q;

    p = &(L->head[i - 1]);
    q = &(L->head[L->length - 1]);

    do{
        *p = *(p+1);

    }while(++p < q);

    L->length--;

    return OK;

}

//O = 1
myStatus getElem(SqList *L, int i, myTYPE *e){

    *e = 0;

    if(L->length == 0 || i < 1 || i > L->length){

        return ERROR;
    }

    *e = L->head[i-1];
    
    return OK;
}

//O = L->length
myStatus showList(SqList *L){
    if(L->length <= 0){
        printf("Empty!\n");
        return ERROR;
    }

    myTYPE *p;
    myTYPE *q;
    p = L->head;
    q = &(L->head[L->length - 1]);
    for(; p <= q; p++){
        printf("%d ", *p);
    }
    putchar('\n');
    
    return OK;
}

//O = 1
bool isEqual(myTYPE a, myTYPE b){

    return (a == b)? true : false;
}

//O = L->length
myStatus locateElem(SqList *L, int *i, myTYPE e, bool (*funcP)(myTYPE, myTYPE)){
    if(L->length == 0){
        return ERROR;
    }
    
    myTYPE *p;
    myTYPE *q;
    p = L->head;
    q = &(L->head[L->length - 1]);

    *i = 0;

    while(p <= q){
        if(funcP(e, *p)){
            *i = p - (L->head) + 1;
            break;
        }
        p++;
    }

    if(*i == 0){
        return ERROR;
    }else{
        return OK;
    }


/*
    int n;
    while(n < L->length){
        if(f){

        }

    }
*/

}

//O = La.length * Lb.length
myStatus mergeList(SqList *La, SqList Lb){
    //condition judging
    if(Lb.length == 0){
        return ERROR;
    }

    //function implementing
    int i;
    int position;
    int reg;

    for(i = 0; i < Lb.length; i++){
        if(locateElem(La, &position, Lb.head[i], isEqual) != OK){
            getElem(&Lb, i+1, &reg);
            insertElem(La, (La->length)+1, reg);
        }
    }

    return OK;
}

//O = 0.5*(L->length)^2
myStatus sortListMonotonicIncrease(SqList *L){
    if(L == NULL || L->length == 0){
        return ERROR;
    }

    myTYPE reg;
    
    int i, j;

    for(i = 0; i < (L->length) - 1; i++){
        for(j = 0; j < (L->length - 1) - i; j++){
            if(L->head[j] > L->head[j+1]){
                reg = L->head[j];
                L->head[j] = L->head[j+1];
                L->head[j+1] = reg;
            }
                       
        }
    }

    return OK;
}


//O = La.length + Lb.length
myStatus mergeListMonotonicIncrease(SqList La, SqList Lb, SqList *Lc){
    if(Lb.length == 0 || La.length == 0){
        return ERROR;
    }
    
    init_List(Lc);

    int i;
    int j;
    int k;
    for(i = 0, j = 0, k = 0; (i < La.length) && (j < Lb.length); ){
        if(La.head[i] < Lb.head[j]){
            insertElem(Lc, ++k, La.head[i++]);
        }else if(La.head[i] > Lb.head[j]){
            insertElem(Lc, ++k, Lb.head[j++]);
        }else{
            insertElem(Lc, ++k, La.head[i]);
            i++;
            j++;
        }
    }

    while(i < La.length){
            insertElem(Lc, ++k, La.head[i++]);
    }
    
    while(j < Lb.length){
            insertElem(Lc, ++k, Lb.head[j++]);
    }

    return OK;
    /*
    for(i = 0; (i < La.length) && (i < Lb.length); i++){
        if(La.head[i] >= Lb.head[i]){
            insertElem(&Lc, i+1, Lb.head[i]);
        }else{
            insertElem(&Lc, i+1, La.head[i]);
        }
    }

    while(i < La.length){
        insertElem(&Lc, i+1, La.head[i]);
        i++;
    }

    while(i < Lb.length){
        insertElem(&Lc, i+1, Lb.head[i]);
        i++;
    }

    return OK;
    */
}