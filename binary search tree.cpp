#include <iostream> 
using namespace std;
// Node structure 
struct Node {
int data;
Node* left;
Node* right;
};
// Function to create a new node 
Node* createNode(int value) {
Node* newNode = new Node(); 
newNode->data = value;
newNode->left = newNode->right = NULL; 
return newNode;
}
// Function to insert a value into BST 
Node* insert(Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Inorder Traversal (L ? Root ? R)
void inorder(Node* root) { 
if (root != NULL) {
inorder(root->left);
cout << root->data << " "; 
inorder(root->right);
}
}
// Preorder Traversal (Root ? L ? R)
void preorder(Node* root) { 
if (root != NULL) {
cout << root->data << " "; 
preorder(root->left); 
preorder(root->right);
}
}
// Postorder Traversal (L ? R ? Root)
void postorder(Node* root) { 
if (root != NULL) {
postorder(root->left); 
postorder(root->right); 
cout << root->data << " ";
}
}
int main() {
Node* root = NULL; 
int n, value;
cout << "Enter number of nodes: "; 
cin >> n;
cout << "Enter " << n << " values: "; 
for (int i = 0; i < n; i++) {
cin >> value;
root = insert(root, value);
}
cout << "\nInorder Traversal: "; 
inorder(root);
cout << "\nPreorder Traversal: "; 
preorder(root);
cout << "\nPostorder Traversal: "; 
postorder(root);
cout << endl;
return 0;
}
