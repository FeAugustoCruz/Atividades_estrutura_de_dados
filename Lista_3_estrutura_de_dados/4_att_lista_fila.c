#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

void CombinaFila(Fila* f_res, Fila* f1, Fila* f2){//<- (4) (a)
    while(!EstaVazia(f1) || !EstaVazia(f2)){
        if(!EstaVazia(f1)){
            InsereFila(f_res, RemoverFila(f1));
        }
        if(!EstaVazia(f2)){
            InsereFila(f_res, RemoverFila(f2));
        }
    }  
}

void CombinaFilaRec(Fila* f_rec, Fila* f1, Fila* f2){//<- (4) (b)
    if(!EstaVazia(f1) || !EstaVazia(f2)){
        if(!EstaVazia(f1)){
            float v = RemoverFila(f1);
            InsereFila(f_rec, v); 
            CombinaFilaRec(f_rec, f2, f1);
        }
        if(!EstaVazia(f2)){
            float v = RemoverFila(f2);
            InsereFila(f_rec, v); 
            CombinaFilaRec(f_rec, f2, f1);
        }
    }
}

int main(void){
    Fila *fila1, *fila2, *fila3;
    fila1 = CriaFila();
    fila2 = CriaFila();
    fila3 = CriaFila();
    InsereFila(fila1, 2.1);
    InsereFila(fila1, 4.5);
    InsereFila(fila1, 1.0);
    //InsereFila(fila2, 7.2);
    //InsereFila(fila2, 3.1);
    //InsereFila(fila2, 9.8);
    ImprimeFila(fila1);
    printf("-=-=-=-=-\n");
    ImprimeFila(fila2);
    printf("-=-=-=-=-\n");
    CombinaFilaRec(fila3, fila1, fila2);
    ImprimeFila(fila3);
    return 0;
}