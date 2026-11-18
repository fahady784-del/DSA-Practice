#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;


// ACTIVITY 01
void insert_at_end(){

    Node* new_node = new Node;

    std::cout << "Enter data: ";
    std::cin >> new_node->data;

    new_node->next = NULL;

    if (first == NULL)
    {
        first = last = new_node;
    }
    else
    {
        last->next = new_node;
        last = new_node;
    }
}

//ACTIVITY 02

void insert_at_start(){
    Node* new_node = new Node;

    std::cout << "Enter data: ";
    std::cin >> new_node->data;

    new_node->next = first;

    if (first == NULL)
    {
        first = last = new_node;
    }
    else
    {
        first = new_node;
    }

}

//ACTIVITY 03
void search_node(){
    int search_key;
    std::cout<<"Enter a node to search: "<<" ";
    std::cin>>search_key;

    Node* current = first;

    while(current != NULL){
        if(current->data == search_key){
            std::cout<<"Value Found!"<<"\n";
            std::cout<<search_key;
            break;
        }
        current = current->next;
        if(current == NULL){
            std::cout << "Value not found!\n";
        }
    }
}

//ACTIVITY 04
void insert_after_node(){

    int specific_node;

    std::cout<<"Enter a Specific Node: "<<" ";
    std::cin>>specific_node;

    Node* current = first;

    while(current != NULL)
    {
        if(current->data == specific_node)
        {
            Node* new_node = new Node;

            std::cout << "Enter data: ";
            std::cin >> new_node->data;

            new_node->next = current->next;
            current->next = new_node;

            if(current == last)
            {
                last = new_node;
            }

            std::cout << "New node linked successfully!\n";
            break;
        }

        current = current->next;

        if(current == NULL)
        {
            std::cout << "Value not found!\n";
        }
    }
}

//ACTIVITY 05
void delete_node(){

    if(first == NULL){
        std::cout<<"Linked list not exist!";
    }
    else{
        Node* current = first;
        first = first->next;
        delete current;
    }
}

//ACTIVITY 06
void delete_last_node(){
    Node* current = first;
     if(first == NULL){
        std::cout << "List is empty!\n";
    }
    else{
        while(current->next->next != NULL){
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
        last = current;
    }
}

//ACTIVITY 07
void delete_specific_node(){
    int specific_node;

    std::cout << "Enter the node to delete: ";
    std::cin >> specific_node;

    if(first == NULL)
    {
        std::cout << "List is empty!\n";
    }
    else{
        Node* current = first;
        while(current->next != NULL){
            if(current->next->data == specific_node){
                Node* temp = current->next;
                current->next = current->next->next;
                if(temp == last)
                {
                    last = current;
                }
                delete temp;
                std::cout << "Node deleted successfully!\n";
                break;
            }
            current = current->next;
        }

    }
}
//ACTIVITY 08
void delete_list(){

    while (first != NULL){
            Node* temp = first;
            first = first->next;
            delete temp;
    }
    Node* current = first;
    if(current == NULL){
        std::cout<<"List Deleted!";
    }else{
        std::cout<<"List not Deleted";
    }
}
//GRADED LAB TASKS

//LAB task 01

// Using Loops
void display_in_reverse(){
    int count = 0;
    Node* current = first;
    while(current != NULL){
        count++;
        current = current->next;
    }

    for(int i = count; i >= 1; i--){
        current = first;
        for(int j = 1; j < i; j++){
            current = current->next;
        }
        std::cout << current->data << " ";
    }
}

//Recursively

void display_recursive(Node* current){
    if(current == NULL){
        return;
    }
    display_recursive(current->next);

    std::cout << current->data << " ";
}

// LAB TASK 02

void merge_lists(Node* first1, Node* first2){

    Node* third_first = NULL;
    Node* third_last = NULL;

    Node* current = first1;

    while(current != NULL){

        Node* new_node = new Node;

        new_node->data = current->data;
        new_node->next = NULL;

        if(third_first == NULL){
            third_first = third_last = new_node;
        }
        else{
            third_last->next = new_node;
            third_last = new_node;
        }

        current = current->next;
    }

    current = first2;

    while(current != NULL){

        Node* new_node = new Node;

        new_node->data = current->data;
        new_node->next = NULL;

        if(third_first == NULL){
            third_first = third_last = new_node;
        }
        else{
            third_last->next = new_node;
            third_last = new_node;
        }

        current = current->next;
    }

    std::cout << "Merged List: ";

    current = third_first;

    while(current != NULL){
        std::cout << current->data << " ";
        current = current->next;
    }
}

//LAB TASK 03

void find_multiple_occurrences(){

    int search_key;
    int count = 0;

    std::cout << "Enter data to search: ";
    std::cin >> search_key;

    Node* current = first;

    while(current != NULL){

        if(current->data == search_key){

            std::cout << "Value Found: " << current->data << "\n";

            count++;
        }

        current = current->next;
    }

    if(count == 0){
        std::cout << "Value not found!\n";
    }
    else{
        std::cout << "Total occurrences: " << count << "\n";
    }
}


int main(){

    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;

    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = NULL;

    first = node1;
    last = node3;

    Node* current = node1;

    //ACTIVITY 01
    std::cout<<"Insert at the end"<<"\n";
    insert_at_end();
    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 02
    std::cout<<"Insert at the start"<<"\n";
    insert_at_start();
    current = first;

    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 03
    std::cout<<"Accessing a specific node"<<"\n";
    search_node();

    std::cout<<"\n\n";

    //ACTIVITY 04
    std::cout<<"Insert after the Specific Node"<<"\n";
    insert_after_node();
    current = first;

    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 05
    std::cout<<"Delete first node"<<"\n";
    delete_node();
    current = first;

    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 06
    std::cout<<"Delete last node"<<"\n";
    delete_last_node();
    current = first;

    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 07
    std::cout<<"Delete a specific node"<<"\n";
    delete_specific_node();
    current = first;

    while(current != NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<"\n\n";

    //ACTIVITY 08
    std::cout<<"Delete Whole List"<<"\n";
    delete_list();

    std::cout<<"\n\n";


    //GRADED LAB TASKS
    //LAB TASK 01

    //Using loops
    std::cout<<"Reverse List By using Loops"<<"\n";
    display_in_reverse();

    std::cout<<"\n";

    //Recursively
    std::cout<<"Reverse List using recursive method"<<"\n";
    display_recursive(first);

    std::cout<<"\n\n";

    //LAB TASK 02

    Node* first2 = new Node;
    Node* second2 = new Node;

    first2->data = 40;
    first2->next = second2;

    second2->data = 50;
    second2->next = NULL;

    std::cout<<"Merge List"<<"\n";
    merge_lists(first, first2);

    std::cout<<"\n\n";

    //LAB TASK 03
    std::cout << "Find Multiple Occurrences" << "\n";
    find_multiple_occurrences();
    std::cout << "\n\n";


    return 0;
}
