/*-----------------------
PRODIPTA SHAKAR DAS AKASH
ID:        05624205101051
Course:    CSE-06131211
Session:   Fall-24
Dept:      CSE
NEUB
-----------------------*/
#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MAX 10

class Stack1{
    int top, stack[MAX];

    public:

    Stack1(){
        top = -1;
    }

    void print(){
        if (top == -1){
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = 0; i <= top; i++) cout << stack[i] << " ";
        cout << endl;
    }

    void push(int value){
        if (top > MAX){
            cout << "Stack Overflow" << endl;
            return;
        }
        else{
            top++;
            stack[top] = value;
        }
    }

    int pop(){
        if (top == -1){
            cout << "Stack underflow." << endl;
            return -1;
        }
        top--;
        return stack[top + 1];
    }

    bool isEmpty() {
        return top == -1;
    }

};

int main(){
    //optimize();

    Stack1 s;
    int dec, del;
    cout << "Enter A Decimal Number: ";
    cin >> dec;

    while (dec != 0){
        s.push(dec % 2);
        dec /= 2;
    }

    cout << "Binary Number Is: ";
    while (s.isEmpty() == false){
        cout << s.pop();
    }

    return 0;
}
