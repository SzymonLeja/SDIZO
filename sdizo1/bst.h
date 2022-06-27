#pragma once
class node
{
public:
    int key;
    node *left;
    node *right;
    node *parent;
    node(int value){
        key=value;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
};
class bst
{
public:
    node *root;
    bst()
    {
        root=nullptr;
    }
    void insertToTree(int value);
    node* searchTree(int value);
    void deleteKey(int value);
    node* searchMinKey();
    node* searchMaxKey();
    node* findSuccessor(node* element);
    node* findPredecessor(node* element);
    void createLinearTree();
    void preorder(node *p);

};