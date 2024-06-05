
// Estrutura para representar um grafo
typedef struct {
    int nro_vertices;   // Número de vértices no grafo
    int** arestas;      // Matriz de adjacência para armazenar as arestas do grafo
    double** pesos;     // Matriz para armazenar os pesos das arestas (se o grafo for ponderado)
    int* grau;          // Vetor para armazenar o grau de cada vértice
    int eh_ponderado;   // Flag indicando se o grafo é ponderado (1) ou não (0)
} Grafo;

// Protótipos das funções
Grafo* cria_Grafo(int nro_vertices, int eh_ponderado);
void insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, double peso);
void libera_Grafo(Grafo* gr);
void algKruskal(Grafo* gr, int orig, int* pai);