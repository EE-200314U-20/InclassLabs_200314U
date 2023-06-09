#include <iostream>
#include <chrono> 
using namespace std;



class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head;

    Stack() {
        head = nullptr;
    }
    

    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    int pop() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int popped_data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return popped_data;
    }
    
    void display() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
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
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    
    

    
    return 0;
}
