#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int num;
    struct nolista *prox;
}NoLista;

void CriarLista(NoLista **l){
    *l = NULL;
}

int EstaVazia(NoLista **l){
    return((*l) == NULL);
}

int InsereElementoInit(NoLista **l, int n){
    NoLista *p = (NoLista*)malloc(sizeof(NoLista));
    if(p != NULL){
            p->num = n;
            p->prox = (*l);
            (*l) = p;
    }else{
        printf("Nçao foi possivel armazenar o valor!\n");
    }
}

void RemoverElemento(NoLista **l, int v){
    NoLista *p, *aux = NULL;
    for(p = *l; p != NULL && p->num != v; p = p->prox){
        aux = p;
    }
    if(p != NULL){
        if(aux == NULL){
            (*l) = p->prox;
        }else{
            aux->prox = p->prox;
        }
        free(p);
    }else{
        printf("Elemento nao encontrado!\n");
    }
}

void Imprime(NoLista **l){
    NoLista *p; 
    for(p = *l; p != NULL; p = p->prox){
        printf("Valor: %d\n", p->num);
    }
}

void Libera(NoLista **l){
    NoLista *p, *ant;
    for(p = *l; p != NULL; p = ant){
        ant = p->prox;
        //printf("ELEMENTO ELIMINADO\n");
        free(p);
    }
}

NoLista* Ultimo(NoLista **l){//<- (1) a)
    NoLista* p;
    for(p = *l; p->prox != NULL; p = p->prox);
    return p;
}

int Maiores(NoLista **l, int n){//<- (1) (b)
    NoLista *p;
    int numero = 0;
    for(p = *l; p != NULL; p = p->prox){
        if(p->num > n){
            numero++;
        }
    }
    return numero;
}

NoLista* Concatena(NoLista **l1, NoLista **l2){//<- (1) (c)
    NoLista *p;
    if (!EstaVazia(l1)){
        for(p = *l1; p->prox != NULL; p = p->prox);
        p->prox = *l2;
    }else{
        *l1 = *l2;
    }
    return *l1;

}

NoLista* Separa(NoLista** l, int n){//<- (1) (d) 
    NoLista *p, *l2 = NULL;
    for(p = *l; p != NULL && p->num != n; p = p->prox);
    if(p == NULL){
        printf("Elemento nao encontrado\n");
        return NULL;
    }else{
        if (Ultimo(l)->num == p->num){
            printf("Impossivel separar o ultimo elemento\n");
            return NULL;
        }else{
            l2 = p->prox;
            p->prox = NULL;
        }
    }
    return l2;
}

void ImprimeRecursiva(NoLista** l){//<- (2) (a)
    NoLista *p = *l;
    if(p == NULL){
        return;
    }else{
        printf("%d\n", p->num);
        return ImprimeRecursiva(&(*l)->prox);
    }
}

void ImprimeRecursivaInversa(NoLista** l){//<- (2) (b)
   NoLista *p = *l;
    if(p == NULL){
        return;
    }else{
        ImprimeRecursiva(&(*l)->prox);
        printf("%d\n", p->num);
    }

}

void LiberarListaRecursiva(NoLista **l){//<- (2) (c)
    NoLista *p = *l, *aux;
    if(p == NULL){
        return;
    }else{
        aux = p->prox;
        free(p);
        LiberarListaRecursiva(&aux);
    }
}

NoLista* BuscarRecursiva(NoLista **l, int n){//<- (2) (d)
    NoLista *p = *l;
    if(p == NULL){
        printf("Nao foi possivel encontrar o elemento\n");
        return NULL;
    }
    if (p->num == n){
        return p;
    }
    else{
        BuscarRecursiva(&(*l)->prox, n);
    }
}

void RemoverElementoRecursiva(NoLista **l, int n){//<- (2) (e)
    NoLista *p = *l;
    if(p == NULL){
        printf("Elemento nao encontrado!\n");
        return;
    }else{
        if(p->num == n){
            *l = p->prox;
            free(p);
            return;
        }
    }
    return RemoverElementoRecursiva(&(p->prox)  , n);
}

int main(void){
    NoLista *lista1, *lista2, *lista3;
    CriarLista(&lista1);
    //CriarLista(&lista2);
    InsereElementoInit(&lista1, 5);
    InsereElementoInit(&lista1, 2);
    InsereElementoInit(&lista1, 1);

    //lista3 = BuscarRecursiva(&lista1, 2);
    //if(lista3 != NULL){
    //    printf("%d\n", lista3->num);
    //}

    RemoverElementoRecursiva(&lista1, 1);

    Imprime(&lista1);

    //InsereElementoInit(&lista2, 8);
    //InsereElementoInit(&lista2, 10);

    //lista1 = Concatena(&lista1, &lista2);

    //lista3 = Separa(&lista1, 12);

    //Imprime(&lista3);
    //ImprimeRecursiva(&lista1);
    //ImprimeRecursivaInversa(&lista1);
    //NoLista *n = Ultimo(&lista);
    //printf("Ultimo: %d\n", n->num);
    //printf("Quantida maior : %d", Maiores(&lista, -10));

    //Imprime(&lista);
    LiberarListaRecursiva(&lista1);
    //Libera(&lista2);
    //Libera(&lista3);
    return 0;
}