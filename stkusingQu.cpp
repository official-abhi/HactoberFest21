#include<iostream>
#include<queue>
using namespace std;

class stack{
queue<int>qu1;


public:

void push(int val){
if(qu1.empty()){
    qu1.push(val);
    return;
}
qu1.push(val);
int siz = qu1.size()-1;
while(siz--){
    qu1.push(qu1.front());
    qu1.pop();
}


}
void pop(){
    if(!qu1.empty()){
        qu1.pop();
    }
}
int top(){
     if(!qu1.empty()){
     return   qu1.front();
    }
    return -1;
}


};


int main(){

stack stk;
stk.push(1);
stk.push(2);
stk.push(3);
stk.push(4);
stk.push(5);
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;
stk.pop();
cout<<stk.top()<<endl;


return 0;

}