#include <iostream>
using namespace std;

string karaoke_queue[10]; // Limiting to max_queue = 10
int front = -1, rear = -1;
int max_queue = 10;

bool isFull() {
    return (rear + 1) % max_queue == front;
}

bool isEmpty() {
    return front == -1;
}

string enqueue(string song) {
    if (isFull()) return "The queue is full. Try again later";

    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % max_queue;

    karaoke_queue[rear] = song;
    return "A new song has been added to the queue";
}

string dequeue() {
    if (isEmpty()) return "There is no song in the queue. Try adding first";

    string song = karaoke_queue[front];

    if (front == rear) front = rear = -1;  // Queue is now empty
    else front = (front + 1) % max_queue;

    return song;
}

int main() {
    cout << enqueue("Lion") << endl;
    cout << enqueue("Back To Me") << endl;
    cout << enqueue("Kiss The Rain") << endl;

    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;

    return 0;
}