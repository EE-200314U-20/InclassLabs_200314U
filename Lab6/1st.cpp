#include <iostream>
using namespace std;

#define MAX_SIZE 25

class Stack {
private:
    int a[MAX_SIZE];
    int t;

public:
    Stack() {
        t = -1;
    }
    //check whether stack is empty.
    bool isEmpty() {
        if (t<0){
            return true;
        }
        else{
            return false;
        }
    }
    
    // push an element x to the stack
    bool push(int k) {
        t=t+1;
        if (t > MAX_SIZE ) {
            cout << "Stack Overflow!" << endl;
            return false;
        } else {
            a[t] = k;
            cout << k << " pushed into stack" << endl;
            return true;
        }
    }
    
    //remove a element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int popped_element = a[t];
            t=t-1;
            cout << popped_element << " popped from stack" << endl;
            return popped_element;
        }
    }

    //display the final stack
    void displayStack() {
        cout << "Final stack:" << endl;
        for(int i = 0; i <=t; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.displayStack();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(4);
    s.push(13);
    s.push(3);
    s.push(1);
    s.displayStack();
    return 0;
}
