#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
}NoLista;

typedef struct descritor{
    NoLista *ult;
    NoLista *prim;
    int quantidade;
}Descritor;

void CriarLista(Descritor *l){
    l->ult = NULL;
    l->prim = NULL;
}

int EstaVazia(Descritor *l){
    return(l->ult == NULL && l->prim == NULL);
}

void InserirElemento(Descritor *l, int n){
    NoLista *p;
    p = (NoLista*)malloc(sizeof(NoLista));
    if(p != NULL){
        p->info = n;
        p->prox = l->prim;
        l->prim = p;
        if(EstaVazia(l)){
            l->ult = p;
        }
        l->quantidade++;
    }else{
        printf("Nao foi possivel alocar o elemento\n");
    }
}

void Imprimir(Descritor *l){
    NoLista *p;
    for(p = l->prim; p != l->ult; p = p->prox){
        printf("%d\n", p->info);
    }
}

NoLista* Ultima(Descritor *l){//<- (1) (a)
    if(!EstaVazia(l)){
        NoLista *p;
        for(p = l->prim; p->prox != l->ult; p = p->prox);
        return p;
    }else{
        printf("Essa lista esta vazia!\n");
        return NULL;
    }
}

void RemoverElemento(Descritor *l, int v){//<- (1) (b)
    NoLista *p, *ant = NULL;
    for(p = l->prim; p != l->ult && p->info != v; p = p->prox){
        ant = p;
    }
    if(p != l->ult){
        if(ant == NULL){
            l->prim = p->prox;
        }else if(p->prox == NULL){
            ant->prox = p->prox;
            l->ult = ant;
        }else{
            ant->prox = p->prox;
        }
        free(p);
    }else{
        printf("Elemento nao encontrado\n");
    }
}

int Maiores(Descritor *l, int n){//<- (1) (c)
    if(!EstaVazia(l)){
        NoLista *p;
        int quantidade = 0;
        for(p = l->prim; p != l->ult; p = p->prox){
            if (p->info > n){
                quantidade++;
            }
        }
        return quantidade;
    }else{
        printf("Essa lista esta vazia!\n");
        return 0;
    }
}

Descritor Concantana(Descritor *l1, Descritor *l2){//<- (1) (d)
    NoLista *p;
    if(!EstaVazia(l1)){
        l1->ult = l2->ult;
        Ultima(l1)->prox = l2->prim;
        l2->prim = NULL;
        l2->ult = NULL;
        return *l1;
    }else{
        printf("A lista 1 esta vazia");
        return *l2;
    }

}

void Separa(Descritor*m, Descritor *l, int i){//<- (1) (e)
    NoLista *p, *novo;
    for(p = l->prim; p != l->ult && p->info != i; p = p->prox);
    if(p != l->ult){
        if(Ultima(l)->info == p->info){
            printf("Impossivel separar o ultimo elmento (retorno null)");
            return;
        }else{
            novo = p->prox;
            p->prox = NULL;

            m->prim = novo;
            m->ult = Ultima(m);
        }
    }else{
        printf("Ellemento nao encontrado\n");
    }

}

void ImprimeRecursiva(NoLista *l, Descritor* m){// (2) (a)
    NoLista *p = l;
    if(p == m->ult){
        return;
    }else{
        printf("%d\n", p->info);
        ImprimeRecursiva((p->prox), m);
    }
}

void ImprimeRecursivaInversa(NoLista *l, Descritor* m){//<- (2) (b)
    NoLista *p = l;
    if (p == m->ult){
        return;
    }else{
        ImprimeRecursivaInversa((p->prox), m);
        printf("%d\n", p->info);
    }
}   


void LiberaLista(NoLista * l ,Descritor *m){//<- (2) (c)
    NoLista *p = l;
    NoLista *ant;
    if (p != m->ult){
        ant = p->prox;
        printf("Elemento %d (Eliminado)\n", p->info);
        free(p);
    }else{
        return;
    }
    LiberaLista(ant , m);

}

NoLista* BuscaRecursiva(NoLista* m ,Descritor *l, int i){//<- (2) (d)
    NoLista *p = m;
    if(p == l->ult){
        printf("Elemento nao encontrado!\n");
        return NULL;
    }else{
        if(p->info == i){
            return p;
        }
    }
    BuscaRecursiva(p->prox, l, i);
}


void RemoverElementoRecursiva(NoLista **l, int v, Descritor *d){//<- (2) (e)
    NoLista *p = *l;

    if (p == NULL) {
        printf("Elemento não encontrado!\n");
        return;
    }

    if (p->info == v) {
        *l = p->prox;

        // Atualiza o descritor se necessário
        if (d->prim == p) d->prim = p->prox;
        if (d->ult == p) d->ult = NULL; // caso seja o único

        free(p);
        return;
    }

    // chamada recursiva com o próximo nó
    RemoverElementoRecursiva(&(p->prox), v, d);
}

int main(void){
    Descritor lista;
    Descritor novalista;
    CriarLista(&novalista);
    CriarLista(&lista);
    InserirElemento(&lista, 5);
    InserirElemento(&lista, 1);
    InserirElemento(&lista, -34);
    InserirElemento(&novalista, 3);
    InserirElemento(&novalista, 8);

    //novalista = Concantana(&novalista, &lista);//<- descarta a lista1

    //ImprimeRecursivaInversa(novalista.prim, &novalista);

    ///NoLista *p = Ultima(lista);
    //if(p != NULL){
    //    printf("%i", p->info);
    //}

    //Separa(&novalista, &lista, 1);

    //Imprimir(&novalista);
    //printf("-------------\n");
    //Imprimir(&lista);

    //Imprimir(novalista);
    //Imprimir(lista);
    //int n = Maiores(lista, -400);
    //printf("%d\n", n);
    //RemoverElemento(lista, 1);

    //Imprimir(lista);

    //NoLista *a = BuscaRecursiva(lista.prim, &lista, 5);
    //if(a != NULL){
    //    printf("Valor: %d\n", a->info);
    //}
    RemoverElementoRecursiva(&lista.prim, 5, &lista);
    LiberaLista(lista.prim, &lista);
    return 0;
}