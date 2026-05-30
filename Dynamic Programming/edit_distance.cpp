#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n, m;
    n = s1.length();
    m = s2.length();

    // vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<int> prev(m+1);
    for(int i=0; i<=m; i++) prev[i] = i;

    for(int i=1; i<=n; i++) {
        vector<int> curr(m+1);
        curr[0] = i;
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1 + min({prev[j-1], prev[j], curr[j-1]});
        }
        prev = curr;
    }

    cout << prev[m];

    return 0;
}