#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ans = INT_MAX;
ll total = 0;

void divide(int i, vector<int>& p, ll sum1) {
    // base case
    if(i == p.size()) {
        ans = min(ans, abs(sum1 - (total - sum1)));
        return ;
    }

    // put in set 1
    divide(i+1, p, sum1 + p[i]);

    // don't put in set 1
    divide(i+1, p, sum1);
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i=0; i<n; i++) {
        cin >> p[i];
        total += p[i];
    }

    divide(0, p, 0);
    cout << ans;

    return 0;
}