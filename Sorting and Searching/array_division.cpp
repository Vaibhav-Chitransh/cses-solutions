#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
bool check(ll mid, vector<ll>& v, ll n, ll k) {
    ll div = 1;
    ll sum = 0;
 
    for(ll i=0; i<n; i++) {
        if(sum + v[i] > mid) {
            sum = v[i];
            div++;
        } else {
            sum += v[i];
        }
 
        if(div > k) return false;
    }
 
    return true;
}
 
int main(){
    ll n, k;
    cin >> n >> k;
 
    ll hi = 0, lo = 0;
 
    vector<ll> v(n);
    for(ll i=0; i<n; i++) {
        cin >> v[i];
        hi += v[i];
        lo = max(lo, v[i]);
    }
 
    ll res = hi;
 
    while(lo <= hi) {
        ll mid = lo + (hi - lo)/2;
        if(check(mid, v, n, k)) {
            res = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
 
    cout << res;
    
    return 0;
}