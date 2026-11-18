#include <iostream>

int tree[100];
int size = 0;

// Creation
void create()
{
    int n, value;

    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    size = 0;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter value: ";
        std::cin >> value;

        tree[size] = value;
        size++;
    }
}

// Insertion
void insert()
{
    int value;

    if(size == 100)
    {
        std::cout << "Tree is Full!" << endl;
        return;
    }

    std::cout << "Enter value: ";
    std::cin >> value;

    tree[size] = value;
    size++;

    std::cout << "Value Inserted!" << endl;
}

// Deletion
void deleteNode()
{
    int value, i;

    std::cout << "Enter value to delete: ";
    std::cin >> value;

    for(i = 0; i < size; i++)
    {
        if(tree[i] == value)
        {
            break;
        }
    }

    if(i == size)
    {
        std::cout << "Value Not Found!" << endl;
        return;
    }

    tree[i] = tree[size - 1];
    size--;

    std::cout << "Value Deleted!" << endl;
}

// Searching
void search()
{
    int value;

    std::cout << "Enter value to search: ";
    std::cin >> value;

    for(int i = 0; i < size; i++)
    {
        if(tree[i] == value)
        {
            std::cout << "Value Found at index: " << i << endl;
            return;
        }
    }

    std::cout << "Value Not Found!" << endl;
}

// Display
void display()
{
    if(size == 0)
    {
        std::cout << "Tree is Empty!" << endl;
        return;
    }

    std::cout << "Tree Elements: ";

    for(int i = 0; i < size; i++)
    {
        std::cout << tree[i] << " ";
    }

    std::cout << endl;
}

// Inorder Traversal
void inorder(int i)
{
    if(i < size)
    {
        inorder(2 * i + 1);
        std::cout << tree[i] << " ";
        inorder(2 * i + 2);
    }
}

// Preorder Traversal
void preorder(int i)
{
    if(i < size)
    {
        std::cout << tree[i] << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }
}

// Postorder Traversal
void postorder(int i)
{
    if(i < size)
    {
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        std::cout << tree[i] << " ";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        std::cout << "\n--- BINARY TREE MENU ---" << endl;
        std::cout << "1. Create Tree" << endl;
        std::cout << "2. Insert Node" << endl;
        std::cout << "3. Delete Node" << endl;
        std::cout << "4. Search Node" << endl;
        std::cout << "5. Display Tree" << endl;
        std::cout << "6. Inorder Traversal" << endl;
        std::cout << "7. Preorder Traversal" << endl;
        std::cout << "8. Postorder Traversal" << endl;
        std::cout << "9. Exit" << endl;

        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insert();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                search();
                break;

            case 5:
                display();
                break;

            case 6:
                inorder(0);
                std::cout << endl;
                break;

            case 7:
                preorder(0);
                std::cout << endl;
                break;

            case 8:
                postorder(0);
                std::cout << endl;
                break;

            case 9:
                std::cout << "Program Ended!" << endl;
                break;

            default:
                std::cout << "Invalid Choice!" << endl;
        }

    } while(choice != 9);

    return 0;
}
