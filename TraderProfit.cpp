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
#define N 35
#define MOD 1000000007
ll dp [2][N][2];
ll input[N];

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

        int n,k; cin >> k >> n;

        for(int i=0;i<n;i++)
        cin >> input[i];

        for(int i=0;i<=n;i++) 
        dp[0][i][0] = dp[1][i][0] = 0;

        int row = 1;
        ll ans = 0;
        for(int i=1;i<=k;i++) {

            dp[0][n][row] = dp[1][n][row] = 0;

            for(int j=n-1;j>=0;j--) {
                dp[0][j][row] = max(-input[j] + dp[1][j+1][row], dp[0][j+1][row]);
                dp[1][j][row] = max(input[j] + dp[0][j+1][1^row], dp[1][j+1][row]);
            }
            ans = max(ans, dp[0][0][row]);
            row = 1^row;
        }

        cout << ans << endl;

    }

    return 0;
}