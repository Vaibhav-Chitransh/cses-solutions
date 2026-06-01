#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int totalSum = 0;

    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
        totalSum += coins[i];
    }

    vector<vector<int>> dp(n, vector<int>(totalSum+1, false));
    dp[0][0] = true;
    dp[0][coins[0]] = true;

    for(int i=1; i<n; i++) {
        dp[i][0] = true;
        for(int x=1; x<=totalSum; x++) {
            dp[i][x] = dp[i-1][x];
            if(x >= coins[i]) dp[i][x] |= dp[i-1][x-coins[i]];
        }
    }

    int count = 0;
    vector<int> possibleSums;
    for(int i=1; i<=totalSum; i++) {
        if(dp[n-1][i]) {
            count++;
            possibleSums.push_back(i);
        }
    }

    cout << count << endl;
    for(int i=0; i<possibleSums.size(); i++) cout << possibleSums[i] << " ";

    return 0;
}