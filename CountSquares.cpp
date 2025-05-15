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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    
    int m, n;
    cin >> m >> n;

    vector<vector<long long>> matrix(m, vector<long long>(n));

    for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
    cin >> matrix[i][j];

    vector<vector<int>> dp(2, vector<int>(n));
    int ans = 0;

    for(int i = n-1; i>=0;i--) {
        dp[0][i] = matrix[m-1][i];
        ans += dp[0][i];
    }

    int rowNo = 1;
    
    for(int j= m-2;j>=0;j--) {
        dp[rowNo][n-1] = matrix[j][n-1];
        ans += dp[rowNo][n-1];
        for(int i = n-2; i>=0;i--){
            if(matrix[j][i] == 0){
                dp[rowNo][i] = 0;
                continue;
            }
            dp[rowNo][i]= 1 + min(dp[1-rowNo][i], min(dp[1-rowNo][i+1], dp[rowNo][i+1]));
            ans += dp[rowNo][i];
        }
        rowNo = 1 - rowNo;
    }

    cout << ans << endl;

    return 0;
}