#pragma once

#include <vector>
#include <queue>
#include <iostream>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> adj;

public:
    Graph(int nodes) : n(nodes), adj(nodes) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void removeEdge(int u, int v) {
        
    }

    void bfs(int start) const {
        std::vector<bool> visited(n, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            std::cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }

    void dfs(int start) const {
        std::vector<bool> visited(n, false);
        dfsHelper(start, visited);
        std::cout << std::endl;
    }

private:
    void dfsHelper(int node, std::vector<bool>& visited) const {
        visited[node] = true;
        std::cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
};
