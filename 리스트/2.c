#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial{
    int coef, exp;
    struct Polynomial* next;
} PN;
typedef struct Polynomials{
    PN *header;
    int len;
} PNs;


PN* initPolyN(int coef, int exp);
PNs* initPolyNs();
void addPN(PNs *PNs,int coef, int exp);
PNs *calculate(PNs *p1, PNs *p2);
void print(PNs* pns);


int main(){
    PNs* pns1 = initPolyNs();
    PNs* pns2 = initPolyNs();
    PNs* resultPNs;

    int n;scanf("%d", &n);
    int coef, exp;
    for(int i = 0; i<n; i++){
        scanf("%d %d", &coef, &exp);
        addPN(pns1, coef, exp);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &coef, &exp);
        addPN(pns2, coef, exp);
    }

    resultPNs = calculate(pns1, pns2);

    print(resultPNs);
}

PN* initPolyN(int coef, int exp){
    PN* newPN = (PN*) malloc(sizeof(PN));
    newPN->next = NULL;
    newPN->coef = coef;
    newPN->exp = exp;

    return newPN;
}

PNs* initPolyNs(){
    PNs* newPNs = (PNs*) malloc(sizeof(PNs));
    newPNs->header = initPolyN(0, 0);

    return newPNs;
}

void addPN(PNs *PNs,int coef, int exp){
    PNs->len++;
    PN *lastPN = PNs->header;
    for(;lastPN->next; lastPN = lastPN->next);
    PN* newPN = initPolyN(coef, exp);
    lastPN->next = newPN;
}

PNs *calculate(PNs *pns1, PNs *pns2){
    PNs* resultPNs = initPolyNs();
    PN *pn1 = pns1->header->next, *pn2 = pns2->header->next;
    while(pn1!=NULL && pn2!=NULL){
        if(pn1->exp < pn2->exp){
            addPN(resultPNs, pn2->coef, pn2->exp);
            pn2 = pn2->next;
        }else if(pn1->exp > pn2->exp){
            addPN(resultPNs, pn1->coef, pn1->exp);
            pn1 = pn1->next;
        }else if(pn1->exp == pn2->exp){
            addPN(resultPNs, pn1->coef+pn2->coef, pn2->exp);
            pn1 = pn1->next;
            pn2 = pn2->next;
        }
    }
    while(pn1!=NULL){ 
        addPN(resultPNs, pn1->coef, pn1->exp);
        pn1 = pn1->next;
    }
    while(pn2!=NULL){
        addPN(resultPNs, pn2->coef, pn2->exp);
        pn2 = pn2->next;
    }

    return resultPNs;
}

void print(PNs *pns){
    PN *p = pns->header->next;
    while(p->next!=NULL){
        if(p->coef != 0 && p->exp != 0){
            printf(" %d %d",p->coef, p->exp);
        }
        p = p->next;
    }
    if(p->coef != 0 
    // && p->exp != 0
    ){
        printf(" %d %d\n",p->coef, p->exp);
    }
}


/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0

2
2 7 3 0 
3   
-3 10 3 7 -3 0
*/