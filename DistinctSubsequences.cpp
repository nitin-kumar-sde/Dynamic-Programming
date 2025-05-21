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

ll dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int q; cin >> q;

    while(q--) {
        string s;
        cin >> s;
        int n = s.length();

        map<char, int > lastIndex;
        dp[n] = 1;

        for(int i=n-1;i>=0;i--) {

            dp[i] = (2*dp[i+1])%MOD;
            
            if (lastIndex.find(s[i]) != lastIndex.end()) {
                int index = lastIndex[s[i]];
                dp[i] = ((dp[i] - dp[index + 1] ) % MOD + MOD)%MOD;

            }
            lastIndex[s[i]] = i;
        }

        cout << dp[0] << endl;
    }

    return 0;
}