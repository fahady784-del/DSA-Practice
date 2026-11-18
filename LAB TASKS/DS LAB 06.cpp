#include <iostream>
#include <string>

//ACTIVITY 1
class Que{

public:
    int size;
    int* q;
    int front;
    int rear;

    Que(){
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    Que(int x){
        size = x;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return rear == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void display(){
        if (isEmpty())
            std::cout << "\nQueue is empty!";
        else{
            for (int i = front; i <= rear; i++)
                std::cout << "\nValue at index " << i << " is: " << q[i];
        }
    }

    void Enqueue(int x){
        if (isFull())
            std::cout << "\nNo space";
        else{
            if (isEmpty()){
                front = rear = 0;
            }else{
                rear++;
            }
            q[rear] = x;
        }
    }

    int Dequeue(){
        if (isEmpty()){
            std::cout << "\nQueue is already empty";
            return -1;
        }

        int x = q[front];

        if (front == rear){
            front = rear = -1;
        }else{
            front++;
        }
        return x;
    }
};

//ACTIVITY 2
class ShiftQueue{

private:
    int size;
    int* que;
    int front;
    int rear;

public:
    ShiftQueue(int x){
        size = x;
        que = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void Enqueue(int x){
        if (isFull())
            std::cout << "\nQueue is Full";
        else{
            if (isEmpty()){
                front = rear = 0;
            }else{
                rear++;
            }
            que[rear] = x;
        }
    }

    void shift_left(int front, int rear){
        for (int i = front; i < rear; i++){
            que[i] = que[i + 1];
        }
    }

    int deQue(){
        int temp;

        if (!isEmpty()){
            temp = que[front];

            if (front == rear){
                front = rear = -1;
            }else{
                shift_left(front, rear);
                rear--;
            }
        }
        else{
            std::cout << "\nSorry Q is Empty";
            temp = -1;
        }

        return temp;
    }

    void display(){
        if (isEmpty()){
            std::cout << "\nQueue is Empty";
        }else{
            for (int i = front; i <= rear; i++){
                std::cout << que[i] << " ";
            }
        }
    }
};

//ACTIVITY 3
template <class T>
class Q{

private:
    T Data[10];
    int front;
    int rear;
    int count;

public:
    Q(){
        front = rear = count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == 10;
    }

    void enQue(T x){
        if (!isFull()){
            Data[rear] = x;
            rear = (rear + 1) % 10;
            count++;
        }
        else
            std::cout << "\nSorry Q is Full";
    }

    T deQue(){
        if (!isEmpty()){
            T temp = Data[front];
            front = (front + 1) % 10;
            count--;
            return temp;
        }
        else{
            std::cout << "\nSorry Q is Empty";
            return T();
        }
    }
};

//ACTIVITY 4
#define SIZE 10

class Deque{

private:
    int a[SIZE];
    int f, r;

public:
    Deque(){
        f = -1;
        r = -1;
    }

    void insert_at_end(int x){
        if (r == SIZE - 1)
            std::cout << "\nInsertion is not possible, overflow!";
        else{
            if (f == -1){
                f = r = 0;
            }else{
                r++;
            }

            a[r] = x;
            std::cout << "\nInserted item: " << x;
        }
    }

    void insert_at_beg(int x){
        if (f == 0){
            std::cout << "\nInsertion is not possible, overflow!";
        }else if (f == -1){
            f = r = 0;
            a[f] = x;
            std::cout << "\nInserted item: " << x;
        }else{
            f--;
            a[f] = x;
            std::cout << "\nInserted item: " << x;
        }
    }

    void delete_fr_front(){
        if (f == -1){
            std::cout << "\nDeque is empty";
        }else{
            std::cout << "\nDeleted element: " << a[f];

            if (f == r){
                f = r = -1;
            }else{
                f++;
            }
        }
    }

    void delete_fr_rear(){
        if (f == -1){
            std::cout << "\nDeque is empty";
        }else{
            std::cout << "\nDeleted element: " << a[r];

            if (f == r){
                f = r = -1;
            }else{
                r--;
            }
        }
    }

    void show(){
        if (f == -1){
            std::cout << "\nDeque is empty";
        }else{
            for (int i = f; i <= r; i++)
                std::cout << a[i] << " ";
        }
    }
};

//GRADED LAB TASK 1
struct QueueNode{
    int data;
    QueueNode* link;
};

class LinkedQueue{

private:
    QueueNode* front;
    QueueNode* rear;

public:
    LinkedQueue(){
        front = rear = NULL;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void Enqueue(int x){
        QueueNode* temp = new QueueNode;
        temp->data = x;
        temp->link = NULL;

        if (rear == NULL){
            front = rear = temp;
        }else{
            rear->link = temp;
            rear = temp;
        }
    }

    int Dequeue(){
        if (isEmpty()){
            std::cout << "\nQueue is Empty";
            return -1;
        }

        QueueNode* temp = front;
        int x = temp->data;
        front = front->link;

        if (front == NULL){
            rear = NULL;
        }

        delete temp;
        return x;
    }

    void display(){
        QueueNode* current = front;

        if (isEmpty()){
            std::cout << "\nQueue is Empty";
        }
        while (current != NULL){
            std::cout << current->data << " ";
            current = current->link;
        }
    }
};

//GRADED LAB TASK 2
struct DequeNode{
    int data;
    DequeNode* next;
    DequeNode* prev;
};

class LinkedDeque{

private:
    DequeNode* front;
    DequeNode* rear;

public:
    LinkedDeque(){
        front = rear = NULL;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void insert_at_beg(int x){
        DequeNode* temp = new DequeNode;
        temp->data = x;
        temp->prev = NULL;
        temp->next = front;

        if (isEmpty()){
            front = rear = temp;
        }else{
            front->prev = temp;
            front = temp;
        }
    }

    void insert_at_end(int x){
        DequeNode* temp = new DequeNode;
        temp->data = x;
        temp->next = NULL;
        temp->prev = rear;

        if(isEmpty()){
            front = rear = temp;
        }else{
            rear->next = temp;
            rear = temp;
        }
    }

    void delete_fr_front(){
        if (isEmpty()){
            std::cout << "\nDeque is Empty";
        }else{
            DequeNode* temp = front;
            std::cout << "\nDeleted: " << temp->data;
            front = front->next;

            if (front == NULL){
                rear = NULL;
            }else{
                front->prev = NULL;
            }

            delete temp;
        }
    }

    void delete_fr_rear(){
        if (isEmpty()){
            std::cout << "\nDeque is Empty";
        }else{
            DequeNode* temp = rear;
            std::cout << "\nDeleted: " << temp->data;
            rear = rear->prev;

            if(rear == NULL){
                front = NULL;
            }else{
                rear->next = NULL;
            }

            delete temp;
        }
    }

    void display(){
        DequeNode* current = front;

        if (isEmpty()){
            std::cout << "\nDeque is Empty";
        }

        while (current != NULL){
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main(){

    //ACTIVITY 1
    Que q1;
    q1.Enqueue(5);
    q1.Enqueue(7);
    q1.Enqueue(9);
    q1.display();
    std::cout << "\nDequeued: " << q1.Dequeue();
    std::cout << "\n\n";

    //ACTIVITY 2
    ShiftQueue q2(5);
    q2.Enqueue(10);
    q2.Enqueue(20);
    q2.Enqueue(30);
    std::cout << "Dequeued: " << q2.deQue() << "\n";
    q2.display();
    std::cout << "\n\n";

    //ACTIVITY 3
    Q<int> q3;
    Q<char> q4;
    Q<std::string> q5;

    q3.enQue(4);
    q3.enQue(7);
    std::cout << "Dequeued value: " << q3.deQue() << "\n";

    q4.enQue('A');
    q4.enQue('B');
    std::cout << "Dequeued value: " << q4.deQue() << "\n";

    q5.enQue("I");
    q5.enQue("Love");
    q5.enQue("Programming");
    std::cout << "Dequeued value: " << q5.deQue() << "\n\n";

    //ACTIVITY 4
    Deque d1;
    d1.insert_at_end(10);
    d1.insert_at_end(20);
    d1.insert_at_beg(5);
    d1.show();
    d1.delete_fr_front();
    d1.delete_fr_rear();
    std::cout << "\n";
    d1.show();
    std::cout << "\n\n";

    //GRADED LAB TASK 1
    LinkedQueue lq;
    lq.Enqueue(100);
    lq.Enqueue(200);
    lq.Enqueue(300);
    lq.display();
    std::cout << "\nDequeued: " << lq.Dequeue() << "\n";
    lq.display();
    std::cout << "\n\n";

    //GRADED LAB TASK 2
    LinkedDeque ld;
    ld.insert_at_beg(20);
    ld.insert_at_beg(10);
    ld.insert_at_end(30);
    ld.display();
    ld.delete_fr_front();
    ld.delete_fr_rear();
    std::cout << "\n";
    ld.display();

    return 0;
}
