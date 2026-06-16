#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[a-1] = 1;
    }

    for(int i=0; i<n; i++) {
        if(v[i] == 0) {
            cout << i+1;
            break;
        }
    }

    return 0;
}