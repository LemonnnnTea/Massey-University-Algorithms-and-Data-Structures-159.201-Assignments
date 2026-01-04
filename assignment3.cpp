#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int addr;
    string value;
    Node* next;
};

class queue {
    private:
    Node* front;
    Node* rear;
    public:
    queue();
    ~queue();
    void enqueue(int, string);
    void dequeue(int &, string &);
    bool isEmpty();
};
queue::queue() {
    front = NULL;
    rear = NULL;
}

queue::~queue() {
    Node* temp = front;
    while (temp != NULL) {
        front = temp->next;
        delete temp;
        temp = front;
    }
}

void queue::enqueue(int addr, string value) {
    Node* temp = new Node;
    temp->addr = addr;
    temp->value = value;
    temp->next = NULL;
    if (front == NULL) {
        front = temp;
    }
    if (rear != NULL) {
        rear -> next = temp;
    }
    rear = temp;
}


void queue::dequeue(int &addr, string &value) {
   if (front == NULL) {
        addr = -1;
        value = "";
        return;
    }
    value = front->value;
    addr = front->addr;
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

bool queue::isEmpty() {
    return front == NULL;
}

queue Port[256];
string output[256];

void write_to_output(){
    for (int i = 0; i < 256; i++) {
        if (!Port[i].isEmpty()) {
            int temp_addr;
            string temp_value;
            Port[i].dequeue(temp_addr, temp_value);
            if (temp_addr == -1) {
                continue;
            }
            if (output[temp_addr].empty()) {
                output[temp_addr] = temp_value;
            }
            else {
                output[temp_addr] += (" " + temp_value);
            }
        }
    }
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        istringstream is(input);
        int package_count;
        is >> package_count;
        for (int i = 0; i < package_count; i++) {
            int temp;
            is >> temp;
            int port = temp;
            is >> temp;
            int addr = temp;
            string value;
            is >> value;
            Port[port].enqueue(addr, value);
        }
        write_to_output();
    }
    while (1) {
        write_to_output();
        bool is_empty = true;
        for (int i = 0; i < 256; i++) {
            if (!Port[i].isEmpty()) {
                is_empty = false;
                break;
            }
        }
        if (is_empty) {
            break;
        }
    }
    for (int i = 0;i < 256;i++) {
        if (!output[i].empty()) {
            cout << i << " " << output[i] << endl;
        }
    }
    return 0;
}