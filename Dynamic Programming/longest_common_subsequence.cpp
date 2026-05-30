#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a1(n), a2(m);
    for(int i=0; i<n; i++) cin >> a1[i];
    for(int j=0; j<m; j++) cin >> a2[j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a1[i-1] == a2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;
    int size = dp[n][m];
    vector<int> ans(size);
    int curr = size - 1;

    int i=n, j=m;
    while(i != 0 && j != 0) {
        int up = dp[i-1][j];
        int left = dp[i][j-1];
        int diag = dp[i-1][j-1];

        if(a1[i-1] == a2[j-1]) {
            ans[curr--] = a1[i-1];
            i--, j--;
        } else {
            if(up > left) i--, j;
            else i, j--;
        }
    }

    for(int i=0; i<size; i++) cout << ans[i] << " ";

    return 0;
}