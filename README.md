# Algoritmo de Kruskal para Árvore Geradora Mínima em Grafos
Este repositório contém a implementação de um grafo ponderado e não direcionado, juntamente com a aplicação do algoritmo de Kruskal para encontrar a árvore geradora mínima (MST - Minimum Spanning Tree).

## Estrutura do Projeto
O projeto é composto pelos seguintes arquivos:

- **Grafo.h**: Contém a definição da estrutura do grafo.
- **main.c**: Implementa as funções para criar o grafo, adicionar arestas, liberar memória e o algoritmo de Kruskal.
  
## Funcionalidades

### Estrutura do Grafo

A estrutura do grafo (Grafo) é definida com os seguintes campos:

- **nro_vertices**: Número de vértices no grafo.
- **eh_ponderado**: Indica se o grafo é ponderado (1) ou não (0).
- **grau**: Vetor que armazena o grau de cada vértice.
- **arestas**: Matriz de adjacência para representar as arestas.
- **pesos**: Matriz de pesos das arestas, utilizada apenas se o grafo for ponderado.
  
## Funções Implementadas
- **Grafo *cria_Grafo(int nro_vertices, int eh_ponderado)**: Cria um novo grafo com o número de vértices especificado e indica se é ponderado.
- **void insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, double peso)**: Insere uma aresta no grafo, com a opção de especificar se é um digrafo e o peso da aresta.
- **void libera_Grafo(Grafo *gr)**: Libera a memória alocada para o grafo.
- **void algKruskal(Grafo *gr, int orig, int *pai)**: Implementa o algoritmo de Kruskal para encontrar a árvore geradora mínima.
  
## Algoritmo de Kruskal
O algoritmo de Kruskal é utilizado para encontrar a árvore geradora mínima de um grafo ponderado. Ele funciona da seguinte maneira:

1. Inicializa cada vértice como uma árvore separada.
2. Ordena todas as arestas em ordem crescente de peso.
3. Adiciona arestas à árvore geradora mínima, evitando ciclos, até que todos os vértices estejam conectados.

## Autor
Desenvolvido por [Vitor Sbeghi].


