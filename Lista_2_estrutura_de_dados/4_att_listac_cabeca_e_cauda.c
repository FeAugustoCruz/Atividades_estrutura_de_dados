#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
}NoLista;

typedef struct lista{
    NoLista* cab;
    NoLista* cau;
    int n;
}Lista;

void CriarLista(Lista *l){
    l->cab = (NoLista*)malloc(sizeof(NoLista));
    l->cau = (NoLista*)malloc(sizeof(NoLista));
    l->cab->prox = l->cau;
}

int EstaVazia(Lista *l){
    return(l->cau->prox == l->cab);
}

void InserirElemento(Lista *l, int i){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL){
        novo->info = i;
        novo->prox = l->cab->prox;
        l->cab->prox = novo;
    }else{
        printf("Noa oif possivel amarzenar o elemento na lista\n");
    }
}

void RemoverElemento(Lista *l, int i){
    NoLista *p, *ant = NULL;
    if(!EstaVazia(l)){
        for(p = l->cab->prox; p != l->cau && p->info != i; p = p->prox){
            ant = p;
        }
        if(p != l->cau){
            ant->prox = p->prox;
        }else{
            printf("Elemento nao encontrado\n");
        }
        free(p);
    }else{
        printf("A lista esta vazia!\n");
    }
}

void ImprimirLista(Lista *l){
    NoLista *p;
    for(p = l->cab->prox; p != l->cau; p = p->prox){
        printf("%d\n", p->info);
    }
}

void LiberaLista(Lista *l){
    NoLista *p, *ant;
    for(p = l->cab->prox; p != l->cau; p = ant){
        ant = p->prox;
        free(p);
    }
    l->cab->prox = l->cau;
}

NoLista* Ultimo(Lista *l){//<- (1) (a)
    if(!EstaVazia(l)){
        NoLista *p;
        for(p = l->cab->prox; p->prox != l->cau; p = p->prox);
        return p;
    }else{
        printf("A lista esta vazia!\n");
        return NULL;
    }   
}

int Maiores(Lista *l, int n){//<- (1) (b)
    NoLista *p;
    int quantidades;
    for(p = l->cab->prox; p != l->cau; p = p->prox){
        if(p->info > n){
            quantidades++;
        }
    }

    return quantidades;
}

void Concatena(Lista *l1, Lista *l2) {//<- (1) (c)
    if (l1->cab->prox == l1->cau) {
        // l1 está vazia, então apenas aponta para o conteúdo de l2
        l1->cab->prox = l2->cab->prox;
    } else {
        // encontra o último nó de l1 antes da cauda
        NoLista *p = l1->cab->prox;
        while (p->prox != l1->cau) {
            p = p->prox;
        }
        // conecta o último nó de l1 ao primeiro de l2
        p->prox = l2->cab->prox;
    }

    // faz com que l2 aponte para a sentinela de l1
    NoLista *q = l2->cab;
    while (q->prox != l2->cau) {
        q = q->prox;
    }
    q->prox = l1->cau;

    // esvazia l2
    l2->cab->prox = l2->cau;
}


int main(void){
    Lista lista, lista2;
    CriarLista(&lista);
    CriarLista(&lista2);
    InserirElemento(&lista2, 8);
    InserirElemento(&lista2, 10);
    InserirElemento(&lista, 2);
    InserirElemento(&lista, 1);
    InserirElemento(&lista, 7);

    Concatena(&lista, &lista2);

    ImprimirLista(&lista);

    //NoLista *n = Ultimo(&lista);
    //if(n != NULL){
    //   printf("%d\n", n->info);
    //}

    LiberaLista(&lista);
    return 0;
}