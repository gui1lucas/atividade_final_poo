#include "Pilha.hpp"
#include <iostream>
#include <string>

// como o código foi implementado no Linux, usar windows.h não funciona
// #include <windows.h>

void exibirOperacoes();

int main(){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    Pilha pilha; // cria um dado do tipo Pilha
    int valorEmpilhado, elementoTopo, operacao;
    int valorDesempilhado = 0; // para evitar o lixo de memória

    do{
        exibirOperacoes();
        std::cout << "Operação escolhida: ";

        // tratamento de erros para evitar o loop infinito se o usuário digitar uma letra
        if(!(std::cin >> operacao)){
            std::cout << "\nDigite somente números!\n" << std::endl;
            std::cin.clear(); // limpa o erro e reinicia o std::cin
            std::cin.ignore(1000, '\n'); // limpa o buffer para evitar que o erro continue
            continue; // e o continue reinicia o loop principal
        }

        switch(operacao){
            case 1:
                try{
                    std::cout << "\nInforme o valor que deseja empilhar: ";
                    std::cin >> valorEmpilhado;
                    std::cin.ignore(1000, '\n'); // limpa o buffer para evitar erros
                    pilha.empilhar(valorEmpilhado);
                } catch(const std::overflow_error& erro){
                    std::cout << erro.what() << std::endl;
                }
                break;

            case 2:
                try{
                    valorDesempilhado = pilha.desempilhar();
                } catch(const std::underflow_error& erro){
                    std::cout << erro.what() << std::endl;
                }
                break;

            case 3:
                if(pilha.estaCheia()){
                    std::cout << "\nA pilha está cheia atualmente.\n" << std::endl;
                } else{
                    std::cout << "\nA pilha não está cheia atualmente.\n" << std::endl;
                }
                break;

            case 4:
                if(pilha.estaVazia()){
                    std::cout << "\nA pilha está vazia atualmente.\n" << std::endl;
                } else{
                    std::cout << "\nA pilha não está vazia atualmente.\n" << std::endl;
                }
                break;

            case 5:
                try{
                    elementoTopo = pilha.consultarTopo();
                    std::cout << "\nElemento ocupando o topo da pilha: " << elementoTopo << ".\n" << std::endl;
                } catch(const std::logic_error& erro){
                    std::cout << erro.what() << std::endl;
                }
                break;

            case 6:
                std::cout << "\nTamanho atual da pilha: " << pilha.consultarTamanho() << ".\n" << std::endl;
                break;

            case 7:
                pilha.consultarTudo();
                break;

            case 8:
                pilha.ordenar();
                pilha.consultarTudo();
                break;

            case 9:
                std::cout << "\nÚltimo elemento desempilhado: " << valorDesempilhado << ".\n" << std::endl;
                break;

            default:
                if(operacao != 10){
                    std::cout << "\nOperação inválida. Tente novamente.\n" << std::endl;
                }
        }
    } while(operacao != 10);

    return 0;
}

void exibirOperacoes(){
    std::string operacoes[10] = {
        "Empilhar um elemento",
        "Desempilhar um elemento",
        "Verificar se a pilha está cheia",
        "Verificar se a pilha está vazia",
        "Consultar elemento do topo",
        "Consultar tamanho atual da pilha",
        "Consultar todos os elementos da pilha",
        "Ordenar os elementos da pilha",
        "Consultar último elemento desempilhado",
        "Encerrar o programa"
    };

    std::cout << "=============== PILHA DE INTEIROS ===============" << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << "[" << i + 1 << "] - " << operacoes[i] << std::endl;
    }
}