#include <stdlib.h>
#include <stdio.h>
#include "arvoresbusca.h"

int MaiorArvore(Arvore* a){// (2) (e)
    if(!EstaVazia(a)){
        while(a->dir != NULL){
            a = a->dir;
        }
        return a->info;
    }
}

int main(void){
    Arvore* tree;
    tree = CriaArvoreVazia();
    tree = InsereArvore(tree, 5);
    tree = InsereArvore(tree, 5);
    tree = InsereArvore(tree, 8);
    tree = InsereArvore(tree, 9);
    tree = InsereArvore(tree, 7);

    //printf("%d", MaiorArvore(tree));
    ImprimeArvore(tree);
}