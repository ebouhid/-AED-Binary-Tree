//
//  ABB.cpp
//  F9_ABB
//
//  Created by Eduardo Bouhid Neto on 09/10/21.
//

#include "ABB.hpp"
#include <iostream>
//Cria
ABB::ABB() {
    this->esq = nullptr;
    this->dir = nullptr;
}

void ABB::destroi(ABB *R) {
    free (R);
}

bool ABB::Vazia() {
    if (this == nullptr) {
        return true;
    } else {
        return false;
    }
}

void ABB::insere(ABB** R, int x, bool* deuCerto) {
    if (*R == nullptr) {
        ABB* novo = new ABB();
        novo->info = x;
        *R = novo;
        *deuCerto = true;
    } else if ((*R)->info == x) {
        *deuCerto = false;
    } else if ((*R)->info < x) {
        insere(&((*R)->dir), x, deuCerto);
    } else if ((*R)->info > x) {
        insere(&((*R)->esq), x, deuCerto);
    }
}

int ABB::contaFilhos() {
    int nFilhos = 0;
    if (this->esq != NULL) {nFilhos++;}
    if (this->dir != NULL) {nFilhos++;}
    return nFilhos;
}

int ABB::NumeroDeNosCom1UnicoFilho (ABB* R) {
    if (R->esq == NULL and R->dir == NULL) {
        return 0;
    }
    if (R->esq != NULL && R->dir == NULL) {
        return 1 + NumeroDeNosCom1UnicoFilho(R->esq);
    } else if (R->esq == NULL && R->dir != NULL) {
        return 1 + NumeroDeNosCom1UnicoFilho(R->dir);
    } else {
        return NumeroDeNosCom1UnicoFilho(R->esq) + NumeroDeNosCom1UnicoFilho(R->dir);
    }
}

void ABB::remove(ABB** R, int x, bool *deuCerto) {
    if (estaNaArvore(*R, x)) {
        *deuCerto = true;
        if ((*R)->info == x) {
            switch ((*R)->contaFilhos()) {
                case 0:
                    (*R)->destroi(*R);
                    *R = nullptr;
                    break;
                case 1:
                    if ((*R)->esq != NULL) {
                        ABB* aux = (*R);
                        *R = (*R)->esq;
                        aux->destroi(aux);
                    } else {
                        ABB* aux = (*R);
                        *R = (*R)->dir;
                        aux->destroi(aux);
                    }
                    break;
                case 2:
                    {
                        //Buscando o maior elemento da subarvore esquerda
                        ABB* RAux = (*R)->esq;
                        while (RAux->dir != NULL) {
                            RAux = RAux->dir;
                        }
                        int maiorDaEsq = RAux->info;
                        (*R)->remove(R, maiorDaEsq, deuCerto);
                        (*R)->info = maiorDaEsq;
                        break;
                    }

                default:
                    break;
            }
        } else {
            if (x < (*R)->info) {
                (*R)->remove(&((*R)->esq), x, deuCerto);
            } else {
                (*R)->remove(&((*R)->dir), x, deuCerto);
            }
        }
    } else {
        *deuCerto  =false;
    }
}

bool ABB::estaNaArvore(ABB *tree, int x) {
    if (tree == nullptr) {
        return false;
    } else if (tree->info == x) {
        return true;
    } else if (x < tree->info) {
        return tree->estaNaArvore(tree->esq, x);
    } else {
        return tree->estaNaArvore(tree->dir, x);
    }
}

int ABB::somaRecursiva(ABB *R) {
    if (R == NULL) {
        return 0;
    } else {
        switch (R->contaFilhos()) {
            case 0:
                return R->info;
                break;
            case 1:
                if (R->esq != NULL) {
                    return somaRecursiva(R->esq) + R->info;
                } else {
                    return somaRecursiva(R->dir) + R->info;
                }
            case 2:
                return R->info + somaRecursiva(R->esq) + somaRecursiva(R->dir);
                break;
            default:
                return -1;
                break;
        }
    }
}

void ABB::imprimeTodos() {
    if (this == NULL) {
        std::cout << "Arvore vazia." << std::endl;
    } else {
        std::cout << this->info << " ";
        if (this->esq != NULL) {this->esq->imprimeTodos();}
        if (this->dir != NULL) {this->dir->imprimeTodos();}
    }
}
