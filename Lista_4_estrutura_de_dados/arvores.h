#ifndef ARVORES_H
#define ARVORES_H

typedef struct arvore{
    char info;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore* CriaArvoreVazia();
Arvore* CriarArvore(char c, Arvore* sae, Arvore* sad);
void ImprimeArvore(Arvore* arv);
int EstaVazia(Arvore* arv);
Arvore* LiberarArvore(Arvore* arv);
int PertenceArvore(Arvore* arv, char c);


#endif