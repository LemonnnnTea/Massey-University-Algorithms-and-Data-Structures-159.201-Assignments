#include <iostream>
#include <stack>
using namespace std;

struct node {
    char value;
    node* left;
    node* right;
    node() {
        left = right = nullptr;
    }
    node(char ch):value(ch) {
        left = right = nullptr;
    }
};

stack<node*> st;

void post_to_tree(string input, node* &T) {
    for (unsigned long i = 0; i < input.length(); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            st.push(new node(input[i]));
        }
        else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
            node* right = st.top();
            st.pop();
            node* left = st.top();
            st.pop();
            node* temp = new node(input[i]);
            temp -> right = right;
            temp -> left = left;
            st.push(temp);
        }
    }
    T = st.top();
    st.pop();
}

void inorder(node *root, string &output) {
    node *temp = root;
    if (temp == nullptr) {
        return;
    }
    if (temp->left || temp->right) {
        output += "(";
    }
    inorder(temp->left, output);
    output += temp->value;
    inorder(temp->right, output);
    if (temp->left || temp->right) {
        output += ")";
    }
}

int main() {
    node* root = new node;
    string input, output;
    output = "";
    cin >> input;
    post_to_tree(input, root);
    inorder(root, output);
    cout << output << endl;
    return 0;
}