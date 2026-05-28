#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> pages[i];

    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i=0; i<=x; i++) {
        if(price[0] <= i) dp[0][i] = pages[0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=x; j++) {
            int purchase = 0, notPurchase = 0;
            if(price[i] <= j) purchase = pages[i] + dp[i-1][j - price[i]];
            notPurchase = dp[i-1][j];

            dp[i][j] = max(purchase, notPurchase);
        }
    }

    cout << dp[n-1][x];

    return 0;
}