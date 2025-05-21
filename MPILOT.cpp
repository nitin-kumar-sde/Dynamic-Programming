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
#define N 10005
#define MOD 1000000007

pair<ll, ll > salary[N];

ll dp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    for(int i=0;i<n;i++) {
        cin >> salary[i].first;
        cin >> salary[i].second;
    }

    for(int i=0;i<2;i++) {
        for(int j=0;j<N;j++)
        dp[i][j] = 1e16;
    }

    dp[0][1] = salary[0].second;
    
    int row = 1;
    for(int i=1;i<n;i++) {
        
        dp[row][0] = salary[i].first + dp[1^row][1];
        for(int j=1;j<=i+1;j++) {

        dp[row][j] = min(salary[i].second + dp[1^row][j-1], salary[i].first + dp[1^row][j+1]);    
      }
      row = 1^row;
    }

    cout << dp[1^row][0] << endl;
    return 0;
}