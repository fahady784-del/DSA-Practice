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

//DELETE THE FIRST NODE
void delete_first(){
    if(first == NULL){
    std::cout << "List is empty\n";
    last == NULL;
    }
    else{
        Node* temp = first;
        first = temp->next;
        delete temp;
        }
}

//DELETE THE LAST NODE
void delete_last(){
    if(first == NULL){
        std::cout << "List is empty\n";
    }
    else if(first == last){
        delete first;
        first = NULL;
        last = NULL;
    }
    else{
        Node* current = first;

        while(current->next != last){
            current = current->next;
        }

        Node* temp = last;
        last = current;
        last->next = NULL;

        delete temp;
    }
}

//DELETE A SPECIFIC NODE
void delete_specific_node(){
    int search_key;

    std::cout<<"Enter the node to be deleted: "<<" ";
    std::cin>>search_key;

    Node* current = first;

    while(current->next != NULL){

        if(current->next->data == search_key){

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;

            break;
        }

        current = current->next;
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

    //Delete the first node
    //delete_first();
    //display_list();

    //Delete the last node
    //delete_last();
    //display_list();

    //Delete a specific node
    delete_specific_node();
    display_list();


    return 0;
}
