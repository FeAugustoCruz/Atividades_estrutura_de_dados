#include <stdlib.h>
#include <stdio.h>
#include "pilhas.h"

void ConcatenaPilhas(Pilha* p1, Pilha* p2){//<- (3) (a)
    Pilha* p;
    NoLista *l;
    p = CriarPilha();
    if(!EstaVazia(p2)){
        while(!EstaVazia(p2)){
            Push(p, Pop(p2));
        }
        for(l = p->prim; l != NULL; l = l->prox){
            Push(p1, l->info);
        }
    }
    EsvaziaPilha(p2);
    EsvaziaPilha(p);
}

void ConcatenaPilhasRec(Pilha* p1, Pilha* p2){//<- (3) (b)

    if(!EstaVazia(p2)){
        float valor = Pop(p2);
        ConcatenaPilhasRec(p1, p2);
        Push(p1, valor);
    }
}

void ConcatenaPilhas3(Pilha *p1, Pilha* p2){//<- (3) (c)
    NoLista* p;    
    for(p = p2->prim; p->prox != NULL; p = p->prox);
    p->prox = p1->prim;
    p1->prim = p2->prim;
    
    p2->prim = NULL;
    free(p2);
}

int main(void){

    Pilha* lista_pilha1, *lista_pilha2;
    lista_pilha1 = CriarPilha();
    lista_pilha2 = CriarPilha();
    Push(lista_pilha1, 5.5);
    Push(lista_pilha1, 10);
    Push(lista_pilha2, 6.4);
    Push(lista_pilha2, 7);
    Push(lista_pilha2, 8.7);

    /*ImprimePilha(lista_pilha1);
    printf("-------------------\n");
    ImprimePilha(lista_pilha2);
    printf("-------------------\n");
    */

    ConcatenaPilhas3(lista_pilha1, lista_pilha2);
    ImprimePilha(lista_pilha1);
    EsvaziaPilha(lista_pilha1);
}