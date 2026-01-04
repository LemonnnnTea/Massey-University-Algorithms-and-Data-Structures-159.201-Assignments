#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int data);
    int pop();
};

bool read_value(Stack &stack, int& v1, int& v2) {
    if (stack.isEmpty() == true) {
        return false;
    }
    else {
        v1 = stack.pop();
    }
    if (stack.isEmpty() == true) {
        return false;
        }
    else {
        v2 = stack.pop();
        }
    return true;
}

int read_number(int i) {
    while (true) {
        int temp = getchar();
        if (temp >= '0' && temp <= '9') {
            i = i * 10 + (temp - '0');
        }
        else if (temp == '\n') {
            cout << "INVALID"<<endl;
            exit(0);
        }
        else {
            return i;
        }
    }
}

int main() {
    Stack stack;
    int input;
    int value1, value2;
    bool check = false;
    while ((input = getchar()) != '\n') {
        if (input >= '0' && input <= '9') {
            stack.push(read_number(input - '0'));
            continue;
        }
        else if (input == '-') {
            int temp = getchar();
            if (temp == '\n') {
                check = true;
            }
            if (temp >= '0' && temp <= '9') {
                stack.push(-1 * read_number((temp - '0')));
                continue;
            }
        }
        if (input == '+' || input == '-' || input == '*' || input == '/') {
            if (read_value(stack, value1, value2) == false) {
                cout << "INVALID"<<endl;
                return 0;
            }
            switch (input) {
                case '+': {
                    value2 = value2 + value1;
                    stack.push(value2);
                    break;
                }
                case '-': {
                    value2 = value2 - value1;
                    stack.push(value2);
                    break;
                }
                case '*': {
                    value2 = value2 * value1;
                    stack.push(value2);
                    break;
                }
                case '/': {
                    if (value1 == 0) {
                        cout << "INVALID"<<endl;
                        return 0;
                    }
                    value2 = value2 / value1;
                    stack.push(value2);
                    break;
                }
                default: {
                    break;
                }
            }
        }
        if (stack.isEmpty()) {
            cout << "INVALID";
            return 0;
        }
        if (check == true) {
            break;
        }
    }

    int output =  stack.pop();
    if (!stack.isEmpty()) {
        cout << "INVALID";
        return 0;
    }
    cout << output;
    return 0;
}

bool Stack::isEmpty(){
    return top == nullptr;
}

Stack::~Stack() {
    while (!Stack::isEmpty()) {
        pop();
    }
}
Stack::Stack() {
    top = nullptr;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "INVALID" << endl;
        exit(0);
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

void Stack::push(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = top;
    top = temp;
}