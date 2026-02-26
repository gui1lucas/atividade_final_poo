#include "Pilha.hpp"
#include <iostream>
#include <stdexcept>

Pilha::Pilha(){ // inicializa a pilha com valores válidos
    topo = -1;
    elementos = new int[CAPACIDADE_MAX];
}

Pilha::~Pilha(){ // libera os recursos que a pilha usou
    delete[] elementos;
    elementos = nullptr;
}

bool Pilha::estaCheia() const{
    // como o topo começa em -1, a pilha fica cheia quando o topo chega em 24
    // a comparação vai retornar um valor booleano
    return topo == CAPACIDADE_MAX - 1;
}

bool Pilha::estaVazia() const{
    // se a pilha estiver vazia, o topo vai ser -1
    // também deve retornar um valor booleano
    return topo == -1;
}

void Pilha::empilhar(int valor){
    if(!estaCheia()){
        topo++; // a posição do topo é incrementada em 1 para receber o elemento
        elementos[topo] = valor;
        std::cout << "\nO elemento de valor " << valor << " foi empilhado.\n" << std::endl;
    } else{ // se a pilha estiver cheia, a mensagem de erro será exibida na tela
        throw std::overflow_error("\nA pilha se encontra cheia atualmente.\n");
    }
}

// desempilha e retorna o último elemento desempilhado
int Pilha::desempilhar(){
    if(!estaVazia()){
        int elementoRemovido = elementos[topo];
        topo--; // o topo é decrementado em 1 para remover o elemento
        std::cout << "\nO elemento de valor " << elementoRemovido << " foi desempilhado.\n" << std::endl;
        return elementoRemovido;
    } else{
        // se a pilha estiver vazia, uma exceção é lançada para avisar
        throw std::underflow_error("\nNão há elementos para desempilhar atualmente.\n");
    }
}

int Pilha::consultarTopo() const{
    if(!estaVazia()){
        return elementos[topo]; // pega o elemto que ocupa o topo atualmente
    } else{
        // mesma lógica usada em desempilhar
        throw std::logic_error("\nNão há nenhum elemento na pilha atualmente.\n");
    }
}

int Pilha::consultarTamanho() const{
    // como o topo começa com -1, o tamanho real tem que ser somado a 1
    return topo + 1;
}

void Pilha::consultarTudo() const{
    if(!estaVazia()){
        std::cout << "\n[";
        for(int i = 0; i <= topo; i++){ // o for vai percorrer os elementos da pilha e exibir cada um
            std::cout << elementos[i];
            if(i < topo){
                std::cout << ", ";
            }
        }
        std::cout << "]\n" << std::endl;
    } else{
        std::cout << "\nNão há elementos para exibir atualmente.\n" << std::endl;
    }
}

// não é possível desfazer
void Pilha::ordenar(){ // usei um bubble sort para ordenar
    if(!estaVazia()){
        int tamanho = topo + 1; // como o topo começa com -1, o tamanho real tem que ser somado a 1
        int temporario;

        // controle de voltas pela pilha
        for(int i = 0; i < tamanho - 1; i++){
            for(int j = 0; j < tamanho - i - 1; j++){
                // se j for maior que j + 1, eles trocam de lugar
                if(elementos[j] > elementos[j + 1]){
                    temporario = elementos[j];
                    elementos[j] = elementos[j + 1];
                    elementos[j + 1] = temporario;
                }
            }
        }
        std::cout << "\nOs elementsos foram ordenados." << std::endl;
    } else{
        std::cout << "\nNão há elementos para ordenar atualmente.\n" << std::endl;
    }
}