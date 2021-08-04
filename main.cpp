#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll bfs(ll vertex, ll current_length, bool visited[], const ll cities_amount, vector< vector<ll> > matrix) {
    visited[vertex] = true;
    ll ans = 10e10;
    bool all_visited = true;
    for (int next_vertex = 0; next_vertex < cities_amount; next_vertex++) {
        if (!visited[next_vertex]) {
            ans = min(ans, bfs(next_vertex, current_length + matrix[vertex][next_vertex], visited, cities_amount, matrix));
            all_visited = false;
        }
    }
    visited[vertex] = false;
    if (all_visited)
        return current_length + matrix[vertex][0];
    return ans;
}

int main() {
    ll cities_amount;
    cin >> cities_amount;
    vector< vector<ll> > matrix(cities_amount, vector<ll> (cities_amount, 0));

    bool vis[cities_amount];
    for (ll x = 0; x < cities_amount; x++) {
        for (ll y = 0; y < cities_amount; y++)
            cin >> matrix[x][y];
        vis[x] = false;
    }

    cout << bfs(0, 0, vis, cities_amount, matrix);
    return 0;
}
