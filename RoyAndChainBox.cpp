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

ll dp[N] = {0};
ll freq[N] = {0};
ll greater_freq[N] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int l,r;
        cin >> l >> r;
        dp[r] ++;
        dp[l-1]--;
    }

    ll ans = 0;

    for(int i=n;i>0;i--) {
        ans += dp[i];
        dp[i] = ans;
    }
    
    for(int i=1;i<=n;i++)
    freq[dp[i]]++;

    greater_freq[n] = freq[n];

    for(int i=n-1;i>0;i--)
    greater_freq[i] = freq[i] +  greater_freq[i+1];

    int q; cin >> q;

    while(q--) {
        int x; cin >> x;
        int ans = greater_freq[x];
        cout << ans << endl;
    }

    return 0;
}