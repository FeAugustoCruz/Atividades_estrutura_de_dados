#include <stdlib.h>
#include <stdio.h>
#include "arvores.h"

int QtdeFolhas(Arvore* a){//<- (2) (a)
    if(a->dir == NULL && a->esq == NULL){
        return 1;
    }else{
        return QtdeFolhas(a->esq) + QtdeFolhas(a->dir);
    }
}

int QtdeChar(Arvore*a, char c){//<- (2) (b)
    int cont;
    if(a == NULL){
        return 0;
    }

    if(a->info == c){
        cont = 1;
    }else{
        cont = 0;
    }

    return cont + QtdeChar(a->esq, c) + QtdeChar(a->dir, c);
}

int Iguais(Arvore *a, Arvore *b){//<- (2) (c)
    if(EstaVazia(a) && EstaVazia(b)){
        return 1;
    }
    if(!EstaVazia(a) && EstaVazia(b)){
        return 0;
    }
    if(!EstaVazia(b) && EstaVazia(a)){
        return 0;
    }
    if(!EstaVazia(a) && !EstaVazia(b)){
        if(a->info != b->info){
            return 0;
        }
        return 1 && (Iguais(a->esq, b->esq) && Iguais(a->dir, b->dir));
    }
}

Arvore* Copia(Arvore *a){//<- (2) (d)
    if(!EstaVazia(a)){
        Arvore* f = (Arvore*)malloc(sizeof(Arvore));
        f->info = a->info;
        f->esq = NULL;
        f->dir = NULL;
        f->esq = Copia(a->esq);
        f->dir = Copia(a->dir);
        return f;
    }
    return NULL;
}

int main(void){
    Arvore *tree = CriarArvore('a', CriaArvoreVazia(), CriaArvoreVazia());
    tree->esq = CriarArvore('b', CriaArvoreVazia(), CriaArvoreVazia());
    tree->dir = CriarArvore('c', CriaArvoreVazia(), CriaArvoreVazia());

    Arvore *tree2 = Copia(tree);
    ImprimeArvore(tree2);
    //printf("%d", Iguais(tree, tree2));
}