// Q1 A
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) { data = v; next = NULL; }
};

Node* insert(Node *head, int val, int ref = -1, bool before = false) {
    Node *n = new Node(val);
    if (!head) { n->next = n; return n; }
    Node *t = head;
    if (ref == -1) {
        while (t->next != head) t = t->next;
        t->next = n; n->next = head;
        return head;
    }
    do {
        if (t->data == ref) {
            if (before) {
                Node *p = head;
                while (p->next != t) p = p->next;
                p->next = n; n->next = t;
                if (t == head) head = n;
            } else {
                n->next = t->next;
                t->next = n;
            }
            return head;
        }
        t = t->next;
    } while (t != head);
    cout << "Not found\n";
    delete n;
    return head;
}

Node* del(Node *head, int key) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == key) {
            if (curr == head && curr->next == head) {
                delete curr; return NULL;
            }
            if (curr == head) {
                while (head->next != curr) head = head->next;
                head->next = curr->next;
                Node *nh = curr->next;
                delete curr;
                return nh;
            }
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Not found\n";
    return head;
}

void search(Node *head, int key) {
    if (!head) { cout << "Empty\n"; return; }
    int i = 1; Node *t = head;
    do {
        if (t->data == key) { cout << "Found at " << i << endl; return; }
        t = t->next; i++;
    } while (t != head);
    cout << "Not found\n";
}

void display(Node *head) {
    if (!head) { cout << "Empty\n"; return; }
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << endl;
}

int main() {
    Node *head = NULL;
    int ch, v, ref;
    do {
        cout << "\n1.IF 2.IL 3.IB 4.IA 5.D 6.S 7.P 8.X\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Val: "; cin >> v; head = insert(head, v, head ? head->data : -1, true); break;
            case 2: cout << "Val: "; cin >> v; head = insert(head, v); break;
            case 3: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, true); break;
            case 4: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, false); break;
            case 5: cout << "Del: "; cin >> v; head = del(head, v); break;
            case 6: cout << "Search: "; cin >> v; search(head, v); break;
            case 7: display(head); break;
        }
    } while (ch != 8);
}
// Q1 B
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int v) { data = v; prev = next = NULL; }
};

Node* insert(Node *head, int val, int ref = -1, bool before = false) {
    Node *n = new Node(val);
    if (!head) return n;
    Node *t = head;
    if (ref == -1) {
        while (t->next) t = t->next;
        t->next = n; n->prev = t;
        return head;
    }
    while (t && t->data != ref) t = t->next;
    if (!t) { cout << "Not found\n"; delete n; return head; }
    if (before) {
        n->prev = t->prev; n->next = t;
        if (t->prev) t->prev->next = n; else head = n;
        t->prev = n;
    } else {
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }
    return head;
}

Node* del(Node *head, int key) {
    if (!head) return NULL;
    Node *t = head;
    while (t && t->data != key) t = t->next;
    if (!t) { cout << "Not found\n"; return head; }
    if (t->prev) t->prev->next = t->next; else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
    return head;
}

void search(Node *head, int key) {
    int i = 1;
    while (head) {
        if (head->data == key) { cout << "Found at " << i << endl; return; }
        head = head->next; i++;
    }
    cout << "Not found\n";
}

void display(Node *head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    int ch, v, ref;
    do {
        cout << "\n1.IF 2.IL 3.IB 4.IA 5.D 6.S 7.P 8.X\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Val: "; cin >> v; head = insert(head, v, head ? head->data : -1, true); break;
            case 2: cout << "Val: "; cin >> v; head = insert(head, v); break;
            case 3: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, true); break;
            case 4: cout << "Val Ref: "; cin >> v >> ref; head = insert(head, v, ref, false); break;
            case 5: cout << "Del: "; cin >> v; head = del(head, v); break;
            case 6: cout << "Search: "; cin >> v; search(head, v); break;
            case 7: display(head); break;
        }
    } while (ch != 8);
}
// Q2
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) { data = v; next = NULL; }
};

Node* insertEnd(Node *head, int val) {
    Node *n = new Node(val);
    if (!head) { n->next = n; return n; }
    Node *t = head;
    while (t->next != head) t = t->next;
    t->next = n; n->next = head;
    return head;
}

void display(Node *head) {
    if (!head) { cout << "Empty"; return; }
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data;
}

int main() {
    Node *head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insertEnd(head, x);
    }
    display(head);
}
// Q3
#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

void insertDoubly(DNode* &head, int val) {
    DNode* n = new DNode(val);
    if (!head) {
        head = n;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertCircular(CNode* &head, int val) {
    CNode* n = new CNode(val);
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
}

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    DNode* dh = NULL;
    CNode* ch = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertDoubly(dh, x);
        insertCircular(ch, x);
    }
    cout << "Size of Doubly Linked List: " << sizeDoubly(dh) << endl;
    cout << "Size of Circular Linked List: " << sizeCircular(ch) << endl;
}
// Q4
#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char c) {
        data = c;
        prev = next = NULL;
    }
};

void insertEnd(Node* &head, char c) {
    Node* n = new Node(c);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* end = head;
    while (end->next)
        end = end->next;
    while (head != end && end->next != head) {
        if (head->data != end->data)
            return false;
        head = head->next;
        end = end->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    string s;
    cout << "Enter characters: ";
    cin >> s;
    for (char c : s)
        insertEnd(head, c);
    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
