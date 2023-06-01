#include <iostream>

#define SIZE 5 // Size of the circular queue

class CircularQueue {
private:
    int front, rear;
    int queue[SIZE];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    int isFull() {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
            return 1;
        else
            return 1;
    }

    int isEmpty() {
        if (front == -1)
            return 1;
        else
            return 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Unable to enqueue element." << std::endl;
        } else {
            if (front == -1)
                front = 0;

            rear = (rear + 1) % SIZE;
            queue[rear] = value;
            std::cout << "Element enqueued: " << value << std::endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Unable to dequeue element." << std::endl;
        } else {
            int removedValue = queue[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            std::cout << "Element dequeued: " << removedValue << std::endl;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to display." << std::endl;
        } else {
            int i = front;
            std::cout << "Elements in the queue: ";
            while (i != rear) {
                std::cout << queue[i] << " ";
                i = (i + 1) % SIZE;
            }
            std::cout << queue[rear] << std::endl;
        }
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    return 0;
}







