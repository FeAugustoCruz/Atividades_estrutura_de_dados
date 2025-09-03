#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"


Pilha* CriarPilha(){
    Pilha* l = (Pilha*)malloc(sizeof(Pilha));
    l->prim = NULL;
    return l;
}

int EstaVazia(Pilha* l){
    return(l->prim == NULL);
}

void Push(Pilha *l, float v){
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL){
        novo->info = v;
        novo->prox = NULL;
        if(EstaVazia(l)){
            l->prim = novo;
        }else{
            novo->prox = l->prim;
            l->prim = novo;
        }
    }else{
        printf("Nao foi possivel armazenar na pilha!\n");
    }
}

float Pop(Pilha *l){
    if(!EstaVazia(l)){
        NoLista*p = l->prim;
        float v = p->info;
        l->prim = p->prox;
        free(p);
        return v;
    }else{
        printf("A pilha esta vazia!\n");
    }

}

void ImprimePilha(Pilha* l){
    if(!EstaVazia(l)){
        for(NoLista *p = l->prim; p != NULL; p = p->prox){
            printf("[%.2f]\n", p->info);
        }
    }else{
        printf("A pilha esta vazia!\n");
    }
}

void EsvaziaPilha(Pilha* l){
    NoLista *aux;
    for(NoLista* p = l->prim; p!= NULL; p = aux){
        aux = p->prox;
        free(p);
    }
    free(l);
}
