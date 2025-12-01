// Q1
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* createNode(int val) {
    Node* n = new Node(val);
    return n;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
// Q2
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert a new node
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// (a) Search Recursive
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchRec(root->left, key);
    } else {
        return searchRec(root->right, key);
    }
}

// (a) Search Iterative
Node* searchItr(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return root;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// (b) Minimum element
Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (c) Maximum element
Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL) {
        return findMin(node->right);
    }
    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL) {
        return findMax(node->left);
    }
    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return pred;
}

// Display inorder
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter value to search: ";
    cin >> key;
    Node* r = searchRec(root, key);
    Node* i = searchItr(root, key);
    cout << "Recursive Search: " << (r ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (i ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    int val;
    cout << "Enter node to find successor and predecessor: ";
    cin >> val;
    Node* node = searchRec(root, val);
    if (node) {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);
        cout << "Inorder Successor: " << (succ ? to_string(succ->data) : "None") << endl;
        cout << "Inorder Predecessor: " << (pred ? to_string(pred->data) : "None") << endl;
    } else {
        cout << "Node not found in BST." << endl;
    }

    return 0;
}
// Q3
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// (a) Insert (No duplicates)
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    } 
    else {
        cout << "Duplicate value " << val << " not allowed." << endl;
    }
    return root;
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (b) Delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } 
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (c) Maximum Depth
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// (d) Minimum Depth
int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Display (Inorder)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Enter element to delete: ";
    int delVal;
    cin >> delVal;
    root = deleteNode(root, delVal);

    cout << "After deletion (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
// Q4
#include <iostream>
#include<limits.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    if (isBST(root))
        cout << "The given tree is a BST.";
    else
        cout << "The given tree is NOT a BST.";
    
    return 0;
}
