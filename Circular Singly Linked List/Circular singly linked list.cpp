#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = first;


//ACTIVITY 01
void creation() {
    Node* new_node = new Node;

    std::cout << "Enter data for the node: ";
    std::cin >> new_node->data;

    if (first == NULL) {
        first = last = new_node;
        new_node->next = first;
    }
    else {
        last->next = new_node;
        last = new_node;
        last->next = first;
    }
}

//ACTIVITY 02
void access_node(){
    Node* current = first;

    int search_key = 0;
    int count_index = 0;
    if(first==NULL){
        std::cout<<"List is Empty!";
        return;
    }

    std::cout<<"Enter the value to search: ";
    std::cin>>search_key;

    do{
        if(current->data == search_key){
            std::cout<<"Value Found! at index "<<count_index<<"\n";
            return;
        }
        current=current->next;
        count_index++;
    }while(current!=first);

    std::cout<<"Value not Found!!"<<"\n";
}

//ACTIVITY 03
void insertion_before() {
    Node* current = first;
    Node* new_Node = new Node;

    int value;

    std::cout << "Enter the value of node (BEFORE): ";
    std::cin >> value;

    std::cout << "Enter the new node value: ";
    std::cin >> new_Node->data;

    if (first == NULL) {
        std::cout << "List is Empty!";
        return;
    }

    do {
        if (current->next->data == value) {
            new_Node->next = current->next;
            current->next = new_Node;

            std::cout << "Node Inserted!"<<"\n";
            return;
        }

        current = current->next;

    } while (current != first);

    std::cout << "Value not found!"<<"\n";
}
void insertion_after(){
    Node* current = first;
    Node* new_Node = new Node;

    int value;

    std::cout << "Enter the value of node (AFTER): ";
    std::cin >> value;

    std::cout << "Enter the new node value: ";
    std::cin >> new_Node->data;

    if (first == NULL) {
        std::cout << "List is Empty!";
        return;
    }

    do {
        if (current->data == value) {
            new_Node->next = current->next;
            current->next = new_Node;

            std::cout << "Node Inserted!"<<"\n";
            return;
        }

        current = current->next;

    } while (current != first);

    std::cout << "Value not found!"<<"\n";
}

//ACTIVITY 04
void deletion_specific(){
    Node* current = first;

    int value;

    std::cout << "Enter the value of node (DELETE): ";
    std::cin >> value;

    if (first == NULL) {
        std::cout << "List is Empty!";
        return;
    }

    do {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;

            std::cout << "Node Deleted!"<<"\n";
            return;
        }

        current = current->next;

    } while (current != first);

    std::cout << "Value not found!"<<"\n";
}

//ACTIVITY 05

void delete_complete(){
    Node* current = first;

    if(first == NULL){
        return;
    }

    do{
        Node* temp = current;
        current = current->next;
        delete temp;
    }while(current != first);

    first = NULL;
    last = NULL;
}

//GRADED LAB TASKS
//LAB TASK 01
void delete_even_values(){
    Node* current = first;

    if(first == NULL){
        std::cout<<"List is Empty!";
        return;
    }

    do{
        if(current->data % 2 == 0){
            Node* temp = current;
            Node* current2 = first;

            while(current2->next != current){
                current2 = current2->next;
            }

            current2->next = temp->next;
            current = current->next;
            delete temp;
        }
        else{
            current = current->next;
        }

    }while(current != first);

    std::cout<<"Even nodes deleted!"<<"\n";
}


void delete_odd_values(){
    Node* current = first;

    if(first == NULL){
        std::cout<<"List is Empty!";
        return;
    }

    do{
        if(current->data % 2 != 0){
            Node* temp = current;
            Node* current2 = first;

            while(current2->next != current){
                current2 = current2->next;
            }

            current2->next = temp->next;
            current = current->next;
            delete temp;
        }
        else{
            current = current->next;
        }

    }while(current != first);

    std::cout<<"Odd nodes deleted!"<<"\n";
}

//LAB TASK 02
void josephus_problem(){
    Node* current = first;

    int k;

    if(first == NULL){
        std::cout<<"List is Empty!";
        return;
    }

    std::cout<<"Enter the counting interval: ";
    std::cin>>k;

    while(first != last){
        int count = 1;

        while(count < k){
            current = current->next;
            count++;
        }

        Node* temp = current;
        Node* current2 = first;

        while(current2->next != current){
            current2 = current2->next;
        }

        current2->next = temp->next;

        if(current == first){
            first = current->next;
        }

        if(current == last){
            last = current2;
        }

        current = current->next;
        delete temp;

        last->next = first;
    }

    std::cout<<"Survivor: "<<first->data<<"\n";
}

//LAB TASK 03
void delete_even_positions(){
    Node* current = first;
    int position = 1;

    if(first == NULL){
        std::cout<<"List is Empty!";
        return;
    }

    do{
        if(position % 2 == 0){
            Node* temp = current;
            Node* current2 = first;

            while(current2->next != current){
                current2 = current2->next;
            }

            current2->next = temp->next;
            current = current->next;
            delete temp;
        }
        else{
            current = current->next;
        }

        position++;

    }while(current != first);

    std::cout<<"Even-positioned nodes deleted!"<<"\n";
}


//DISPLAY
void display(){
    Node* current = first;
    do{
        std::cout<<current->data<<" ";
        current = current->next;
    }while(current != first);
    std::cout<<"\n\n";
}


int main(){

    //ACTIVITY 01
    creation();
    creation();
    creation();
    creation();
    creation();

    display();

    //ACTIVITY 02
    access_node();

    //ACTIVITY 03
    insertion_before();
    display();

    insertion_after();
    display();

    //ACTIVITY 04
    deletion_specific();
    display();

    //ACTIVITY 05
    delete_complete();

    //GRADED LAB TASKS
    //LAB TASK 01
    delete_even_values();
    display();

    delete_odd_values();
    display();

    //LAB TASK 02
    josephus_problem();

    //LAB TASK 03
    delete_even_positions();


    return 0;
}
