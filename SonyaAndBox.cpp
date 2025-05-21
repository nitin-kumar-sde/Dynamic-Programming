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
#define M 1005
#define MOD 1000000007

vector<int> input[N];

ll dp[N][M] = {0};

ll dp_final[2][M] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;

    // take input
    for(int i=0;i<n;i++) {
        int l; cin >> l;
        vector<int> inp(l);

        for(int j=0;j<l;j++) {
            cin >> inp[j];
        }
        input[i] = inp;
    }

    // build dp array
    for(int i=0;i<n;i++) {

        vector<int> inp = input[i];
        int l = inp.size();
        for(int j=0;j<l;j++) {
            ll sum = 0;
            for(int k=0;k<l-j;k++) {
                if(k+1>m) break;
                sum+=inp[j+k];
                dp[i][k+1] = max(dp[i][k+1], sum);
            }
        }
    }

    
    int row = 1;
    for(int i=n-1;i>=0;i--) {
           
        for(int j=0;j<=m;j++) {
            dp_final[row][j] = 0;
            for(int l=0;l<=j;l++) {
            if(l > input[i].size())
            continue;
            dp_final[row][j] = max(dp_final[row][j], dp[i][l] + dp_final[1^row][j-l]);
            }
        }
        row = 1^row;
    }

    ll ans = dp_final[1^row][m];

    cout << ans << endl;

    return 0;
}