#ifndef ARVORESBUSCA_H
#define ARVORESBUSCA_H

typedef struct arvore{
    int info;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore* BuscaArvore(Arvore* arv, int i);
Arvore* InsereArvore(Arvore* arv, int i);
Arvore* RemoveArvore(Arvore* arv, int i);
int EstaVazia(Arvore* arv);
Arvore* CriaArvoreVazia();
void ImprimeArvore(Arvore* arv);


#endif