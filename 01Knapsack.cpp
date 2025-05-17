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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    int * weight = new int [n];

    for(int i=0;i<n;i++)
    cin >> weight[i];

    int * value = new int[n];

    for(int i=0;i<n;i++)
    cin >> value[i];

    int maxWeight; 
    cin >> maxWeight;

    int * dp = new int[1 + maxWeight];

    fill(dp, dp + 1 + maxWeight, 0);

    for(int i=n-1;i>=0;i--) {

       for(int j=maxWeight;j>=0;j--) {
        if(j >= weight[i])
        dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
    }
   }
   cout << dp[maxWeight] << endl;
    return 0;
}