#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* first = NULL;
Node* last = NULL;


//CREATION OF DOUBLE LINKED LIST
void creation(){
    Node* new_node = new Node;

    std::cout<<"Enter the data for the node: ";
    std::cin>>new_node->data;

    if(first == NULL){
        first=last=new_node;
    }else{
        last->next = new_node;
        new_node->prev = last;
        new_node->next = NULL;
        last = new_node;
    }
}

//ACCESSING NODE

//FORWARD DIRECTION
void access_forward(){
    Node* current = new Node;
    current = first;

    int value1;
    std::cout<<"Enter the value of node(Forward Direction): ";
    std::cin>>value1;

    int count = 1;
    while(current!=NULL){
        if(current->data == value1){
            std::cout<<"Value Found! ";
            std::cout<<current->data;
            std::cout<<"\n\n";
            break;
        }
        current = current->next;
        count++;
    }
    std::cout<<"Value Found at "<<count<<" position from forward direction";
    std::cout<<"\n\n";
}


//BACKWARD DIRECTION
void access_backward(){
    Node* current = new Node;
    current = last;

    int value2;
    std::cout<<"Enter the value of node(Backward Direction): ";
    std::cin>>value2;

    int count = 1;
    while(current!=NULL){
        if(current->data == value2){
            std::cout<<"Value Found! ";
            std::cout<<current->data;
            std::cout<<"\n\n";
            break;
        }
        current = current->prev;
        count++;
    }
    std::cout<<"Value Found at "<<count<<" position from backward direction";
    std::cout<<"\n\n";
}

//INSERTION IN A LIST
//AT THE START

void insert_start(){
    Node* new_Node = new Node;

    std::cout<<"Enter the data of the new Node(START): ";
    std::cin>>new_Node->data;

    if(first == NULL){
        std::cout<<"List is empty";
        first = last = new_Node;
    }else{
        new_Node->next = first;
        first->prev = new_Node;
        first = new_Node;
        new_Node->prev = NULL;
    }

}
void insert_end(){
    Node* new_Node = new Node;

    std::cout<<"Enter the data of the new Node(END): ";
    std::cin>>new_Node->data;

    if(first == NULL){
        std::cout<<"List is empty";
        first = last = new_Node;
    }else{
        new_Node->prev = last;
        last->next = new_Node;
        last = new_Node;
        new_Node->next = NULL;
    }

}

void insert_after_specific(){
    Node* new_Node = new Node;

    int search_key;

    std::cout<<"Enter the value specific Node (After): ";
    std::cin>>search_key;

    std::cout<<"Enter the value of new Node (After): ";
    std::cin>>new_Node->data;

    Node* current = first;

    while(current != NULL){

        if(current->data == search_key){

            new_Node->next = current->next;
            new_Node->prev = current;

            if(current->next != NULL){
                current->next->prev = new_Node;
            }
            else{
                last = new_Node;
            }

            current->next = new_Node;

            std::cout<<"Node inserted successfully!\n";
            break;
        }

        current = current->next;
    }
}

void insert_before_specific(){
    Node* new_Node = new Node;

    int search_key;

    std::cout<<"Enter the value specific Node (Before): ";
    std::cin>>search_key;

    std::cout<<"Enter the value of new Node (Before): ";
    std::cin>>new_Node->data;

    Node* current = first;

    while(current != NULL){

        if(current->next->data == search_key){

            new_Node->next = current->next;
            new_Node->prev = current;

            if(current->next != NULL){
                current->next->prev = new_Node;
            }
            else{
                last = new_Node;
            }

            current->next = new_Node;

            std::cout<<"Node inserted successfully!\n";
            break;
        }

        current = current->next;
    }
}

//DELETE FIRST
void delete_first(){

    if(first == NULL){
        std::cout << "List is Empty!";
        return;
    }

    Node* temp = first;
    first = first->next;
    delete temp;

}


 // DELETE LAST
void delete_last(){

    if(first == NULL){
        std::cout << "List is Empty!";
        return;
    }

    Node* temp = last;

    if(first == last){
        first = last = NULL;
    }
    else{
        last = last->prev;
        last->next = NULL;
    }

    delete temp;
}

//DELETE SPECIFIC
void delete_specific(){
    Node* current = first;

    int value;
    std::cout << "Enter the value you want to remove: ";
    std::cin >> value;

    if(first == NULL){
        std::cout << "List is Empty!";
        return;
    }

    while(current != NULL){
        if(current->data == value){

            Node* temp = current;

            if(current == first){
                first = first->next;
            }
            if(current == last){
                last = last->prev;
            }
            if(current->prev != NULL){
                current->prev->next = current->next;
            }
            if(current->next != NULL){
                current->next->prev = current->prev;
            }
            delete temp;
            std::cout << "Node Deleted!";
            break;
        }

        current = current->next;
    }
    std::cout << "Value not found!";
}

//DELETE COMPLETE
void delete_complete(){
}


//DISPLAY LIST
void display(){
    Node* current = new Node;
    current = first;
    while(current!= NULL){
        std::cout<<current->data<<" " ;
        current = current->next;
    }
    std::cout<<"\n\n";

}

int main(){
    int number = 0;

    std::cout<<"How many values you want to enter in a list: ";
    std::cin>>number;

    for(int i =0;i<number;i++){
        creation();
    }


    std::cout<<"\n";

    display();

    access_forward();
    access_backward();

    insert_start();
    display();

    insert_end();
    display();

    insert_after_specific();
    display();

    insert_before_specific();
    display();

    delete_first();
    display();

    delete_last();
    display();

    delete_specific();
    display();

    delete_complete();
    display();


    return 0;
}


//REMAINING
//INSERTION BEFORE A SPECIFIC NODE
//DELETION
//COMPLETE DELETION OF A LIST
