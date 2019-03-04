#include <stdlib.h>
#include <assert.h>

class MyCircularQueue {
public:
    int* qarr, front, rear, qsize;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        qsize = k + 1;
        front = rear = 0;
        qarr = (int*) malloc(sizeof(int) * qsize);
        assert(qarr != NULL);
    }
    
    ~MyCircularQueue() {
        free(qarr);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        qarr[rear] = value;
        rear = (rear + 1) % qsize;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % qsize;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return qarr[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return rear == 0 ? qarr[qsize - 1] : qarr[rear - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == 0 ? (rear == qsize - 1) : front - 1 == rear;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */