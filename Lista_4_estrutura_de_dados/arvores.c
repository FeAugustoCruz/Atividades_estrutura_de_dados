#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

Arvore* CriaArvoreVazia(){
    return NULL;    
}

Arvore* CriarArvore(char c, Arvore* sae, Arvore* sad){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    if(novo != NULL){
        novo->info = c;
        novo->esq = sae;
        novo->dir = sad;
        return novo;
    }else{
        printf("Nao foi possivel criar a arvore!\n");
        exit(1);
    }
}

int EstaVazia(Arvore* arv){
    return(arv == NULL);
}

void ImprimeArvore(Arvore* arv){//forma de imprimir pre-ordem
    printf("<");
    if(!EstaVazia(arv)){
        printf("%c", arv->info);
        ImprimeArvore(arv->esq);
        ImprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* LiberarArvore(Arvore* arv){
    if(!EstaVazia(arv)){
        LiberarArvore(arv->esq);
        LiberarArvore(arv->dir);
        printf("REMOVIDO - %c\n", arv->info);
        free(arv);
    }
    return NULL;
}

int PertenceArvore(Arvore* arv, char c){
    if(!EstaVazia(arv)){
        if(c == arv->info){
            return 1;
        }else{
            return(PertenceArvore(arv->esq, c) || PertenceArvore(arv->dir, c));
        }
    }
    return 0;
}