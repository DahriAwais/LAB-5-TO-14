#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char ch) {
        if (top < 99) {
            arr[++top] = ch;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operand
bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch; // Add operand to output
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else { // Operator
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    // Pop remaining operators in stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
