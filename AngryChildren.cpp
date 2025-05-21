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
ll input[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    int n,k; cin >> n >> k;

    for(int i=0;i<n;i++)
    cin >> input[i];
    
    sort(input, input+n);
    
    ll sum =  input[0];;
    ll posAns = 0;

    for(int i=1;i<k;i++) {
        posAns = posAns + i* input[i] - sum;
        sum+=input[i];
    }
    
    ll ans = posAns;

    for(int i=k; i<n;i++) {
        sum -= input[i-k];
        posAns = posAns + input[i]*(k-1) + input[i-k]*(k-1) - 2*sum;
        sum+=input[i];
        ans = min(ans, posAns);
    }

    cout << ans << endl;
    return 0;
}