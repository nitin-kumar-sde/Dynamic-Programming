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
#define C 15
ll dp[N][N][C] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n, q, c;
    cin >> n >> q >> c;

    for(int i=0;i<n;i++) {
        int x,y,t;
        cin >> x >> y >> t;
        dp[x][y][t]++;
    }
    // pre compute 
    for(int t=0;t<C;t++) {

        for(int i=1;i<N;i++) {
            for(int j=1;j<N;j++)
            dp[i][j][t] = dp[i][j][t] + dp[i-1][j][t] + dp[i][j-1][t] - dp[i-1][j-1][t];
        }
    }

    while(q--) {
        int x1,y1, x2,y2, t;

        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll brightness = 0;
        for(int i=0;i<C;i++) {
            int fq =  dp[x2][y2][i] - dp[x1-1][y2][i] -dp[x2][y1-1][i] + dp[x1-1][y1-1][i];
            brightness = brightness + fq* ((i+t)%(c+1));
        }
        cout << brightness << endl;
    }

    return 0;
}