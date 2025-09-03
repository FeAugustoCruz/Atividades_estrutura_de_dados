#include <stdlib.h>
#include <stdio.h>
#include "arvoresbusca.h"

Arvore* BuscaArvore(Arvore* arv, int i){
    if(arv->info == i){
        return arv;
    }else if(arv->info < i){
        BuscaArvore(arv->dir, i);
    }else if(arv->info > i){
        BuscaArvore(arv->esq, i);
    }else{
        return NULL;
    }
}

Arvore* CriaArvoreVazia(){
    return NULL;    
}

int EstaVazia(Arvore* arv){
    return(arv == NULL);
}

Arvore* InsereArvore(Arvore* arv, int i){
    if(EstaVazia(arv)){
        arv = (Arvore*)malloc(sizeof(Arvore));
        arv->info = i;
        arv->dir = NULL;
        arv->esq = NULL;
    }else if(i < arv->info){
        arv->esq = InsereArvore(arv->esq, i);
    }else if (i > arv->info){
        arv->dir = InsereArvore(arv->dir, i);
    }

    return arv;
}

void ImprimeArvore(Arvore* arv){//in-ordem
    printf("<");
    if(!EstaVazia(arv)){
        printf("%d", arv->info);
        ImprimeArvore(arv->esq);
        ImprimeArvore(arv->dir);
        /*ImprimeArvore(arv->esq);
        printf("%d", arv->info);
        ImprimeArvore(arv->dir);*/
    }
    printf(">");
}

Arvore* RemoveArvore(Arvore* arv, int i){
    if(!EstaVazia(arv)){
        if(i == arv->info){
            if(arv->dir == NULL && arv->esq == NULL){
                free(arv);
                arv = NULL;
            }else if (arv->esq == NULL){
                Arvore* p = arv;
                arv = arv->dir;
                free(p);
            }else if(arv->dir == NULL){
                Arvore* p = arv;
                arv = arv->esq;
                free(p);
            }else{//Arvore tem os dois filhos 
                Arvore *f = arv->esq;
                while(f->dir != NULL){
                    f= f->dir;
                }
                arv->info = f->info;
                f->info = i;
                arv->esq = RemoveArvore(arv->esq, i);
            }
        }else if(i < arv->info){
            arv->esq = RemoveArvore(arv->esq, i);
        }else if(i > arv->info){
            arv->dir = RemoveArvore(arv->dir, i);
        }
    }else{
        return NULL;
    }
    printf("teste\n");
    return arv;
}
