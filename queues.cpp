#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> stack1, stack2;  // Two stacks for implementing queue

public:
    // Enqueue operation
    void enqueue(int x) {
        // Push the element into stack1
        stack1.push(x);
    }

    // Dequeue operation
    void dequeue() {
        // If both stacks are empty, the queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // If stack2 is empty, move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop the element from stack2 (front of the queue)
        int front = stack2.top();
        stack2.pop();
        //return front;
    }

    // Check if the queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    // Get the front element of the queue
    int front() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // If stack2 is empty, move elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // Output: 10

    cout << "Dequeue element: " << q.dequeue() << endl;  // Output: 10
    cout << "Dequeue element: " << q.dequeue() << endl;  // Output: 20

    cout << "Front element after dequeue: " << q.front() << endl;  // Output: 30

    return 0;
}
