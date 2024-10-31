

#include <iostream>

const int MAX_SIZE = 5;

class Queue {
private:
    int arr[MAX_SIZE];
    int head;
    int tail;
public:
    Queue() {
        head = -1;
        tail = -1;
    }

    void enqueue(int element) {
        if (tail == MAX_SIZE - 1) {
            std::cout << "Queue is full!" << std::endl;
        } else {
            if (head == -1) head = 0;
            arr[++tail] = element;
        }
    }

    int dequeue() {
        if (head == -1) {
            std::cout << "Queue is empty!" << std::endl;
            return -1; // Return -1 to indicate that the queue is empty
        } else {
            int element = arr[head];
            if (head == tail) {
                head = -1;
                tail = -1;
            } else {
                head++;
            }
            return element;
        }
    }

    void printQueue() {
        if (head == -1) {
            std::cout << "Queue is empty!" << std::endl;
        } else {
            for (int i = head; i <= tail; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.printQueue();

    std::cout << "Dequeued element: " << q.dequeue() << std::endl;
    std::cout << "Dequeued element: " << q.dequeue() << std::endl;

    q.printQueue();

    return 0;
}
