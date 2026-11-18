/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

// INSERTION
void insert(int x) {
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = NULL;

    if (first == NULL) {
        first = new_node;
        last = new_node;
        last->next = first;
    }
    else {
        last->next = new_node;
        last = new_node;
        last->next = first;
    }
}

// DISPLAY
void display() {
    Node* current = first;

    if (first == NULL) {
        return;
    }

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != first);

    cout << endl;
}

// JOSEPHUS PROBLEM
void josephus(int m) {
    Node* current = first;
    Node* previous = last;

    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        current = previous->next;
    }

    cout << "Winner: " << current->data << endl;
}

int main() {
    int n, m;

    cout << "Enter number of persons: ";
    cin >> n;

    cout << "Enter counting number: ";
    cin >> m;

    for (int i = 1; i <= n; i++) {
        insert(i);
    }

    cout << "Circular Linked List: ";
    display();

    josephus(m);

    return 0;
}
*/













#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

void insert(int x){

    Node* new_Node = new Node;
    new_Node->data = x;

    if(first == NULL){
        first = last = new_Node;
        last->next = first;
    }else{
        last->next = new_Node;
        last = new_Node;
        last->next = first;
    }
}
// DISPLAY
void display() {
    Node* current = first;

    if (first == NULL) {
        return;
    }

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != first);

    cout << endl;
}

void josephus(int r){
    Node* current = first;
    Node* previous = last;

    while(current->next != current){
        for(int i = 1; i < r; i++){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current = previous->next;
    }
     cout << "Winner: " << current->data << endl;
}

int main(){

    int n, m;

    cout<<"Enter the number of persons: ";
    cin>>n;

    cout<<"Enter the counting number: ";
    cin>>m;

    for(int i = 1;i<=n;i++) insert(i);

    cout<<"List is: ";
    display();

    josephus(m);


    return 0;
}
