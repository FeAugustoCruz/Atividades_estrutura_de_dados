#include <stdio.h>
#include <stdlib.h>

typedef struct arvore4{
    int chave;
    struct arvore4 *dir;
    struct arvore4 *mei;
    struct arvore4 *esq;
}Arvore4;

Arvore4* CriaArvoreVazia(){
    return NULL;    
}

Arvore4* CriarArvore(int c, Arvore4* sae, Arvore4* mei, Arvore4 * sad){
    Arvore4* novo = (Arvore4*)malloc(sizeof(Arvore4));
    if(novo != NULL){
        novo->chave = c;
        novo->esq = sae;
        novo->dir = sad;
        novo->mei = mei;
        return novo;
    }else{
        printf("Nao foi possivel criar a arvore!\n");
        exit(1);
    }
}

int EstaVazia(Arvore4* arv){
    return(arv == NULL);
}

int QtdeCelulas(Arvore4 *a){
    if(EstaVazia(a)){
        return 0;
    }
    if(!EstaVazia(a)){
        return 1 + QtdeCelulas(a->esq) + QtdeCelulas(a->mei) + QtdeCelulas(a->dir);
    }
}

int main(void){
    Arvore4 *tree;
    tree = CriarArvore(4, CriaArvoreVazia(), CriaArvoreVazia(), CriaArvoreVazia());
    tree->esq = CriarArvore(3, CriaArvoreVazia(), CriaArvoreVazia(), CriaArvoreVazia());
    tree->esq->mei = CriarArvore(1, CriaArvoreVazia(), CriaArvoreVazia(), CriaArvoreVazia());
    tree->esq->mei->dir = CriarArvore(7, CriaArvoreVazia(), CriaArvoreVazia(), CriaArvoreVazia());
    tree->mei = CriarArvore(2, CriaArvoreVazia(), CriaArvoreVazia(), CriaArvoreVazia());

    printf("%d\n", QtdeCelulas(tree));
    return 0;

}