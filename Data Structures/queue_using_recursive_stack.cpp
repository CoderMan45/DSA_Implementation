//Implementing queue using stack recursively
#include <iostream>
#include <stack>
using namespace std;

void enque(stack<int>& S, int data){
    S.push(data);
}

void dequeue(stack<int>& S){
    int res = S.top();
    S.pop();
    if(S.empty()){
        return;
    }
    dequeue(S);
    S.push(res);
}

void display_queue(stack<int>& S){
    int res = S.top();
    S.pop();
    if(S.empty()){
        cout<<res<<" ";
        return;
    }
    display_queue(S);
    cout<<res<<" ";   
}

int main(){
    stack<int> S;
    enque(S, 50);
    enque(S, 80);
    enque(S, 90);
    enque(S, 120);
    enque(S, 30);
    enque(S, 20);
    dequeue(S);
    enque(S, 60);
    dequeue(S);
    display_queue(S);

}
