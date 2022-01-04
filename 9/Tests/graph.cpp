// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO
int Graph::outDegree(int v) {
    if(v>=nodes.size()||v<=0) return -1;return nodes.at(v).adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO

int Graph::recursivestuff(Node a){
    int b =0;
    for(auto sus1:a.adj){
        if(nodes[sus1.dest].visited)
            continue;
        nodes[sus1.dest].visited = true;

        b = recursivestuff(nodes[sus1.dest]) + b + 1;
    }
    return b;
}

int Graph::connectedComponents() {
    int count = 0,res = 0;
    for(auto sus :nodes){
        if(count == 0){
            count = 1;
            continue;
        }
        if(!sus.visited){
            sus.visited = true;
            recursivestuff(sus);
            res++;
        }
    }
    return res;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int count = 0,res = 0;
    for(auto sus :nodes){
        if(count == 0){
            count = 1;
            continue;
        }
        if(!sus.visited){
            sus.visited = true;
            int c = recursivestuff(sus);
            if(c>res){
                res = c;
            }
        }
    }
    return res;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO
int Graph::distance(int a, int b) {
    return 0;
}

// ..............................
// b) Diametro
// TODO
int Graph::diameter() {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    return false;
}
