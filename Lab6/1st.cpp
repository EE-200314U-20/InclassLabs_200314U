#include <iostream>
using namespace std;

#define MAX_SIZE 25

class Stack {
private:
    int stackArr[MAX_SIZE];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    // Check whether the stack is empty
    bool isEmpty() {
        if (topIndex < 0) {
            return true;
        } else {
            return false;
        }
    }

    // Push an element 'item' to the stack
    bool push(int item) {
        topIndex = topIndex + 1;
        if (topIndex > MAX_SIZE) {
            cout << "Stack Overflow!" << endl;
            return false;
        } else {
            stackArr[topIndex] = item;
            cout << item << " pushed into the stack" << endl;
            return true;
        }
    }

    // Remove and return the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int poppedElement = stackArr[topIndex];
            topIndex = topIndex - 1;
            cout << poppedElement << " popped from the stack" << endl;
            return poppedElement;
        }
    }

    // Display the final stack contents
    void displayStack() {
        cout << "Final stack:" << endl;
        for (int i = 0; i <= topIndex; i++) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.displayStack();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(4);
    stack.push(13);
    stack.push(3);
    stack.push(1);
    stack.displayStack();

    return 0;
}
