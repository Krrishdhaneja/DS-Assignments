// Q1
#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
    int arr[SIZE];
    int front, rear;
public:
    SimpleQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << arr[front++] << " dequeued\n";
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    SimpleQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.peek();
    q.display();
}
// Q2
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == (rear + 1) % SIZE); }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << x << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << arr[front] << " dequeued\n";
            if (front == rear) front = rear = -1; // Queue becomes empty
            else front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else {
            cout << "Queue: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.dequeue();
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();
    cq.peek();
}
// Q3
#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    queue<int> firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int x : arr) q.push(x);

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
// Q4
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    unordered_map<char,int> freq;
    queue<char> q;

    for (char c : s) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
}
