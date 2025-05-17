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

int dp[10005];
int parent[10005];
int cnt[10005];

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    int * input = new int [n];

    for(int i=0;i<n;i++)
    cin >> input[i];

    dp[0] = 1;
    int ans = 1;
    for(int i=1;i<n;i++) {
        dp[i] = 1;
        parent[i] = i;
        cnt[i] = 1;
        for(int j = i-1;j>=0;j--){
            if(input[j] <input[i]) {
                dp[i] = max(dp[i], 1+ dp[j]);
                if(dp[i] < (1+dp[j])) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                    parent[i] = j;
                }
                else if(dp[i] == (1+dp[j])) {
                    cnt[i] += cnt[j];
                    // parent update - order 
                }
            }
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << endl;
    return 0;
}