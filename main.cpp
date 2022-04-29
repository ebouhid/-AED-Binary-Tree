//
//  main.cpp
//  F9_ABB
//
//  Created by Eduardo Bouhid Neto on 09/10/21.
//

#include <iostream>
#include "ABB.hpp"

using namespace std;

void manipulaArvore(ABB* tree);

int main() {
    //Decl. Globais
    ABB* tree = nullptr;
    
    cout << "Iniciando manipulacao da arvore" << endl;
    manipulaArvore(tree);
    
    return 0;
}

void manipulaArvore(ABB* tree) {
    
    //Decl. Locais
    int x, soma, nosComUmFilho;
    int controle = 0;
    bool deuCerto;
    while (controle != 4) {
        
        cout << "O que deseja fazer?" << endl;
        cout << "1. Adicionar um inteiro a arvore" << endl;
        cout << "2. Remover um elemento da arvore" << endl;
        cout << "3. Calcular a soma de todos os elementos da arvore" << endl;
        cout << "4. Encerrar a manipulação" << endl;
        cout << "5. Imprimir" << endl;
        cout << "6. Contar a qtd de nós com um unico filho" << endl;
        cin >> controle;
        std::cin.ignore(256,'\n');
        switch (controle) {
            case 1:
                cout << "Digite um inteiro para adicionar a arvore: ";
                cin >> x;
                tree->insere(&tree, x, &deuCerto);
                if (deuCerto) {
                    tree->imprimeTodos();
                    cout << "\n";
                } else {
                    cout << "Erro na insercao" << endl;
                }
                break;
            case 2:
                cout << "Digite o elemento a ser removido: ";
                cin >> x;
                tree->remove(&tree, x, &deuCerto);
                if (deuCerto) {
                    tree->imprimeTodos();
                    cout << "\n";
                } else {
                    cout << "Erro na remocao" << endl;
                }
                break;
            case 3:
                soma = tree->somaRecursiva(tree);
                cout << "A soma de todos os elementos da arvore eh: " << soma << endl;
                break;
            case 4:
                cout << "\nEncerrando a manipulacao\n";
                break;
            case 5:
                tree->imprimeTodos();
                cout << "\n";
                break;
            case 6:
                nosComUmFilho = tree->NumeroDeNosCom1UnicoFilho(tree);
                cout << "A quantidade de nos com um unico filho eh: " << nosComUmFilho << endl;
                break;
            default:
                cout << "Codigo invalido; tente novamente, por favor." << endl;
                break;
        }
    }
}
