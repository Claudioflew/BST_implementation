
#include "BST.h"

using namespace std;

/**
 * Creates a new Node with an int variable, and insert it to the appropriate location in BST
 * @param int key
 * @return void
 */
void BST::insert(const int key) {
    if (isEmpty()) { setRoot(new Node(key)); }
    // If BST is not empty
    else {
        Node* curr = getRoot();
        while (curr != nullptr) {
            if (key < curr->key) {
                // If curr doesn't have left child, just insert the newNode there
                if (curr->left == nullptr) {
                    Node* newNode = new Node(key);
                    curr->left = newNode;
                    break;
                    // If curr has left child, sink deeper
                } else curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    Node* newNode = new Node(key);
                    curr->right = newNode;
                    break;
                } else curr = curr->right;
            }
        }
    }
}

/**
 * Searches a Node in BST whose key matches with an int value
 * @param int key
 * @return int: found value
 */
int BST::search(const int key) const {
    Node* curr = getRoot();
    while (curr != nullptr) {
        if (key == curr->key) {
            return key;
        }
        // Sink until finding the key
        if (key < curr->key) {
            curr = curr->left;
        } else curr = curr->right;
    }
    cout << "Couldn't find the key " << key << ".." << endl;
    return -1;
}

/**
 * Removes a Node in BST whose key matches with an int value
 * @param int key
 * @return void
 */
void BST::remove(const int key) {
    Node* prev = nullptr;
    Node* curr = getRoot();
    while (curr != nullptr) {
        // If found the key
        if (key == curr->key) {
            // If curr node has no children
            if (curr->left == nullptr && curr->right == nullptr) {
                // This means curr node is the root
                if (prev == nullptr) setRoot(nullptr);
                // In these case below, we want to skip the curr node
                else if (prev->left == curr) prev->left = nullptr;
                else prev->right = nullptr;
                // This guarantees that curr->right != nullptr
            } else if (curr->left == nullptr) {
                if (prev == nullptr) setRoot(curr->right);
                // In these case below, we want to skip the curr node
                else if (prev->left == curr) prev->left = curr->right;
                else prev->right = curr->right;
                // This guarantees that curr->left != nullptr
            } else if (curr->right == nullptr) {
                if (prev == nullptr) setRoot(curr->left);
                else if (prev->left == curr) prev->left = curr->left;
                else prev->right = curr->left;
                // If the curr node has both children
            } else {
                Node* succ = curr->right;
                // Successor is the next largest key - go right first and go as left as possible
                while (succ->left != nullptr) succ = succ->left;
                int succKey = succ->key;
                // Recursively call remove()
                // This guarantees succ is one of the three cases above - no child, just one child
                remove(succKey);
                // Replace the key with the curr node
                curr->key = succKey;
            }
            return;
            // Sink until finding the key
        } else if (key < curr->key) {
            prev = curr;
            curr = curr->left;
        } else {
            prev = curr;
            curr = curr->right;
        }
    }
    cout << "Couldn't removed the key " << key << " because it doesn't exist.." << endl;
    return;
}

/**
 * Returns the minimum value of the key in BST
 * @param
 * @return int: minimum key
 */
int BST::getMinKey() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return -1;
    } else {
        Node* curr = getRoot();
        // We want to go to as left as possible to find the min
        while (curr->left != nullptr) curr = curr->left;
        return curr->key;
    }
}

/**
 * Returns the maximum value of the key in BST
 * @param
 * @return int: maximum key
 */
int BST::getMaxKey() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return -1;
    } else {
        Node* curr = getRoot();
        // We want to go to as right as possible to find the min
        while (curr->right != nullptr) curr = curr->right;
        return curr->key;
    }
}

/**
 * Calls helper function: preOrderHelper() to display nodes in BST in preorder
 * @param
 * @return
 */
void BST::preOrderDisplay() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return;
    }
    cout << "Traversed BST by preorder: ";
    preOrderHelper(getRoot());
    cout << endl;
}

/**
 * Calls helper function: inOrderHelper() to display nodes in BST in inorder
 * @param
 * @return
 */
void BST::inOrderDisplay() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return;
    }
    cout << "Traversed BST by inorder: ";
    inOrderHelper(getRoot());
    cout << endl;
}

/**
 * Calls helper function: postOrderHelper() to display nodes in BST in postorder
 * @param
 * @return
 */
void BST::postOrderDisplay() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return;
    }
    cout << "Traversed BST by postorder: ";
    postOrderHelper(getRoot());
    cout << endl;
}

/**
 * Calls helper function: levelOrderHelper() to display nodes in BST in level order
 * @param
 * @return
 */
void BST::levelOrderDisplay() const {
    if (isEmpty()) {
        cout << "BST is empty.." << endl;
        return;
    }
    cout << "Traversed BST by level order: ";
    levelOrderHelper(getRoot());
    cout << endl;
}

/**
 * Returns the height of BST
 * @param Node* curr
 * @return int: height value
 */
int BST::heightHelper(Node* curr) const {
    if (curr == nullptr) return -1;

    int left = 1 + heightHelper(curr->left);
    int right = 1 + heightHelper(curr->right);

    return max(left, right);
}

/**
 * Displays nodes in BST in preorder
 * @param Node* curr: starting node
 * @return
 */
void BST::preOrderHelper(Node* curr) const {
    if (curr == nullptr) return;

    cout << curr->key << " ";
    preOrderHelper(curr->left);
    preOrderHelper(curr->right);
}

/**
 * Displays nodes in BST in inorder
 * @param Node* curr: starting node
 * @return
 */
void BST::inOrderHelper(Node* curr) const {
    if (curr == nullptr) return;

    inOrderHelper(curr->left);
    cout << curr->key << " ";
    inOrderHelper(curr->right);
}

/**
 * Displays nodes in BST in postorder
 * @param Node* curr: starting node
 * @return
 */
void BST::postOrderHelper(Node* curr) const {
    if (curr == nullptr) return;

    postOrderHelper(curr->left);
    postOrderHelper(curr->right);
    cout << curr->key << " ";
}

/**
 * Displays nodes in BST in levelorder
 * @param Node* curr: starting node
 * @return
 */
void BST::levelOrderHelper(Node* curr) const {
    queue<Node*> levelQueue;
    levelQueue.push(curr);

    // This is actually BFS algorithm
    while (!levelQueue.empty()) {
        Node* curr = levelQueue.front();
        levelQueue.pop();
        cout << curr->key << " ";

        if (curr->left != nullptr) levelQueue.push(curr->left);
        if (curr->right != nullptr) levelQueue.push(curr->right);
    }
}