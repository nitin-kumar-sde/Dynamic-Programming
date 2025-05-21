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
#define MAX_XOR 1024
ll dp[2][MAX_XOR] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    ll n, k, x; cin >> n >> k >> x;

    for(int i=0;i<n;i++) {
        int inp; cin >> inp;
        dp[0][inp]++;
    }
    int row = 1;

    for(int i=1;i<=k;i++) {
        for(int j=0;j<MAX_XOR;j++)
        dp[row][j] = 0;
        ll count = 0;
        for(int j=0;j<MAX_XOR;j++) {
            int xorInd = j ^ x;
            int ind = j;

            int xorFreq = (count%2==0) ? (dp[1^row][j]+1)/2 : dp[1^row][j]/2;
            int freq = (count%2==1) ? (dp[1^row][j]+1)/2 : dp[1^row][j]/2;

            dp[row][xorInd] +=xorFreq;
            dp[row][ind] += freq;

            count+=dp[1^row][j];
        }  
        row = 1^ row;
    }

    int max_xor = 0;

    for(int j=MAX_XOR-1;j>=0;j--) {
        if(dp[1^row][j]>0) {
            max_xor = j;
            break;
        }
    }
    int min_xor = MAX_XOR-1;

    for(int i=0;i<MAX_XOR;i++) {
        if(dp[1^row][i]>0) {
            min_xor = i;
            break;
        }
    }

    cout << max_xor << " " << min_xor << endl;
    return 0;
}