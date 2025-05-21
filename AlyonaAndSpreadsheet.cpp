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

ll input[2][N] = {0};

ll dp[N] = {0};

ll final_dp[N] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;
    int row = 0;
    for(int i=0;i<n;i++) {
        final_dp[i] = -1e9;
        for(int j=0;j<m;j++) {
            cin >> input[row][j];
            if(input[1^row][j] <= input[row][j])
            dp[j]++;
            else
            dp[j] = 1;

            final_dp[i] = max(final_dp[i], dp[j]);

        }
        row = 1^row;
    }

    int k; cin >> k;

    while(k--) {

        int l,r; cin >> l >> r;
        l--; r--;

        if(final_dp[r] > (r-l))
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
    }

    return 0;
}