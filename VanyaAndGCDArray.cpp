#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <algorithm> 
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007
ll dp[105][5005] = {0};

ll input[5005];


int Gcd(int a, int b) {
    if(b==0) return a;
    if(b>a) return Gcd(b, a);
    return Gcd(b, a%b);
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    for(int i=0;i<n;i++)
    cin >> input[i];
   
    dp[input[0]][0] = 1;

    for(int i=1;i<n;i++) {
        dp[input[i]][i] = 1;
        for(int j=0;j<=i-1;j++) {
            if(input[i] <=input[j])
            continue;

            for(int k=1;k<=100;k++) {
                int gcd = Gcd(k, input[i]);
                dp[gcd][i] += dp[k][j];
                dp[gcd][i] = (dp[gcd][i])%MOD;
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans = (ans + dp[1][i])%MOD;
    }
    cout << ans << endl;
    return 0;
}