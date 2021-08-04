#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll bfs(ll vertex, ll current_length, bool visited[], const ll cities_amount, vector< vector<ll> > matrix) {
    visited[vertex] = true;
    ll ans = 10e10;
    for (int next_vertex; next_vertex < cities_amount; next_vertex++) {
        if (!visited[vertex]) {
            ans = min(ans, bfs(next_vertex, current_length + matrix[vertex][next_vertex], visited, cities_amount, matrix));
        }
    }
    visited[vertex] = false;
    return ans + matrix[vertex][0];
}

int main() {
    vector< vector<ll> > matrix;
    int cities_amount;
    cin >> cities_amount;

    bool vis[cities_amount];
    for (int x = 0; x < cities_amount; x++) {
        for (int y = 0; y < cities_amount; y++)
            cin >> matrix[x][y];
        vis[x] = false;
    }

    cout << bfs(0, 0, vis, cities_amount, matrix);
    return 0;
}
