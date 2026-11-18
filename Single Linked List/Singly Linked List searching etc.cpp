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

//Search value
void search_value(){
    int search_value;
    Node* current = first;

    std::cout<<"Enter the value of search: "<<" ";
    std::cin>>search_value;

    while (current != NULL){
        if(current->data == search_value){
            std::cout<<"Value Found: "<<current->data;
            break;
        }
        current = current->next;
    }

}

//COUNT NODES
void count_nodes(){
    Node* current = first;
    int count=0;

    while(current!=NULL){
        count++;
        current = current->next;
    }
    std::cout<<"Total elements: "<<count;

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

    //Search By Value
    search_value();
    std::cout<<"\n\n";

    //Count Nodes
    count_nodes();



    return 0;
}

