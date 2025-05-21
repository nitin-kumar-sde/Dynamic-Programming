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
#define N 100005
#define MOD 1000000007

ll dp[2][N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int t; cin >> t;

    while(t--) {
        int tNum; cin >> tNum;
        int n,k; 
        cin >> n >> k;

        dp[0][n-1][0] = 0;
        dp[1][n-1][0] = 0;
        dp[0][n-2][0] = 2;
        dp[1][n-2][0] = 1;

        for(int i=n-3;i>=0;i--) {
            dp[0][i][0] = dp[1][i+1][0] + dp[0][i+1][0];
            dp[1][i][0] = dp[0][i+1][0];
        }

        int row = 1;
        for(int d=1;d<=k;d++) {

            dp[0][n-1][row] = 0;
            dp[1][n-1][row] = 0;

            dp[0][n-2][row] = 0;
            dp[1][n-2][row] = (1 == d);
            for(int i=n-3;i>=0;i--) {
                dp[0][i][row] = dp[0][i+1][row] + dp[1][i+1][row];
                dp[1][i][row] = dp[1][i+1][1^row] + dp[0][i+1][row];
            }
            row = 1^row;
        }

        ll ans = dp[0][0][1^row] + dp[1][0][1^row];

        cout << tNum << " " << ans << endl;
    }

    return 0;
}