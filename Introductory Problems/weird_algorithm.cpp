#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    v.push_back(n);

    while(n != 1) {
        if(n & 1) n = n*3 + 1;
        else n /= 2;
 
        v.push_back(n);
    }
 
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";

    return 0;
}