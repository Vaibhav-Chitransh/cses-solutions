#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MIN));

    for(int d=0; d<n; d++) {
        for(int i=0, j=d+i; j<n; i++,j++) {    // d = j-i
            if(i == j) dp[i][j] = arr[i];
            else if(i+1 == j) dp[i][j] = max(arr[i], arr[j]);
            else {
                dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}