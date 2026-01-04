#include <iostream>
#include <stack>

using namespace std;
stack<int> input1, input2, output;;

int main () {
    int up = 0;
    string temp;
    cin >> temp;
    for (unsigned long i = 0; i < temp.length(); i++) {
        input1.push(temp[i] - '0');
    }
    cin >> temp;
    for (unsigned long i = 0; i < temp.length(); i++) {
        input2.push(temp[i] - '0');
    }
    unsigned long size = input1.size() > input2.size() ? input1.size() : input2.size();
    for (unsigned long i = 0; i < size; i++) {
        int temp1 = 0, temp2 = 0;
        if (!input1.empty()) {
            temp1 = input1.top();
            input1.pop();
        }
        if (!input2.empty()) {
            temp2 = input2.top();
            input2.pop();
        }
        int temp_add = temp1 + temp2 + up;
        up = 0;
        if (temp_add >= 10) {
            temp_add -= 10;
            up = 1;
        }
        output.push(temp_add);
    }
    if (up == 1) {
        output.push(1);
    }
    unsigned long opt_size = output.size();
    for (unsigned long i = 0; i < opt_size; i++) {
        cout << output.top();
        output.pop();
    }
    return 0;
}