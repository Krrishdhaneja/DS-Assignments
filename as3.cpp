// Question 1
#include <iostream>
using namespace std;

#define MAX 100
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
        case 2: s.pop(); break;
        case 3: s.peek(); break;
        case 4: s.display(); break;
        }
    } while (choice != 5);
}
// Q2
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str; 
    cout << "Enter string: ";
    cin >> str;

    stack<char> s;
    for (char c : str) s.push(c);

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    cout << "Reversed: " << rev << endl;
}

// Q3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    char stack[100];
    int top = -1;
    bool ok = true;

    for (int i = 0; i < exp.size(); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
            stack[++top] = ch;
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { ok = false; break; }
            char open = stack[top--];
            if ((open == '(' && ch != ')') ||
                (open == '{' && ch != '}') ||
                (open == '[' && ch != ']')) {
                ok = false;
                break;
            }
        }
    }
    if (top != -1) ok = false;

    if (ok) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
// Q5
#include <iostream>
#include <string>
using namespace std;

int main() {
    string post;
    cout << "Enter postfix (single-digit): ";
    cin >> post;

    int stack[100];
    int top = -1;

    for (int i = 0; i < post.size(); i++) {
        char ch = post[i];
        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int res;
            if (ch == '+') res = a + b;
            else if (ch == '-') res = a - b;
            else if (ch == '*') res = a * b;
            else if (ch == '/') res = a / b;
            stack[++top] = res;
        }
    }
    cout << "Result: " << stack[top] << endl;
    return 0;
}
