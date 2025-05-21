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
int dp[105][105][2];

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

        string s1, s2;
        cin >> s1 >> s2;
        int k; cin >> k;
        int m = s1.length();
        int n  = s2.length();
        
        for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++) {
            dp[i][j][0] = 0;
        }
        

        int row = 1;
        for(int i=1;i<=k;i++) {  

        for(int j=0;j<=n;j++)
        dp[m][j][row] = -1e9;

        for(int j=0;j<=m;j++)
        dp[j][n][row] = -1e9;

        for(int j=m-1;j>=0;j--) {
           for(int l=n-1;l>=0;l--) {
              if(s1[j] == s2[l])
              dp[j][l][row] = max(dp[j+1][l+1][row], s1[j] + dp[j+1][l+1][1-row]);
                else
              dp[j][l][row] = max(dp[j+1][l][row], dp[j][l+1][row]);
            }
            
        }
        row = 1 - row;
    }

        int ans = dp[0][0][1-row];
        if(ans < 0) ans = 0;
        cout << ans << endl;

    }

    return 0;
}