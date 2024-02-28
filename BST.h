
#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node() : key{0}, left{nullptr}, right{nullptr} {}
    Node(int key) : key{key}, left{nullptr}, right{nullptr} {}
    Node(int key, Node* left, Node* right) : key{key}, left{left}, right{right} {}
};

class BST {
public:
    BST() { root = nullptr; }
    BST(int key) {
        Node* root = new Node(key);
        this->root = root;
    }

    void setRoot(Node* newNode) { root = newNode; }

    void insert(const int);
    int search(const int) const;
    void remove(const int);

    int getHeight() const { return heightHelper(getRoot()); }
    int getMinKey() const;
    int getMaxKey() const;

    void preOrderDisplay() const;
    void inOrderDisplay() const;
    void postOrderDisplay() const;
    void levelOrderDisplay() const;

private:
    Node* getRoot() const { return root; }
    bool isEmpty() const { return root == nullptr ? true : false; }

    int heightHelper(Node*) const;
    void preOrderHelper(Node*) const;
    void inOrderHelper(Node*) const;
    void postOrderHelper(Node*) const;
    void levelOrderHelper(Node*) const;

    Node* root;
};


#endif
