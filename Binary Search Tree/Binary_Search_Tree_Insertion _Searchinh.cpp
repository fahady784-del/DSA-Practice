
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Insertion Function
Node* insert(Node* root, int value) {

    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Searching Function
void search(Node* root, int value) {

    if (root == NULL) {
        cout << "Value Not Found!";
        return;
    }

    if (root->data == value) {
        cout << "Value Found!";
    }
    else if (value < root->data) {
        search(root->left, value);
    }
    else {
        search(root->right, value);
    }
}

int main() {

    Node* root = NULL;

    // Inserting values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Searching a value
    int value;

    cout << "Enter value to search: ";
    cin >> value;

    search(root, value);

    return 0;
}
