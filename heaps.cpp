#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    void maxheapify(vector<int>& v, int n, int i) { // maxheap: 1-based indexing 
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && v[largest] < v[left]) {
            largest = left;
        }
        if (right <= n && v[largest] < v[right]) {
            largest = right;
        }
        if (largest != i) {
            swap(v[largest], v[i]);
            maxheapify(v, n, largest);
        }
    }

    void minheapify(vector<int>& v, int n, int i) { // minheap: 1-based indexing 
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && v[smallest] > v[left]) {
            smallest = left;
        }
        if (right <= n && v[smallest] > v[right]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(v[smallest], v[i]);
            minheapify(v, n, smallest);
        }
    }

    void buildheap(vector<int>& v, int n) {
        for (int i = n / 2; i > 0; i--) { // Start from the last non-leaf node
            maxheapify(v, n, i);
        }
    }

    void heapsort(vector<int>& v, int n) {
        buildheap(v, n);
        int size = n;

        while (size >= 2) {
            swap(v[1], v[size]); // Swap root with last element
            size--;              // Reduce the size of the heap
            maxheapify(v, size, 1); // Rebuild heap for reduced size
        }
    }
};

int main() {
    vector<int> v = {-1, 12, 15, 13, 11, 14}; // 1-based indexing
    int n = v.size() - 1; // Size of the heap (excluding the dummy 0th index)

    MaxHeap heap;
    heap.buildheap(v, n);
    heap.heapsort(v,n);

    for (int i = 1; i <= n; i++) { // Start from 1 for 1-based indexing
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
