// #include<bits/stdc++.h>
// using namespace std;

// int funct(long long int x,long long int y,long long int l,long long int r){
//    long long int mxsum= 0;
//     int cnt=0;
// for(int i=l;i<=r;i++){
//     mxsum=i;
//     if(mxsum>=x && mxsum<=y)cnt++;
//     for(int j=i+1;j<=r && mxsum<=y;j++){
//         mxsum+=j;
//         if(mxsum>=x && mxsum<=y)cnt++;
//     }
// }
// return cnt;
// }






// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//        long long int q,l,r;
//         cin>>q>>l>>r;
//         while(q--){long long int x,y;
//             cin>>x>>y;
//             cout<<funct(x,y,l,r)<<endl;
//         }
//     }
//     return 0;
// }




#include <bits/stdc++.h>

using namespace std;

int main() {
int l,u,t;
cin>>l>>u>>t;
t*=1000;
int m=0,n=0,lt=t,ut=t;
bool flag=true;
while((lt>0 || ut>0) && flag){
	if(lt>0){
		if(lt==u){
			lt=0;
			m++;
		}else{
			if(lt>=l){
				lt-=l;
				m++;
			}else
			flag=false;
		}
	}
	if(ut>0){
		if(ut==l){
			ut=0;
			n++;
		}else{
			if(ut>=u){
				ut-=u;
				n++;
			}else{
				flag=false;
			}
		}
	}
}
if(flag){
	cout<<n<<endl<<m;
}else{
	cout<<-1<<endl<<-1;
}

	return 0;
}