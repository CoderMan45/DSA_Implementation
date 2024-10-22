//Implementing stack using only queue operations
#include<iostream>
#include<queue>

using namespace std;

queue<int> q1; queue<int> q2;
int q = 0;

void push(int data){
    if(q==0) q1.push(data);
    else q2.push(data);   
}

void pop(){
    if(q==0){
        while(q1.front()!=q1.back()){
            q2.push(q1.front());
            q1.pop();
        }       
        q1.pop();
        q=1;
    }
    else{
        while(q2.front()!=q2.back()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
        q=0;
    }

}

void display(){
    if(q==0){
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
    }
    else{
        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q2.pop();
        }
    }
}

int main(){
    push(30);
    push(40);
    push(60);
    push(90);
    pop();
    push(10);
    pop();
    pop();
    push(25);
    display();
}

