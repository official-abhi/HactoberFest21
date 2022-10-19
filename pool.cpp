#include <bits/stdc++.h>

using namespace std;

int solve(int n,int k){
    int ans=0;
    for(int i=1;i<=k;i++){
        int sum=i;
        for(int j=i+1;j<=k;j++){
            bool check=false;
        for(int l=j;l<n;l++){
            sum*=l;
            if(sum>k)break;
        }
        if(sum<=k){
            ans++;
            sum=i;
        }
           
        }
    }
    return ans;
}

int main() {
int t;
cout<<solve(2,4);
// while(t--){
//     int n,k;
//     cin>>n>>k;
//     cout<<solve(n,k)<<" "; 
// }
// cin>>n;
// vector<int>arr(n);
// for(auto&i:arr)cin>>i;
// unordered_map<int,int>mp;
// for(auto n:arr)mp[n]++;
// cout<<mp.size();


    return 0;
}

