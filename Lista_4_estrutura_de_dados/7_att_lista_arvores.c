#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

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
    }else if (i >= arv->info){
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
    }
    printf(">");
}

int Ocorrencias_X(Arvore *a, int x){//<- (7) (a)
    int cont = 0;
    if(a == NULL){
        return 0;
    }else if(x < a->info){
        return cont + Ocorrencias_X(a->esq, x);
    }else if (x > a->info)
        return cont + Ocorrencias_X(a->dir, x);
    else{//Caso o volor seja igual a x, verificamos a direita
        
        return 1 + Ocorrencias_X(a->dir, x);
    }
}

void ImprimeArvoreDecescente(Arvore* a){//<- (7) (b)
    if(!EstaVazia(a)){
        if(a->esq == NULL && a->dir == NULL){
            printf("Folha - %d\n", a->info);
        }
        ImprimeArvoreDecescente(a->dir);
        ImprimeArvoreDecescente(a->esq);
    }
}

int main(void){
    Arvore* tree;
    tree = CriaArvoreVazia();
    tree = InsereArvore(tree, 2);
    tree = InsereArvore(tree, 6);
    tree = InsereArvore(tree, 6);
    tree = InsereArvore(tree, 1);

    ImprimeArvoreDecescente(tree);
    return 0;
}