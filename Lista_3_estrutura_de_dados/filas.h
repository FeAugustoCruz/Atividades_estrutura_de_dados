#ifndef FILAS_H
#define FILAS_H

typedef struct nolista{
    struct nolista* prox;
    float info;
}NoLista;

typedef struct fila{
    NoLista* fim;
    NoLista* ini;
}Fila;

Fila* CriaFila();
int EstaVazia(Fila* f);
void InsereFila(Fila* f, float v);
void ImprimeFila(Fila* f);
float RemoverFila(Fila* f);
void EsvaziaFila(Fila* f);


#endif