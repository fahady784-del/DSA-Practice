
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Inorder
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = new Node;
    root->data = 50;
    root->left = NULL;
    root->right = NULL;

    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    root->left->left = new Node{20, NULL, NULL};
    root->left->right = new Node{40, NULL, NULL};

    root->right->left = new Node{60, NULL, NULL};
    root->right->right = new Node{80, NULL, NULL};

    // Display traversals
    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
