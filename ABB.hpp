//
//  ABB.hpp
//  F9_ABB
//
//  Created by Eduardo Bouhid Neto on 09/10/21.
//

#ifndef ABB_hpp
#define ABB_hpp

#include <stdio.h>

class ABB {
public:
    ABB();
    void destroi(ABB* R);
    //Inclua no TAD as Operações cria, vazia, insere, remove, destrói e está_na_árvore;
    bool Vazia();
    void insere(ABB** R, int x, bool* deuCerto);
    bool estaNaArvore(ABB* R, int X);
    int contaFilhos();
    int NumeroDeNosCom1UnicoFilho(ABB* R);
    void remove(ABB** R, int x, bool* deuCerto);
    int somaRecursiva(ABB* R);
    void imprimeTodos();
    //ABB* R;
    ABB* esq;
    ABB* dir;
    int info;
};

#endif /* ABB_hpp */
