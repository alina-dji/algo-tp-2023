#include <stdio.h>
#include <stdlib.h>

// Fonction pour initialiser une matrice d'adjacence
int** initAdjacencyMatrix(int numVertices) {
    int** matrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; ++i) {
        matrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; ++j) {
            matrix[i][j] = 0; // Initialisation à zéro (pas d'arête)
        }
    }
    return matrix;
}

// Procédure pour ajouter une arête entre deux sommets
void addEdge(int** matrix, int start, int end) {
    matrix[start][end] = 1;
    matrix[end][start] = 1; // Si le graphe est non orienté
}

// Procédure récursive pour visiter les nœuds en utilisant DFS
void dfs(int** adjacencyMatrix, int numVertices, int vertex, int* visited) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(adjacencyMatrix, numVertices, i, visited);
        }
    }
}

// Procédure pour initialiser et appeler DFS à partir d'un sommet de référence
void visitGraph(int** adjacencyMatrix, int numVertices, int startVertex) {
    int* visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0; // Initialisation à zéro (pas encore visité)
    }

    printf("Visite du graphe à partir du sommet %d : ", startVertex);
    dfs(adjacencyMatrix, numVertices, startVertex, visited);
    printf("\n");

    free(visited);
}

// Procédure pour libérer la mémoire de la matrice d'adjacence
void freeAdjacencyMatrix(int** matrix, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numVertices = 5;
    int** adjacencyMatrix = initAdjacencyMatrix(numVertices);

    // Ajouter des arêtes (exemple)
    addEdge(adjacencyMatrix, 0, 1);
    addEdge(adjacencyMatrix, 0, 2);
    addEdge(adjacencyMatrix, 1, 3);
    addEdge(adjacencyMatrix, 2, 4);

    // Visiter le graphe à partir du sommet 0
    visitGraph(adjacencyMatrix, numVertices, 0);

    // Libérer la mémoire
    freeAdjacencyMatrix(adjacencyMatrix, numVertices);

    return 0;
}
