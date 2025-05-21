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
#define N 1005
#define MOD 1000000007
#define MAX_XOR 8192
int input[N];

int freq[4505] = {0};

vector<bool> isPrime(MAX_XOR+1, true);

void buildSieve() {
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i*i <=MAX_XOR; i++) {

        if(isPrime[i]) {
            for(int j=i*i;j<=MAX_XOR;j+=i) 
            isPrime[j] = false;
        }
    }

}
ll dp[2][MAX_XOR+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif
    buildSieve();
    int q; cin >> q;
    while(q--) {

        int n; cin >> n;
        fill(freq, freq + 4504, 0);

        for(int i=0;i<n;i++) {
            int temp;
            cin >> temp;
            freq[temp]++;
        }

        n = 0;
        for(int i=3500;i<=4500;i++) {   
            if(freq[i] > 0)
            input[n++] = i;
        }

        for(int i=0;i<=MAX_XOR;i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;

        int row = 1;
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<MAX_XOR;j++) {
                int fq = freq[input[i]];
                dp[row][j] = (dp[1-row][j] * (fq/2 + 1) + dp[1-row][j^input[i]] * ((fq+1)/2))%MOD;
            }
            row = 1-row;
        }

        ll ans = 0;

        for(int i=2;i<=MAX_XOR;i++) {
            if(isPrime[i])
            ans = (ans + dp[1-row][i])%MOD;
        }
        cout << ans << endl;

    }

    return 0;
}