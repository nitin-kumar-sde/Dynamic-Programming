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

ll coins[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int T; cin >> T;

    for(int t=1 ;t <=T; t++) {
        int n; cin >> n;

        for(int i=0;i<n;i++) 
        cin >> coins[i];

        if(n==0) {
        cout << "Case " << t <<": " << 0 << endl;
        continue;
        }

        if(n == 1) {
            cout << "Case " << t <<": " << coins[0] << endl;
            continue;
        }

        ll prev_2 = coins[n-1];
        ll prev_1 = max(coins[n-1], coins[n-2]);

        for(int i = n-3; i>=0;i--) {
            ll ans = max(coins[i] + prev_2, prev_1);
            prev_2 = prev_1;
            prev_1 = ans;
        }

        cout << "Case " << t <<": " << prev_1 << endl;
        
    }

    return 0;
}