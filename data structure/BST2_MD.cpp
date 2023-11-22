#include <iostream>
using namespace std;
// #define 

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return createNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    bool search(Node* node, int target) {
        if (node == nullptr)
            return false;

        if (node->data == target)
            return true;

        if (target < node->data)
            return search(node->left, target);

        return search(node->right, target);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* remove(Node* node, int elem) {
        if (node == nullptr)
            return node;

        if (elem < node->data)
            node->left = remove(node->left, elem);
        else if (elem > node->data)
            node->right = remove(node->right, elem);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }
};

int main() {
    BST bst;
    int choice, key, elem;
    bool found;

    do {
        cout << "Menu:\n";
        cout << "1. Insert into BST\n";
        cout << "2. Traverse BST (Inorder, Preorder, Postorder)\n";
        cout << "3. Search BST\n";
        cout << "4. Delete from BST\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int n;
                cout << "Enter the number of elements to insert: ";
                cin >> n;
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) {
                    int value;
                    cin >> value;
                    bst.root = bst.insert(bst.root, value);
                }
                break;

            case 2:
                cout << "Inorder Traversal: ";
                bst.inorder(bst.root);
                cout << endl;

                cout << "Preorder Traversal: ";
                bst.preorder(bst.root);
                cout << endl;

                cout << "Postorder Traversal: ";
                bst.postorder(bst.root);
                cout << endl;
                break;

            case 3:
                cout << "Enter the element to search: ";
                cin >> key;
                found = bst.search(bst.root, key);
                if (found)
                    cout << key << " found in BST." << endl;
                else
                    cout << key << " not found in BST." << endl;
                break;

            case 4:
                cout << "Enter the element to delete: ";
                cin >> elem;
                bst.root = bst.remove(bst.root, elem);
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}