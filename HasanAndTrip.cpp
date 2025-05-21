#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 3005
#define MOD 1000000007

int x[N];
int y[N];
int f[N];

double dp[N];
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
    {
        cin >> x[i];
        cin >> y[i];
        cin >> f[i];
    }

    dp[n-1] = f[n-1];

    for(int i=n-2;i>=0;i--) {
        dp[i] = f[i];
        double maxHapp = -1e9;

        for(int j=i+1;j<n;j++) {
            ll delX = (x[i] - x[j])* (x[i] - x[j]);
            ll delY = (y[i] - y[j])*(y[i] - y[j]);

            double dist = sqrt(delX  + delY);
            maxHapp = max(maxHapp, dp[j] - dist);
        }
        dp[i] += maxHapp;
    }

    cout << fixed << setprecision(6) << dp[0] << endl;
    return 0;
}