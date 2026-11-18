#include <iostream>
#include <string>
#include <cctype>

//ACTIVITY 1
class Stack
{
private:
    int tos;
    int size;
    char* values;

public:
    Stack(int x){
        tos = -1;
        size = x;
        values = new char[size];
    }

    void push(char x){

        if (tos == size - 1)
            std::cout << "\nStack overflow condition";
        else
            values[++tos] = x;
    }

    char pop(){
        if (tos == -1){
            std::cout << "\nStack Underflow Condition\n";
            return ' ';
        }
        else
            return values[tos--];
    }
};

//ACTIVITY 2
struct Node{
    char data;
    Node* link;
};

class LinkedStack{

private:
    Node* head;

public:
    LinkedStack(){
        head = NULL;
    }

    void push(char e){
        Node* temp = new Node;
        temp->data = e;
        temp->link = head;
        head = temp;
    }

    char pop(){
        if (head == NULL){
            std::cout << "\nStack is Empty .... Underflow Condition\n";
            return ' ';
        }else{
            Node* temp = head;
            char value = temp->data;
            head = temp->link;
            delete temp;
            return value;
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    char top(){
        if (head == NULL)
            return ' ';
        return head->data;
    }
};

//GRADED LAB TASK 1
bool isBalanced(string expr){
    LinkedStack s;

    for (int i = 0; i < expr.length(); i++){
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}'){
            if (s.isEmpty())
                return false;

            char temp = s.pop();

            if ((ch == ')' && temp != '(') || (ch == ']' && temp != '[') || (ch == '}' && temp != '{'))
                return false;
        }
    }

    return s.isEmpty();
}

//GRADED LAB TASK 2
int precedence(char op){
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string expr){
    LinkedStack s;
    string postfix = "";

    for (int i = 0; i < expr.length(); i++){
        char ch = expr[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')'){
            while (!s.isEmpty() && s.top() != '(')
                postfix += s.pop();

            if (!s.isEmpty())
                s.pop();
        }else{
            while (!s.isEmpty() && s.top() != '(' && (precedence(s.top()) > precedence(ch) || (precedence(s.top()) == precedence(ch) && ch != '^'))){
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty()){
        char ch = s.pop();

        if (ch != '(')
            postfix += ch;
    }

    return postfix;
}

//GRADED LAB TASK 3
struct IntNode{
    int data;
    IntNode* link;
};

class IntStack{
private:
    IntNode* head;

public:
    IntStack(){
        head = NULL;
    }

    void push(int value){
        IntNode* temp = new IntNode;
        temp->data = value;
        temp->link = head;
        head = temp;
    }

    int pop(){
        if (head == NULL){
            std::cout << "\nStack Underflow Condition\n";
            return 0;
        }

        IntNode* temp = head;
        int value = temp->data;
        head = temp->link;
        delete temp;
        return value;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int evaluatePostfix(string expr)
{
    IntStack s;

    for (int i = 0; i < expr.length(); i++){
        char ch = expr[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch))
            s.push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int b = s.pop();
            int a = s.pop();

            if (ch == '+')
                s.push(a + b);
            else if (ch == '-')
                s.push(a - b);
            else if (ch == '*')
                s.push(a * b);
            else if (ch == '/'){
                if (b == 0){
                    std::cout << "Division by zero error";
                    return 0;
                }
                s.push(a / b);
            }
        }
    }

    return s.pop();
}

int main(){

    //ACTIVITY 1

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

    std::cout<<"\n\n";


    //ACTIVITY 2

    LinkedStack myStack2;
    myStack2.push('H');
    myStack2.push('e');
    myStack2.push('l');
    myStack2.push('l');
    myStack2.push('o');


    std::cout << myStack2.pop();
    std::cout << myStack2.pop();
    std::cout << myStack2.pop();
    std::cout << myStack2.pop();
    std::cout << myStack2.pop();

    std::cout<<"\n\n";


    //ACTIVITY 3

    Stack s1(50);
    char str[] = "I Love Programming";
    int len = sizeof(str) - 1;

    for (int i = 0; i < len; i++)
        s1.push(str[i]);

    for (int i = 0; i < len; i++)
        std::cout << s1.pop();

    std::cout << "\n\n";

    //ACTIVITY 4

    string expr = "[{}(){()}]";
    if (isBalanced(expr))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";

    std::cout<<"\n\n";

    //GRADED LAB TASKS
    //GRADED LAB TASK 1

    string brackets;
    std::cout << "Enter a string of brackets: ";
    std::cin >> brackets;

    if (isBalanced(brackets))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";

    std::cout<<"\n\n";


    //GRADED LAB TASK 2

    string infix;
    std::cout << "Enter infix expression: ";
    std::cin.ignore();
    getline(std::cin, infix);

    std::cout << "Postfix expression: " << infixToPostfix(infix);

    std::cout<<"\n\n";

    //GRADED LAB TASK 3

    string postfix;
    std::cout << "Enter postfix expression (single-digit numbers): ";
    getline(std::cin, postfix);

    std::cout << "Result: " << evaluatePostfix(postfix);

    return 0;
}
