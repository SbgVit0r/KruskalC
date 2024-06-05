#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo grafo
Grafo *cria_Grafo(int nro_vertices, int eh_ponderado) {
  // Aloca memória para a estrutura do grafo
  Grafo *gr = (Grafo *)malloc(sizeof(Grafo));
  if (gr != NULL) {
    // Inicializa os campos da estrutura do grafo
    gr->nro_vertices = nro_vertices;
    gr->eh_ponderado = eh_ponderado;
    // Aloca memória para o vetor de graus
    gr->grau = (int *)calloc(nro_vertices, sizeof(int));
    // Aloca memória para a matriz de adjacência
    gr->arestas = (int **)malloc(nro_vertices * sizeof(int *));
    for (int i = 0; i < nro_vertices; i++) {
      gr->arestas[i] = (int *)malloc(nro_vertices * sizeof(int));
    }
    // Se o grafo for ponderado, aloca memória para a matriz de pesos
    if (eh_ponderado) {
      gr->pesos = (double **)malloc(nro_vertices * sizeof(double *));
      for (int i = 0; i < nro_vertices; i++) {
        gr->pesos[i] = (double *)malloc(nro_vertices * sizeof(double));
      }
    }
  }
  return gr;
}

// Função para inserir uma aresta no grafo
void insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, double peso) {
  if (gr != NULL) {
    // Verifica se os vértices de origem e destino são válidos
    if (orig >= 0 && orig < gr->nro_vertices && dest >= 0 &&
        dest < gr->nro_vertices) {
      // Adiciona a aresta na matriz de adjacência
      gr->arestas[orig][gr->grau[orig]] = dest;
      // Se o grafo for ponderado, atribui o peso à aresta
      if (gr->eh_ponderado) {
        gr->pesos[orig][gr->grau[orig]] = peso;
      }
      // Incrementa o grau do vértice de origem
      gr->grau[orig]++;
      // Se o grafo não for direcionado, adiciona a aresta inversa
      if (!eh_digrafo) {
        insereAresta(gr, dest, orig, 1, peso);
      }
    }
  }
}

// Função para liberar a memória alocada para o grafo
void libera_Grafo(Grafo *gr) {
  if (gr != NULL) {
    // Libera a memória alocada para a matriz de adjacência e para os pesos (se
    // existirem)
    for (int i = 0; i < gr->nro_vertices; i++) {
      free(gr->arestas[i]);
      if (gr->eh_ponderado) {
        free(gr->pesos[i]);
      }
    }
    // Libera a memória alocada para os vetores de grau, matriz de adjacência e
    // matriz de pesos
    free(gr->arestas);
    free(gr->grau);
    if (gr->eh_ponderado) {
      free(gr->pesos);
    }
    // Libera a memória alocada para a estrutura do grafo
    free(gr);
  }
}

// Algoritmo de Kruskal para encontrar a árvore geradora mínima
void algKruskal(Grafo *gr, int orig, int *pai) {
int i, j, dest, primeiro, NV = gr  -> nro_vertices;
  double menorPeso;
  int *arv = (int*) malloc(NV * sizeof(int));
  for(i=0; i < NV; i++){
    arv[i] = i;
    pai[i] = -1; // Sem pai
  }
  pai[orig] = orig;
  while(1){
    primeiro = 1;
    for(i=0; i < NV; i++){ // Percorre todos os vértices
      for(j=0; j < gr -> grau[i]; j++){ // Arestas  
        // Procura vértice menor peso: continua
      }
    }
    if (primeiro == 1 ) break;
    if(pai[orig] == -1) pai[orig] = dest;
    else pai[dest] = orig;

    for(i=0; i < NV; i++){
      if(arv[i] == arv[dest]){
        arv[i] = arv[orig];
      }
      if(arv[i] != arv[gr->arestas[i][j]]){
        if(primeiro){
          menorPeso = gr -> pesos[i][j];
          orig = i;
          dest = gr -> arestas[i][j];
          primeiro = 0;
        } else {
          if(menorPeso > gr->pesos[i][j]){
            menorPeso = gr -> pesos [i][j];
            orig = i;
            dest = gr -> arestas[i][j];
          }
        }
      }
    } 
  }
}

// Função principal
int main() {
  int eh_digrafo = 0;           // Não é direcionado
  Grafo *gr = cria_Grafo(6, 1); // É ponderado

  // Adiciona arestas ao grafo
  insereAresta(gr, 0, 1, eh_digrafo, 6);
  insereAresta(gr, 0, 2, eh_digrafo, 1);
  insereAresta(gr, 0, 3, eh_digrafo, 5);
  insereAresta(gr, 1, 2, eh_digrafo, 2);
  insereAresta(gr, 1, 4, eh_digrafo, 5);
  insereAresta(gr, 2, 3, eh_digrafo, 2);
  insereAresta(gr, 2, 4, eh_digrafo, 6);
  insereAresta(gr, 2, 5, eh_digrafo, 4);
  insereAresta(gr, 3, 5, eh_digrafo, 4);
  insereAresta(gr, 4, 5, eh_digrafo, 3);

  int pai[6];
  algKruskal(gr, 0, pai);

  // Imprime o resultado
  for (int i = 0; i < 6; i++) {
    printf("%d: %d\n", pai[i], i);
  }

  // Libera a memória alocada para o grafo
  libera_Grafo(gr);
  return 0;
}
