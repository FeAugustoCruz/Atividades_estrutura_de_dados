#ifndef PILHAS_H
#define PILHAS_H

typedef struct nolista{
    struct nolista* prox;
    float info;
}NoLista;


typedef struct pilha{
    NoLista* prim;
}Pilha;

Pilha* CriarPilha();
int EstaVazia(Pilha* l);
void Push(Pilha *l, float v);
float Pop(Pilha *l);
void ImprimePilha(Pilha* l);
void EsvaziaPilha(Pilha* l);


#endif