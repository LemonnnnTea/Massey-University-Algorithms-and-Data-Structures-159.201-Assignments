#include <iostream>
using namespace std;

struct Node{
    int index;
    int value;
    Node *next;
};

void AddNode(Node *&head, int index, int value){
    Node *temp = new Node;
    temp->index = index;
    temp->value = value;
    temp->next = nullptr;
    if(head == nullptr) {
        head = temp;
    }
    else {
        Node *current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

void readLinkedList(Node *&listptr){
    int num_node;
    cin >> num_node;
    for (int i = 0; i < num_node; i++){
        int index_tmp, value_tmp;
        cin >> index_tmp >> value_tmp;
        if (value_tmp != 0) {
            AddNode(listptr, index_tmp, value_tmp);
        }
    }
}

void PrintLL(Node *head){
    Node *current = head;
    while(current != nullptr) {
        cout << current->index << " " << current->value <<" ";
        current = current->next;
    }
}

int value_check(Node* listptr1, Node* listptr2) {
    if (listptr1 != nullptr) {
        if (listptr2 == nullptr ||listptr1->index < listptr2->index) {
            return 1;
        }
    }
    if (listptr2 != nullptr) {
        if (listptr1 == nullptr || listptr2->index < listptr1->index) {
            return 2;
        }
    }
    return 0;
}

Node *AddMatrices(Node *listptr1, Node *listptr2, int &nonZeroCount) {
    Node *result = nullptr;
    Node *current1 = listptr1;
    Node *current2 = listptr2;
    while (current1 != nullptr || current2 != nullptr) {
        int index_temp, value_temp;
        switch (value_check(current1, current2)) {
            case 0: {
                index_temp = current1->index;
                value_temp = current1->value + current2->value;
                current1 = current1->next;
                current2 = current2->next;
                if (value_temp == 0) {
                    continue;
                }
                break;
            }
            case 1: {
                index_temp = current1->index;
                value_temp = current1->value;
                current1 = current1->next;
                break;
            }
            case 2: {
                index_temp = current2->index;
                value_temp = current2->value;
                current2 = current2->next;
                break;
            }
            default: {
                break;
            }
        }
        nonZeroCount++;
        AddNode(result, index_temp, value_temp);
    }
    return result;
}

void FreeMemory(Node *&head){
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Node *listptr1 = nullptr;
    Node *listptr2 = nullptr;
    int nonZeroCount = 0;
    readLinkedList(listptr1);
    readLinkedList(listptr2);
    Node *result = AddMatrices(listptr1, listptr2, nonZeroCount);
    cout << nonZeroCount << " ";
    PrintLL(result);
    FreeMemory(listptr1);
    FreeMemory(listptr2);
    FreeMemory(result);
    return 0;
}