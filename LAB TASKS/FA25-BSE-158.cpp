#include <iostream>
#include <string>

struct patient{
    int id;
    string name;
    int urgency;
    int time;
};

class patient_queue{
    struct Node{
        patient data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    patient_queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(patient p){
        Node* newNode = new Node;

        newNode->data = p;
        newNode->next = NULL;

        if (front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    patient dequeue(){
        patient p = front->data;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;

        return p;
    }

    patient peek(){
        if (front == NULL)
            return patient();

        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;

        if (front == NULL){
            std::cout << "Empty\n";
            return;
        }

        while (temp != NULL){
            std::cout << temp->data.name << " - " << temp->data.time << " minutes\n";

            temp = temp->next;
        }
    }
};

void simulateTurn(patient_queue &critical, patient_queue &standard, int Q, int &clock){
    patient p;

    if (!critical.isEmpty()){
        p = critical.dequeue();

        if (p.time > Q){
            p.time = p.time - Q;
            clock = clock + Q;
            critical.enqueue(p);
            std::cout << p.name << " Re-queued. Remaining: " << p.time << "\n";
        }
        else{
            clock = clock + p.time;
            std::cout << p.name << " Discharged at minute " << clock << "\n";
        }
    }

    else if (!standard.isEmpty()){
        p = standard.dequeue();

        if (p.time > Q){
            p.time = p.time - Q;
            clock = clock + Q;
            standard.enqueue(p);
            std::cout << p.name << " Re-queued. Remaining: " << p.time << "\n";
        }
        else{
            clock = clock + p.time;
            std::cout << p.name << " Discharged at minute " << clock << "\n";
        }
    }

    else{
        std::cout << "No patients waiting!\n";
    }
}

int main(){
    patient_queue critical;
    patient_queue standard;

    int Q;
    int clock = 0;
    int choice;

    std::cout << "Enter Time Quantum: ";
    std::cin >> Q;

    while (Q <= 0){
        std::cout << "Enter positive Quantum: ";
        std::cin >> Q;
    }

    do{
        std::cout << "\n1. Register patient";
        std::cout << "\n2. Simulate One Turn";
        std::cout << "\n3. Simulate All";
        std::cout << "\n4. Display Waiting Room";
        std::cout << "\n5. Exit";

        std::cout << "\nEnter Choice: ";
        std::cin >> choice;

        if (choice == 1){
            patient p;

            std::cout << "Enter ID: ";
            std::cin >> p.id;

            std::cout << "Enter Name: ";
            std::cin >> p.name;

            std::cout << "Enter Urgency (1 or 2): ";
            std::cin >> p.urgency;

            std::cout << "Enter Treatment Time: ";
            std::cin >> p.time;

            if(p.time <= 0)
                std::cout << "Invalid Treatment Time!\n";

            else if(p.urgency == 1){
                critical.enqueue(p);
                std::cout << "Critical patient Registered!\n";
            }
            else if(p.urgency == 2){
                standard.enqueue(p);
                std::cout << "Standard patient Registered!\n";
            }
            else
                std::cout << "Invalid Urgency!\n";
        }

        else if (choice == 2){
            simulateTurn(critical, standard, Q, clock);
        }

        else if (choice == 3){
            while (!critical.isEmpty() || !standard.isEmpty()){
                simulateTurn(critical, standard, Q, clock);
            }

            std::cout << "\nAll Patients Discharged!\n";
            std::cout << "Total Time: " << clock << "\n";
        }

        else if (choice == 4){
            std::cout << "\nCritical Queue:\n";
            critical.display();

            std::cout << "\nStandard Queue:\n";
            standard.display();
        }

        else if (choice == 5){
            std::cout << "Exiting...\n";
        }

        else{
            std::cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
