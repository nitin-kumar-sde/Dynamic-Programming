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

ll sumOfDigits(ll n) {
    
    if(n<0)
    return 0;

    if(n<10)
    return (n*(n+1))/2;
    
    ll temp = n;
    ll firstDigit = temp;
    int cnt = 0;

    while(temp/10) {
        temp/=10; 
        firstDigit = temp;
        cnt++;
    }

    ll ans = pow(10, cnt) * ((firstDigit-1)* (firstDigit))/2;

    ans += (firstDigit * cnt* pow(10, cnt-1) * 45);

    ll rem = n -firstDigit * pow(10, cnt);

    ans += (firstDigit * (rem+1));
    ans+=sumOfDigits(rem);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DYNAMIC-PROGRAMMING/output.txt", "w", stdout);
    #endif

    while(1) {
        ll a,b; 
        cin >> a >> b;

        if(a == -1 && b== -1)
        break;

        ll sum1 = sumOfDigits(a-1);
        ll sum2 = sumOfDigits(b);
         
        cout << sum2 - sum1 << endl;
    }

    return 0;
}