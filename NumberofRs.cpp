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
// finds maximum sum sub array
int kadane(int dp[],int n){
       int ans=-1;
       int curr=0;
       for(int i=0;i<n;i++) {
        if(curr<0)
        curr=0;
        
        curr+=dp[i];
        ans=max(ans,curr);
    }
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

    int t; cin >> t;

    while(t--)
    {  
        string s;
        cin>>s;
        int l=s.length();
        int count_r=0;
        int input[l];
         for(int i=0;i<l;i++)
             {
                 if(s[i]=='R')
                  {
                      count_r++;
                      input[i]=-1;
                  }
                  else
                  input[i]=1;
             }
             
        int max_sub=kadane(input,l);     
        int ans=count_r+max_sub;
        cout<<ans<<endl;
        
        
    }
    return 0;
}