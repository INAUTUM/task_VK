/*
░░░░░░░░░░░▄█░░░░░░░░░░░░█▄░░░░░░░░░░░
░░░░░░░░░▄██▀░░░░░░░░░░░░▀██░░░░░░░░░░
░░░░░░░░▄███░░░█░░░░░░█░░░███▄░░░░░░░░
░░░░░░░████░░▄█░░░░░░░░█▄░░████░░░░░░░
░░░░░░▄███░▄██▀░░░░░░░░▀██░░███▄░░░░░░
░░░█░░███▀░██░░░░░░░░░░░▀██░▀███░░█░░░
░░░██░░██░█▀▄█░░░░░░░░░░█▄▀█░██░░██░░░
▄░░▀██░▀█░░██░░░░░░░░░░░░██░░█▀░██▀░░▄
▀█▄░▀██▄▀░▄██░░░░░░░░░░░░██▄░▀▄██▀░▄█▀
░▀██▄░▀▀░░▀██▄░░░░░░░░░░▄██▀░░▀▀░▄██▀░
░▄▀▀███▄░░░████▄░░░░░░▄████░░░▄███▀▀▄░
░▀█▄▄░▀▀▀░░▀███▀░░░░░░▀███▀░░▀▀▀░▄▄█▀░
░░░▀▀██████░░▀█▄░░░░░░▄█▀░░██████▀▀░░░
░░░░▄▄▄▄▄██▀░░▄██▄░░▄██▄░▀▀██▄▄▄▄▄░░░░
░░░░░░░░░▄▄▀░▄██▀░░░░▀██▄░█▄▄░░░░░░░░░
░░░░░░░▀▀▀░░▀▀▀░░░░░░░░▀▀▀░░▀▀▀░░░░░░░
*/

// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <ranges>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>
#include <numeric>
#include <fstream>
#include <vector>
#include <queue>

#define ull unsigned long long
using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ifstream file("graph.txt");
    if (!file.is_open()) {
        cerr << "ошибка открытия файла" << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        file >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    file >> start;
    file.close();

    vector<int> distance(n, -1); // bfs
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << distance[i] << endl;
    }

    return 0;
}