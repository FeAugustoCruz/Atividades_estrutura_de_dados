#include <stdlib.h>
#include <stdio.h>

typedef struct nolista{
    struct nolista *prox;
    float info;
}NoLista;

typedef struct fila{
    NoLista *ini;
    NoLista *fim;
}Fila;

Fila* CriarLista(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->fim = f->ini = NULL;
    return f;
}

int EstaVazia(Fila* f){
    return(f->ini == NULL);
}

void InserirFila(Fila* f, float v){
    NoLista* g = (NoLista*)malloc(sizeof(NoLista));
    if(g != NULL){
        g->info = v;
        g->prox = NULL;
        if(!EstaVazia(f)){
            f->fim->prox = g;
            f->fim = g;
        }else{
           f->ini = g;
           f->fim = g; 
        }
    }
}

float RemoverFila(Fila *f){
    if(!EstaVazia(f)){
        NoLista* p = f->ini;
        float value = p->info;
        f->ini = p->prox;
        free(p);
        return value;
    }else{
        printf("A fila esta vazia!\n");
    }
}

void ImprimirFila(Fila* f){
    for(NoLista *p = f->ini; p != NULL; p = p->prox){
        printf("%.2f\n", p->info);
    }
}

void LiberaFila(Fila* f){
    NoLista* aux;
    for(NoLista *p = f->ini; p != NULL; p = aux){
        aux = p->prox;
        printf("Elemento eliminado\n");
        free(p);
    }
}

float MaiorFila(Fila *f){//<- (2)
    if(!EstaVazia(f)){
        float maior = f->ini->info;
        for(NoLista *p = f->ini; p != NULL; p = p->prox){
            if(p->info > maior){
                maior = p->info;
            }
        }
        return maior;
    }
    else{
        printf("Fila vazia!\n");
        return -1;
    }
}

int main(void){
    Fila* fila_lista;
    fila_lista = CriarLista();
    InserirFila(fila_lista, 5.3);
    InserirFila(fila_lista, 1.3);
    InserirFila(fila_lista, 14.4);

    //RemoverFila(fila_lista);

    ImprimirFila(fila_lista);
    printf("-=-=-=-=-=-=-\n");
    printf("%.2f e o maior valor\n", MaiorFila(fila_lista));
    LiberaFila(fila_lista);
    return 0;
}