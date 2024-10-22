// Implement queue using stack operations only
#include <iostream>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;
int s=0;

void enque(int data)
{
    if (s == 0)
    {
        s1.push(data);
    }
    else
    {
        s = 0;
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(data);
    }
}

void dequeue()
{
    if (s == 1)
    {
        s2.pop();
    }
    else
    {
        s = 1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
}

void display()
{
    if (s == 0)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
    }
    else
    {
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
    }
}

int main()
{
    enque(45);
    enque(53);
    enque(77);
    enque(49);
    enque(60);
    enque(100);
    dequeue();
    dequeue();
    enque(10);
    enque(97);
    dequeue();
    dequeue();
    display();
}