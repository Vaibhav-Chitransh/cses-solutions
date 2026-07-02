#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int n = str.length();
    int ans = 1;

    int cnt = 1;
    char prev = str[0];

    int idx = 1;
    while(idx < n) {
        if(str[idx] == prev) cnt++;
        else {
            prev = str[idx];
            cnt = 1;
        }

        ans = max(ans, cnt);
        idx++;
    }

    cout << ans << endl;

    return 0;
}