#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string ans;
    ans += grid[0][0];

    vector<pair<int,int>> frontier;
    frontier.push_back({0, 0});

    vector<vector<int>> seen(n, vector<int>(n, -1));
    int timer = 0;

    for(int step = 0; step < 2 * n - 2; step++) {
        char mn = 'Z';

        // Find minimum character among all next reachable cells
        for(auto [x, y] : frontier) {
            if(x + 1 < n) mn = min(mn, grid[x + 1][y]);
            if(y + 1 < n) mn = min(mn, grid[x][y + 1]);
        }

        vector<pair<int,int>> next_frontier;
        timer++;

        // Keep only cells having character == mn
        for(auto [x, y] : frontier) {
            if(x + 1 < n && grid[x + 1][y] == mn) {
                if(seen[x + 1][y] != timer) {
                    seen[x + 1][y] = timer;
                    next_frontier.push_back({x + 1, y});
                }
            }

            if(y + 1 < n && grid[x][y + 1] == mn) {
                if(seen[x][y + 1] != timer) {
                    seen[x][y + 1] = timer;
                    next_frontier.push_back({x, y + 1});
                }
            }
        }

        ans += mn;
        frontier = move(next_frontier);
    }

    cout << ans << '\n';

    return 0;
}