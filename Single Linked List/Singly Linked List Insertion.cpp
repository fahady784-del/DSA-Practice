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

//DISPLAY LIST
void display_list(){
    Node* current = first;

    while (current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";
}

//INSERT AT THE START
void insert_at_start(){
    Node* new_node = new Node;

    std::cout<<"Enter the new Node data(At start): "<<" ";
    std::cin>>new_node->data;

    if(first == NULL){
    first = new_node;
    last = new_node;
    }
    else{
        new_node->next = first;
        first = new_node;
    }
}
void insert_at_end(){
    Node* new_node = new Node;

    std::cout<<"Enter the new Node data(At End): "<<" ";
    std::cin>>new_node->data;
    new_node->next = NULL;


    if(first == NULL){
        first = new_node;
        last = new_node;
    }
    else{
        last->next = new_node;
        last = new_node;
    }
}

//INSERT AFTER SPECIFIC NODE
void insert_after(){
    int search_key;

    std::cout<<"Enter Specific Node(After): "<<" ";
    std::cin>>search_key;

    Node* new_node = new Node;

    std::cout<<"Enter the data of New Node: "<<" ";
    std::cin>>new_node->data;

    Node* current = first;

    while(current != NULL){
        if(current->data == search_key){

            new_node->next = current->next;
            current->next = new_node;

            break;

        }
        current = current->next;
    }
}
//INSERT BEFORE SPECIFIC NODE
void insert_before(){
    Node* current = first;
    Node* new_node = new Node;

    int search_key;

    std::cout<<"Enter the Specific Node(Before): "<<" ";
    std::cin>>search_key;


    std::cout<<"Enter the data of New Node: "<<" ";
    std::cin>>new_node->data;


    while(current != NULL){
         if(current->next != NULL && current->next->data == search_key){
            new_node->next = current->next;
            current->next = new_node;
            break;
        }
        current = current->next;
    }if(current == NULL){
        std::cout<<"Value not found\n";
    }

}


int main(){
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;


    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    first = node1;
    last = node3;

    //Insert at the start
    insert_at_start();
    display_list();

    //Insert at the end
    insert_at_end();
    display_list();

    //Insert after Specific Node
    insert_after();
    display_list();

    //Insert before Specific Node
    insert_before();
    display_list();
/*
    //Display List
    display_list();
*/

    return 0;
}
