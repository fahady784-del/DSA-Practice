#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* first = NULL;
Node* last = NULL;


// ACTIVITY 01

void insert_at_end(){

    Node* new_node = new Node;

    std::cout << "Enter data: ";
    std::cin >> new_node->data;

    new_node->next = NULL;
    new_node->prev = NULL;

    if(first == NULL){
        first = last = new_node;

    }else{

        last->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}


// ACTIVITY 02

void display_forward(){

    Node* current = first;

    while(current != NULL){

        std::cout << current->data << " ";
        current = current->next;
    }
}

void display_backward(){

    Node* current = last;

    while(current != NULL){

        std::cout << current->data << " ";
        current = current->prev;
    }
}


// ACTIVITY 03

void insert_at_start(){

    Node* new_node = new Node;

    std::cout << "Enter data: ";
    std::cin >> new_node->data;

    new_node->prev = NULL;
    new_node->next = first;

    if(first == NULL){
        first = last = new_node;

    }else{

        first->prev = new_node;
        first = new_node;
    }
}


void insert_after_node(){

    int specific_node;

    std::cout << "Enter a Specific Node: ";
    std::cin >> specific_node;

    Node* current = first;

    while(current != NULL){

        if(current->data == specific_node){
            Node* new_node = new Node;

            std::cout << "Enter data: ";
            std::cin >> new_node->data;

            new_node->prev = current;
            new_node->next = current->next;

            if(current->next != NULL){
                current->next->prev = new_node;
            }else{
                last = new_node;
            }

            current->next = new_node;

            std::cout << "New node linked successfully!\n";
            break;
        }

        current = current->next;

        if(current == NULL){
            std::cout << "Value not found!\n";
        }
    }
}


// ACTIVITY 04

void delete_first_node(){

    if(first == NULL){
        std::cout << "List is empty!\n";

    }else{
        Node* current = first;

        first = first->next;

        if(first == NULL){
            last = NULL;
        }else{
            first->prev = NULL;
        }

        delete current;

        std::cout << "First node deleted successfully!\n";
    }
}


void delete_last_node(){

    if(first == NULL){
        std::cout << "List is empty!\n";

    }else{
        Node* current = last;

        last = last->prev;

        if(last == NULL){
            first = NULL;

        }else{
            last->next = NULL;
        }

        delete current;

        std::cout << "Last node deleted successfully!\n";
    }
}


void delete_specific_node(){

    int specific_node;

    std::cout << "Enter the node to delete: ";
    std::cin >> specific_node;

    if(first == NULL){
        std::cout << "List is empty!\n";

    }else{
        Node* current = first;

        while(current != NULL){
            if(current->data == specific_node){
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;

            std::cout << "Node deleted successfully!\n";
            break;
            }

            current = current->next;

            if(current == NULL){
                std::cout << "Value not found!\n";
            }
        }
    }
}


// ACTIVITY 05

void delete_list(){

    while(first != NULL){
        Node* current = first;

        first = first->next;

        delete current;
    }

    last = NULL;

    std::cout << "Doubly Linked List deleted.\n";
}


// GRADED LAB TASKS

// LAB TASK 01

void reverse_list(){

    Node* current = first;
    Node* temp = NULL;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    temp = first;
    first = last;
    last = temp;

    std::cout << "Reversed successfully!\n";
}


// LAB TASK 02

void swap_nodes(){

    int value1;
    int value2;

    std::cout << "Enter first value: ";
    std::cin >> value1;

    std::cout << "Enter second value: ";
    std::cin >> value2;

    Node* first_node = first;
    Node* second_node = first;

    while(first_node->data != value1)
    {
        first_node = first_node->next;
    }

    while(second_node->data != value2)
    {
        second_node = second_node->next;
    }

    Node* temp_prev = first_node->prev;
    Node* temp_next = first_node->next;

    first_node->prev->next = second_node;
    first_node->next->prev = second_node;

    second_node->prev->next = first_node;
    second_node->next->prev = first_node;

    first_node->prev = second_node->prev;
    first_node->next = second_node->next;

    second_node->prev = temp_prev;
    second_node->next = temp_next;

    std::cout << "Nodes swapped successfully!\n";
}


// LAB TASK 03

void convert_to_doubly(Node* singly_first){

    first = NULL;
    last = NULL;

    Node* current = singly_first;

    while(current != NULL)
    {
        Node* new_node = new Node;

        new_node->data = current->data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if(first == NULL)
        {
            first = last = new_node;
        }
        else
        {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }

        current = current->next;
    }

    std::cout << "Singly Linked List converted into Doubly Linked List!\n";
}


int main(){

    // ACTIVITY 01

    std::cout << "Creation of Doubly Linked List\n";

    insert_at_end();
    insert_at_end();
    insert_at_end();


    // ACTIVITY 02

    std::cout <<"Accessing Nodes Forward\n";

    display_forward();

    std::cout <<"\n";

    std::cout <<"Accessing Nodes Backward\n";

    display_backward();

    std::cout <<"\n\n";


    // ACTIVITY 03

    std::cout <<"Insert at Start\n";

    insert_at_start();

    std::cout << "\n";
    std::cout << "Insert After Specific Node\n";

    insert_after_node();


    // ACTIVITY 04

    std::cout << "Delete First Node\n";

    delete_first_node();

    std::cout << "Delete Last Node\n";

    delete_last_node();

    std::cout << "Delete Specific Node\n";

    delete_specific_node();


    // ACTIVITY 05

    std::cout << "Delete Whole List\n";

    delete_list();

    std::cout << "\n\n";


    // GRADED LAB TASKS


    // LAB TASK 01

    std::cout << "Reverse Doubly Linked List\n";

    reverse_list();


    // LAB TASK 02

    std::cout << "Swap Two Nodes\n";

    swap_nodes();


    // LAB TASK 03

    std::cout << "Convert Singly Linked List to Doubly Linked List\n";

    convert_to_doubly(singly_first);

    return 0;
}
