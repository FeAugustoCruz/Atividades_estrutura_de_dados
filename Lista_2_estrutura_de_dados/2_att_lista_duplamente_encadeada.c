#include <stdlib.h>
#include <stdio.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
    struct nolista *ant;
}NoLista;

void CriarLista(NoLista **l){
    *l = NULL;
}

int EstaVazia(NoLista** l){
    return((*l) == NULL);
}

void InserirElemento(NoLista **l, int n){
    NoLista *p = (NoLista*)malloc(sizeof(NoLista));
    if(p != NULL){
        p->info = n;
        p->prox = NULL;
        p->ant = NULL;
        if(EstaVazia(l)){
            *l = p;
        }else{
            p->prox = (*l);
            (*l)->ant = p;
            (*l) = p;
        }
    }else{
        printf("Não foi cadsatrar o valor\n");
    }
}

void Imprimir(NoLista **l){
    NoLista* p;
    for(p = *l; p != NULL; p = p->prox){
        printf("%d\n", p->info);
    }
}

void RemoverElemento(NoLista** l, int n){
    NoLista *p;
    for(p = *l; p != NULL && p->info != n; p = p->prox);
    if(p != NULL){
        if(p->ant == NULL){
            (*l) = p->prox;
            p->prox->ant = p->ant;
        }
        else if(p->prox == NULL){
            p->ant->prox = p->prox;
        }
        else{
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
        }
        free(p);
    }else{
        printf("Elemento nao encontrado\n");
    }
}

NoLista* Ultimo(NoLista **l){//<- (1) (a)
    if(!EstaVazia(l)){
        NoLista *p = *l;
        for(p = *l; p->prox != NULL; p = p->prox);
        return p;
    }else{
        printf("Lista vazia!\n");
    }
}

int Maiores(NoLista** l, int n){//<- (1) (b)
    NoLista* p;
    int contador = 0;
    for(p = *l; p != NULL; p = p->prox){
        if (p->info > n){
            contador++;
        }
    }

    return contador;
}

NoLista* Concatena(NoLista **l1, NoLista **l2){//<- (1) (c)
    NoLista *p;
    if(!EstaVazia(l1)){
        for(p = *l1; p->prox != NULL; p = p->prox);
        p->prox = *l2;
    }
    else{
        *l1 = *l2;
    }

    return *l1;
}

NoLista* Separa(NoLista** l, int n){//<- (1) (d)
    NoLista *p, *novo = NULL;
    for(p = *l; p != NULL && p->info != n; p = p->prox);
    if(p != NULL){
        if(Ultimo(l)->info == p->info){
            printf("Impossivel separar o ultimo elemento\n");
            return NULL;
        }else{
            novo = p->prox;
            novo->ant = NULL;//<-- Importante para a duplamente encadeada
            p->prox = NULL;
        }
    }else{
        printf("Elemento não encontrado\n");
        return NULL;
    }
    return novo;
}

void ImprimeRecursiva(NoLista **l){//<- (2) (a)
    NoLista *p = *l;
    if(p == NULL){
        return;
    }else{
        printf("%d\n", p->info);
        ImprimeRecursiva(&(p->prox));
    }
}

void ImprimeRecursivaInversa(NoLista **l){//<- (2) (b)
    NoLista* p = *l;
    if(p == NULL){
        return;
    }else{
        ImprimeRecursivaInversa(&(p->prox));
        printf("%d\n", p->info);
    }
}

NoLista* BuscaRecursiva(NoLista **l, int v){//<- (2) (c)
    NoLista *p = *l;
    if(p == NULL){
        printf("Elemento nao encontrado\n");
        return NULL;
    }
    if(p->info == v){
        return p;
    }
    BuscaRecursiva(&(p->prox), v);
}

void RemoverElementoRecursivo(NoLista **l, int v){//<- (2) (d)
    NoLista *p = *l;
    if(p == NULL){
        printf("Elemento nao encontrado!\n");
        return;
    }
    if(p->info == v){

        if(p->ant == NULL){
            p->prox->ant = p->ant;
            *l = p->prox;
        }else if(p->prox == NULL){
            p->ant->prox = p->prox;
        }else if(p->ant == NULL && p->prox == NULL){
            *l = NULL;
        }else{
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
        }
        free(p);
        return;
    }
    RemoverElementoRecursivo(&(p->prox), v);
}

int main(void){
    NoLista* lista, *lista2, *lista3;
    CriarLista(&lista);
    CriarLista(&lista3);
    InserirElemento(&lista, 4);
    InserirElemento(&lista, 6);
    InserirElemento(&lista, 8);

    //InserirElemento(&lista2, 4);
    //InserirElemento(&lista2, 1);

    //lista3 = Concatena(&lista, &lista2);

    //NoLista* lista4 = BuscaRecursiva(&lista, 42);
    //if(lista4 != NULL){
    //    printf("Valor: %d", lista4->info);
    //}

    //ImprimeRecursiva(&lista);

    //lista3 = Separa(&lista, 6);
    //if (lista3 != NULL){
    //    Imprimir(&lista3);
    //}

    RemoverElementoRecursivo(&lista, 4);
    ImprimeRecursivaInversa(&lista);
    //NoLista *n = Ultimo(&lista);
    //int total = Maiores(&lista, 1000);
    //printf("Ultimo: %d\n", n->info);
    //printf("Quantidade maiores: %d", total);
    //Imprimir(&lista);

    return 0;
}