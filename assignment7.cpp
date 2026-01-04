#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class minHeap {
private:
    vector <int> heap;
    int swapTimes = 0;
public:
    void swap(int&, int&);
    void insert(int);
    void sorting(int, int);
    void deleteMin();
    void del();
    int getSwapTimes();
};

int main() {
    minHeap heap;
    vector<int> v;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    for (int i = 0; i < size; i++) {
        heap.insert(v[i]);
    }
    int insertSwapTimes = heap.getSwapTimes();
    heap.del();
    int deleteSwapTimes = heap.getSwapTimes();
    cout << "original: " << insertSwapTimes << " + " << deleteSwapTimes << endl;
    heap = minHeap();


    sort(v.begin(), v.end());
    for (int i = 0; i < size; i++) {
        heap.insert(v[i]);
    }
    insertSwapTimes = heap.getSwapTimes();
    heap.del();
    deleteSwapTimes = heap.getSwapTimes();
    cout << "ascending: " << insertSwapTimes << " + " << deleteSwapTimes << endl;
    heap = minHeap();

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < size; i++) {
        heap.insert(v[i]);
    }
    insertSwapTimes = heap.getSwapTimes();
    heap.del();
    deleteSwapTimes = heap.getSwapTimes();
    cout << "descending: " << insertSwapTimes << " + " << deleteSwapTimes << endl;
    return 0;
}

void minHeap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    swapTimes++;
}

void minHeap::insert(int data) {
    this->heap.push_back(data);
    int index = this->heap.size() - 1;
    int parent = (index - 1) / 2;
    sorting(index, parent);
}

int minHeap::getSwapTimes() {
    int temp = this->swapTimes;
    this->swapTimes = 0;
    return temp;
}

void minHeap::sorting(int index, int parent) {
    while(index > 0) {
        if(heap[index] < heap[parent]) {
            this->swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
        else {
            return;
        }
    }
}


void minHeap::del(){
    while(!this->heap.empty()) {
        this->deleteMin();
    }
}

void minHeap::deleteMin() {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();

    int index = 0;
    int size = heap.size();

    while (2 * index + 1 < size) {
        int child = 2 * index + 1;
        if (child + 1 < size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[child] < heap[index]) {
            swap(heap[child], heap[index]);
            index = child;
        } else {
            break;
        }
    }
}
