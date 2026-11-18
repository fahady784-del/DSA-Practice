#include<iostream>

struct Node{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

Node* node1 = new Node;
Node* node2 = new Node;
Node* node3 = new Node;


// DISPLAY LIST
void display_list(){
    Node* current = first;

    while(current != NULL){
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n\n";
}


// REVERSE LINKED LIST
void reverse_list(){

    Node* previous = NULL;
    Node* current = first;
    Node* next = NULL;

    while(current != NULL){

        next = current->next;

        current->next = previous;

        previous = current;

        current = next;
    }

    last = first;

    first = previous;
}


int main(){

    // Create nodes
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Set first and last
    first = node1;
    last = node3;


    // Original list
    std::cout << "Original List:\n";
    display_list();


    // Reverse list
    reverse_list();


    // Reversed list
    std::cout << "Reversed List:\n";
    display_list();


    return 0;
}
