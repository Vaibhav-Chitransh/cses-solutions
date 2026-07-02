#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    ll ans = 0;
    int prev = arr[0];

    for(int i=1; i<n; i++) {
        if(arr[i] < prev) {
            ans += (prev - arr[i]);
        } else {
            prev = arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}