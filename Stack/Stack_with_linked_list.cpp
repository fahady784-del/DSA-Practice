#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;


// PUSH
void push(){
    Node* new_node = new Node;

    std::cout << "Enter value: ";
    std::cin >> new_node->data;

    new_node->next = top;
    top = new_node;

    std::cout << "Value Inserted!\n";
}


// POP
void pop() {
    if (top == NULL) {
        std::cout << "Stack Underflow!\n";
    } else {
        Node* temp = top;

        std::cout << "Deleted Value: " << top->data << "\n";

        top = top->next;
        delete temp;
    }
}


// PEEK
void peek() {
    if (top == NULL) {
        std::cout << "Stack is Empty!\n";
    } else {
        std::cout << "Top Value: " << top->data << "\n";
    }
}


// DISPLAY
void display() {
    if (top == NULL) {
        std::cout << "Stack is Empty!\n";
    } else {
        Node* current = top;

        while (current != NULL) {
            std::cout << current->data << endl;
            current = current->next;
        }
    }
}


// MAIN
int main() {
    int choice;

    do {
        std::cout << "\n--- STACK MENU ---\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                std::cout << "Program Terminated!\n";
                break;

            default:
                std::cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}

