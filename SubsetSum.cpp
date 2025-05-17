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

int dp[2][100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n, target; 
    cin >>  n >> target;
    
    vector<int> input(n);

    for(int i=0;i<n;i++)
    cin >> input[i];

    for(int i=1;i<=target;i++)
    dp[0][i] = 0;
    
    dp[0][0] = 1;
    int row = 1;

    for(int i=n-1;i>=0;i--) {
        dp[row][0] = 1;
        if(input[i] == 0)
        dp[row][0] = 2;
        for(int j = 1; j<=target; j++) {
            dp[row][j] = dp[1-row][j];
            if(j >=input[i])
            dp[row][j] += dp[1-row][j-input[i]];
        }
        row = 1 - row;
    }

    cout << dp[1 - row][target] << endl;

    return 0;
}