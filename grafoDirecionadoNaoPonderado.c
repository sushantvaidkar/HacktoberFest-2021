#include <stdio.h>
#include <stdlib.h>

// Implementação de um Grafo Direcionado Não ponderado em C 
// Utilizando Lista encadeada

// Estruturas
/**
 * Typedef Struct Celula
 * Estrutura correspondente aos vértices
 * int index corresponde ao identificador do vértice
 * Celula *proximo é um ponteiro que aponta para a próxima célula
 **/
typedef struct Celula {
    int index;
    struct Celula *proximo;
} Celula;

/**
 * Typedef Struct Grafo
 * representa o grafo com seu conjunto de vertices e arestas
 * int vertice indica a quantidade de vértices no grafo
 * Celula **graph é um ponteiro que aponta para os vertices e identifica as ligações
 **/
typedef struct Grafo{
    Celula **graph;
    int vertice; 
} Grafo;

// Métodos
/**
 * Criação de um vértice
 * @param int id correspondente ao identificador do vértice
 * @return Celula* que corresponde ao vértice criado
 */
struct Celula* criarCelula(int id) {
    Celula *celula = (Celula*)malloc(sizeof(Celula));
    celula->index = id;
    celula->proximo = NULL;
    return celula;
}

/**
 * Criação do grafo com a determinada quantidade de vértices
 * @param int vertices corresponde a quantidade de vertices no grafo 
 * @return Grafo* que corresponde ao grafo criado
 */
struct Grafo* criarGrafo(int vertices) {
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->vertice = vertices;
    grafo->graph = malloc(sizeof(Celula *)*vertices);

    for(int i = 0; i < vertices; i++) {
        // Inicializa todas os apontadores para as celulas como null, não possui nenhuma aresta
        grafo->graph[i] = (Celula *)malloc(sizeof(Celula *)*vertices);
        grafo->graph[i]->index = i;
        grafo->graph[i]->proximo = NULL;
    }
    return grafo;
}

/**
 * Método responsável por inserir quantidadeVertices em um grafo
 * @param Grafo grafo o qual tera a insercao dos vértices.
 * @param int quantidadeVertice corresponde a quantidade de vértices a ser inserido no grafo
 */
void inserirVertice(int quantidadeVertices, Grafo *grafo) {

    for(int i = 0; i < quantidadeVertices; i++) {
        grafo->graph[grafo->vertice] = (Celula *)malloc(sizeof(Celula *)*grafo->vertice);
        grafo->graph[grafo->vertice]->index = grafo->vertice;
        grafo->graph[grafo->vertice]->proximo = NULL;
        grafo->vertice++;
    }
}

/**
 * Método responsável por inserir a aresta de verticeA e verticeB no grafo
 * @param Grafo grafo no qual tera a insercao da aresta.
 * @param int verticeA correspondente ao valor do primeiro vertice na relação que sera criada (com a insercao da aresta).
 * @param int verticeB correspondente ao valor do segundo vertica na relação que sera criada (com a insercao da aresta).
 */
void inserirAresta(Grafo *grafo, int verticeA, int verticeB) {

    // Cria uma celula para adicionar na lista do verticeA
    Celula *celula = criarCelula(verticeB);
    // nova celula aponta para o primeiro(antigo) da lista
    celula->proximo = grafo->graph[verticeA]->proximo;
    // apontador de celulas aponta para a nova celula -> inserimos no inicio da lista
    grafo->graph[verticeA]->proximo = celula; 
}

/**
 * Função responsável por remover a aresta de verticeA e verticeB no grafo
 * @param Grafo grafo no qual tera a remocao de uma aresta.
 * @param int verticeA correspondente ao valor do primeiro vertice na relação que será excluida (coma a remocao da aresta).
 * @param int verticeB correspondente ao valor do segundo vertice na relação que será excluida (coma a remocao da aresta).
 */
void removerAresta(Grafo *grafo, int verticeA, int verticeB) {

    if(grafo->graph[verticeA]->index == verticeA) {
        Celula *head = grafo->graph[verticeA];
        Celula *retirar = grafo->graph[verticeA]->proximo;
        Celula *anterior = head;
        int j;
        while (retirar->index != verticeB)
        {
            anterior = retirar;
            retirar = retirar->proximo;
        }
        if(retirar->proximo != NULL) {
            Celula *proxima = retirar->proximo;
            retirar->proximo = NULL;
            anterior->proximo = proxima;
            free(retirar); 
        } else {
            free(retirar); 
            anterior->proximo = NULL;
        }
         
    } else {
        printf("Não foi possível remover a aresta com vértices: %d e %d", verticeA, verticeB);
    }
}

/**
 * Imprime o conjunto de arestas que compoe o grafo.
 * Percorre todo o grafo e seus vértices imprimindo cada uma de suas relações
 * @param Grafo grafo que tera seu conjunto de arestas impresso.
 */
void printGrafo(Grafo *grafo) {
    
    for(int i = 0; i < grafo->vertice; i++) {
        Celula *celulaRaiz = grafo->graph[i]->proximo;
        printf("\n Vértice %d:\n Aponta para ", i);
        while (celulaRaiz != NULL)
        {
            printf("%d  ", celulaRaiz->index);
            celulaRaiz = celulaRaiz->proximo;
        }
        printf("\n"); 
    }
    printf("\n");
}

void main() {

    int v = 5;
    Grafo *grafo = criarGrafo(v);

    inserirAresta(grafo, 0, 1);
    inserirAresta(grafo, 0, 4);
    inserirAresta(grafo, 1, 2);
    inserirAresta(grafo, 1, 3);
    inserirAresta(grafo, 1, 4);
    inserirAresta(grafo, 2, 3);
    inserirAresta(grafo, 3, 4);
    inserirAresta(grafo, 4, 1);
    inserirAresta(grafo, 0, 2);
    inserirAresta(grafo, 2, 4);

    inserirVertice(2, grafo);
    inserirAresta(grafo, 5, 4);
    inserirAresta(grafo, 6, 2);
    inserirAresta(grafo, 6, 4);
    inserirAresta(grafo, 6, 3);
    printGrafo(grafo);
    removerAresta(grafo, 1, 2);
    removerAresta(grafo, 5, 4);
    printGrafo(grafo);
}

