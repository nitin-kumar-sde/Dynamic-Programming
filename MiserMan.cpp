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
#define N 105
#define MOD 1000000007
int input[N][N];
int dp[2][N] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> input[i][j];
        }
    }
    int row  = 1;
    for(int i=n-1;i>=0;i--) {
        dp[row][0] = input[i][0] + min(dp[1^row][1], dp[1^row][0]);
        dp[row][m-1] = input[i][m-1] + min(dp[1^row][m-2], dp[1^row][m-1]);

        for(int j=1;j<m-1;j++) {
            dp[row][j] = input[i][j] + min(dp[1^row][j], min(dp[1^row][j+1], dp[1^row][j-1]));
        }
        row = 1^row;
    }

    int ans = 1e9;

    for(int i=0;i<m;i++)
    ans = min(ans, dp[1^row][i]);

    cout << ans << endl;

    return 0;
}