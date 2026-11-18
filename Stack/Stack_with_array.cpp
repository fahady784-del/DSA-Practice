#include <iostream>


//ACTIVITY 01

class Stack
{
private:
    int tos;
    char* values;

public:
    Stack(int x)
    {
        tos = -1;
        values = new char[x];
    }

    void push(char x)
    {
        if (tos == 9)
            std::cout << "\nStack overflow condition";
        else
            values[++tos] = x;
    }

    char pop()
    {
        if (tos == -1)
        {
            std::cout << "\nStack Underflow Condition";
            return ' ';
        }
        else
            return values[tos--];
    }
};

int main()
{
    Stack* myStack = new Stack(10);

    myStack->push('B');
    myStack->push('S');
    myStack->push('S');
    myStack->push('E');
    myStack->push('3');
    myStack->push('Z');

    std::cout << myStack->pop();
    std::cout << myStack->pop();
    std::cout << myStack->pop();
    std::cout << myStack->pop();
    std::cout << myStack->pop();
    std::cout << myStack->pop();
    std::cout << myStack->pop();

    return 0;
}
