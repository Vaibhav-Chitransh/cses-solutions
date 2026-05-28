#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;

    while(n) {
        string s = to_string(n);
        int maxi = 0;
        for(int i=0; i<s.length(); i++) maxi = max(maxi, s[i] - '0');
        n -= maxi;
        cnt++;
    }

    cout << cnt;

    return 0;
}