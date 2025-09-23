#include<iostream>
using namespace std;

char stack[100];
int top = -1;
char post[100],temp;
char infix[100];

int pre(char sy) {
    switch(sy) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

bool isEmpty() {
    return (top == -1);
}

void push(char val) {
    stack[++top] = val;
}

char pop() {
    if(!isEmpty()) {
        char ne = stack[top--];
        return ne;
    }
    return '\0'; // if empty
}

char peek() {
    return stack[top];
}

int main() {
    cout<<"Enter the Expression: ";
    cin>>infix;

    int j = 0;
    for(int i=0; infix[i] != '\0'; i++) {
        char sy = infix[i];

        switch(sy) {
            case '(':
                push(sy);
                break;

            case ')':
                while((temp = pop())!= '(')
                    post[j++] = temp;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                while(!isEmpty() && pre(peek()) >= pre(sy))
                    post[j++] = pop();
                push(sy);
                break;

            default: // operand
                post[j++] = sy;
        }
    }

    while(!isEmpty())
        post[j++] = pop();

    cout << "Postfix Expression: " << post << endl;

    return 0;
}
