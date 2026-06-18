// There is an elevator with maximum weight x, and n people with known weights who want to get from the ground floor to the top floor. What is the minimum number of rides needed if the people enter the elevator in an optimal order?

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for(int i=0; i<n; i++) cin >> wt[i];

    // state: dp[mask] = {r, w} -> r rides are taking place to transport people of subset mask & the current weight of the last ride is w
    vector<pair<int, long long>> dp(1 << n);

    // base case
    dp[0] = {1, 0};    // we already have 1 ride available to fill and no people are in that ride so weight is 0

    // Transition
    for(int mask=1; mask<(1 << n); mask++) {
        dp[mask] = {n+1, 0};    // initialize with maximum so it will not affect while taking minimum
        for(int p=0; p<n; p++) {
            if(mask & (1<<p)) {    // what if the last person added to the elevator was p (so computing this state using previous without p)
                int prev = mask ^ (1 << p);
                int rides = dp[prev].first;
                long long lastWt = dp[prev].second;

                pair<int, long long> candidate;
                if(lastWt + wt[p] <= x) candidate = {rides, lastWt + wt[p]};   // now if I add p to current state then what will be the wt of the lift
                else candidate = {rides + 1, wt[p]};

                dp[mask] = min(dp[mask], candidate);  // lexicographical comparison
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}