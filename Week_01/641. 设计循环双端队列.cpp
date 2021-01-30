#include <map>
//https://leetcode-cn.com/problems/design-circular-deque/
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int> buffer;
    int k1;
    int count;
    int front;
    int rear;

    MyCircularDeque(int k) {
        buffer = vector<int>(k, 0);
        k1 = k;
        count = 0;
        front = k - 1;
        rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        bool ok = true;
        if (count == k1) {
            return false;
        }
        buffer[front] = value;
        front = (front - 1 + k1) % k1;
        count++;
        return ok;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        bool ok = true;
        if (count == k1) {
            return false;
        }
        buffer[rear] = value;
        rear = (rear + 1) % k1;

        count++;
        return ok;

    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        bool ok = true;
        if (count == 0) {
            return false;
        }
        front = (front + 1) % k1;
        count--;
        return ok;

    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        bool ok = true;
        if (count == 0) {
            return false;
        }
        rear = (rear - 1 + k1) % k1;

        count--;

        return ok;

    }

    /** Get the front item from the deque. */
    int getFront() {
        int vfront = 0;
        if (count == 0) {
            return -1;
        }
        vfront = buffer[(front + 1) % k1];
        return vfront;
    }

    /** Get the last item from the deque. */
    int getRear() {
        int vrear = 0;
        if (count == 0) {
            return -1;
        }
        vrear = buffer[(rear - 1 + k1) % k1];
        return vrear;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        bool ok = false;
        if (count == 0) {
            return true;
        }
        return ok;

    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        bool ok = false;
        if (count == k1) {
            return true;
        }
        return ok;

    }
};