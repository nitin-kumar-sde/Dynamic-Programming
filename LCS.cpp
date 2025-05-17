#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

int dp[2][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    string s, t;

    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    for(int i=0;i<=m;i++)
    dp[0][i] = 0;

    int row = 1;
    for(int i=n-1;i>=0;i--) {
        dp[row][m] = 0;
        for(int j = m-1; j>=0; j--) {
            if(s[i] == t[j])
            dp[row][j] = 1 + dp[1-row][j+1];
            else
            dp[row][j] = max(dp[1-row][j], dp[row][j+1]);
        }
        row = 1 - row;
    }

    cout << dp[1-row][0];
    return 0;
}