#ifndef PILHA_HPP
#define PILHA_HPP

const int CAPACIDADE_MAX = 25; // capacidade máxima da pilha

class Pilha{
    private:
        int topo; // posição do topo da pilha
        int* elementos; // alocação dos elementos da pilha

    public:
        Pilha(); // aloca a memória
        ~Pilha(); // libera a memória alocada

        // métodos de manipulação
        void empilhar(int valor);
        int desempilhar();
        void ordenar();

        // métodos de somente leitura
        bool estaCheia() const;
        bool estaVazia() const;
        int consultarTopo() const;
        int consultarTamanho() const;
        void consultarTudo() const;
};

#endif // PILHA_HPP