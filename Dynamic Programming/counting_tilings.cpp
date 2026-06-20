#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<vector<int>> dp;

void generateNextMasks(int currMask, int row, int nextMask, int n, vector<int>& nextMasks) {
    if(row == n+1) {
        nextMasks.push_back(nextMask);
        return ;
    }

    // if this cell is already been filled with the previous column (so skip this)
    if(currMask & (1 << row)) {
        generateNextMasks(currMask, row+1, nextMask, n, nextMasks);
        return ;
    }

    // if it is a last row then there is only possibility of filling the horizontal tile and make the nextMask next col of same row as 1
    if(row != n) {    // if I want to place a vertical tile then currRow and currRow + 1 should not be previously filled
        if((currMask & (1 << (row + 1))) == 0) {
            generateNextMasks(currMask, row+2, nextMask, n, nextMasks);
        }
    }

    // place a horizontal mask but check that the currRowth column is not previously filled
    generateNextMasks(currMask, row+1, nextMask | (1 << row), n, nextMasks);
}

int findWays(int col, int mask, int m, int n) {
    if(col == m+1) {
        if(mask == 0) return 1;    // (no cell of (m+1)th column should be filled that means in the last column I can't put horizontal tile)
        return 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];

    vector<int> nextMasks;
    generateNextMasks(mask, 1, 0, n, nextMasks);

    int answer = 0;
    for(int nextMask : nextMasks) {
        answer = (answer + findWays(col+1, nextMask, m, n)) % mod;
    }

    return dp[col][mask] = answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    dp.resize(m+2, vector<int>(1 << (n + 1), -1));
    // state: dp[i][mask] = number of ways to fill the columns from ith till mth given that some positions are already filled
    cout << findWays(1, 0, m, n) << endl;

    return 0;
}