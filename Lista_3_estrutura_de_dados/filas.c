#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

Fila* CriaFila(){
    Fila* p = (Fila*)malloc(sizeof(Fila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}

int EstaVazia(Fila* f){
    return (f->ini == NULL);
}

void InsereFila(Fila* f, float v){
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL){
        novo->info = v;
        novo->prox = NULL;
        if(EstaVazia(f)){
            f->ini = novo;
            f->fim = f->ini;
        }else{
            f->fim->prox = novo;
            f->fim = novo;
        }
    }else{
        printf("Nao foi possivel armazenar o valor!\n");
    }
}

void ImprimeFila(Fila* f){
    for(NoLista* p = f->ini; p != NULL; p = p->prox){
        printf("[%.2f]\n", p->info);
    }
}

float RemoverFila(Fila* f){
    if(!EstaVazia(f)){
        NoLista* p;
        p = f->ini;
        f->ini = p->prox;
        if(f->ini == NULL){
            f->fim = NULL;
        }
        float v = p->info;
        free(p);
        return v;
    }else{
        printf("Esta vazia!\n");
    }   
}

void EsvaziaFila(Fila* f){
    NoLista* aux = NULL;
    for(NoLista *p = f->ini; p != NULL; p = aux){
        aux = p->prox;
        free(p);
        //printf("LIBERADO\n");
    }    
}