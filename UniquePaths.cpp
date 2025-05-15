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
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int m, n;
    cin >> m >> n;

    vector<vector<long long>> obstacleGrid(m, vector<long long>(n));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        cin >> obstacleGrid[i][j];

    vector<vector<int>> dp(2, vector<int>(n));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j)
        dp[i][j] = 0;
    
    dp[0][n-1] = ((obstacleGrid[m-1][n-1] == 0) ? 1 : 0);

    for(int i = n-2; i>=0;i--) {
        dp[0][i] = dp[0][i+1];
        if(obstacleGrid[m-1][i] == 1)
        dp[0][i] = 0;
    }
    int rowNo = 1;
    for(int j= m-2;j>=0;j--) {
        
        for(int i = n-1; i>=0;i--){
            if(obstacleGrid[j][i] == 1){
                dp[rowNo][i] = 0;
                continue;
            }
            dp[rowNo][i]= dp[1-rowNo][i];

            if(i < n-1)
            dp[rowNo][i] +=dp[rowNo][i+1];
        }
        rowNo = 1 - rowNo;
    }
    int ans = dp[1-m%2][0];

    cout << ans << endl;
    return 0;
}