#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Edge
{
    int src, dst;
};

struct Graph
{
    int V, E;
    Edge *edges;
};

Graph createGraph(int V, int E)
{
    Graph g;
    g.V = V;
    g.E = E;
    g.edges = (Edge *)malloc(sizeof(Edge) * E);
    return g;
}

int findParent(int *parent, int pos)
{
    printf("f");
    if (parent[pos] == pos)
    {
        return pos;
    }
    return findParent(parent, parent[pos]);
}

bool isCycle(Graph g)
{
    
    int parent[g.V];

    // make sets

    for (int i = 0; i < g.V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < g.E; i++)
    {
        
        int src = g.edges[i].src;
        int dst = g.edges[i].dst;
        int parentSrc = findParent(parent, src);
        int parentDst = findParent(parent, dst);
        printf("src: %d, dst: %d, parentSrc: %d, parentDst: %d");
        if (parentSrc == parentDst)
        {
            return true;
        }
        parent[parentSrc] = parentDst;
    }
    return false;
}

int main()
{
    int V = 4;
    int E = 3;
    Graph g = createGraph(V, E);
    g.edges[0].src = 0;
    g.edges[0].src = 0;
    g.edges[1] = {1, 2};
    g.edges[2] = {2, 3};
//    g.edges[3] = {3, 0};
    // printf("f");
    printf("graph is %s\n", isCycle(g) ? "cycle" : "safe"); // ternary
    // return 1;
}

