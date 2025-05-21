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
#define N 55
#define MOD 1000000007

ll dp[2][N];
int freq[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif
    int d; cin >> d;
    while(d--) {
        int n,k;
        cin >> n >> k;

        for(int i=0;i<=2*n;i++) {
            dp[0][i] = dp[1][i] = freq[i] = 0;
        }

        for(int i=0;i<k;i++) {
            int temp;
            cin >> temp;
            freq[temp-1]++;
        }

        dp[0][1] = 1;
       
        int row = 1;

        for(int i=1;i<2*n;i++) {
            if(freq[i] == 0)
            dp[row][0] = dp[1^row][1];
            else
            dp[row][0] = 0;
            for(int j=1;j<=i+1;j++) {

                if(freq[i] > 0)
                dp[row][j] = dp[1^row][j-1];
                else
                dp[row][j] = dp[1^row][j-1] + dp[1^row][j+1];
            }
            row = 1^ row;
        }

        ll ans = dp[1^row][0];
        cout << ans << endl;
    }
    

    return 0;
}