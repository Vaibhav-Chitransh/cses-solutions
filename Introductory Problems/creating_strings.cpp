#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> freq(26, 0);
vector<string> perm;

void search(string curr) {
    if(curr.size() == s.size()) {
        perm.push_back(curr);
        return ;
    }

    for(int i=0; i<26; i++) {
        if(freq[i]) {
            freq[i]--;
            search(curr + char('a' + i));
            freq[i]++;
        }
    }
}

int main() {
    cin >> s;

    for(char ch : s) freq[ch - 'a']++;

    search("");

    cout << perm.size() << "\n";
    for(string& s : perm) cout << s << "\n";

    return 0;
}