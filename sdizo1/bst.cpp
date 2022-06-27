#include <iostream>
#include <math.h>

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
private:
    node *root;
public:
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
    void preorder();

    void preorder(node *p);
};
void bst::insertToTree(int value)
{
    node *insertNode =new node(value), *tempPar=nullptr, *tempX=root;
    while(tempX!=nullptr)
    {
        tempPar=tempX;
        if(value < tempX->key)
        {
            tempX=tempX->left;
        }
        else
        {
            tempX=tempX->right;
        }
    }
    insertNode->parent=tempPar;
    if(tempPar==nullptr)
    {
        root=insertNode;
    }
    else
    {
        if(value < tempPar->key)
        {
            tempPar->left=insertNode;
        }
        else
        {
            tempPar->right=insertNode;
        }
    }
}
node* bst::searchTree(int value)
{
    node *temp=root;
    while (temp)
    {
        if(temp->key==value)
        {
            return temp;
        }
        else if(temp->key > value)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return nullptr;
}
void bst::deleteKey(int value)
{
    node *tempY, *tempX;
    node *deletion=searchTree(value);
    if(deletion == nullptr){
        return;
    }
    if(deletion->left==nullptr || deletion->right==nullptr)
    {
        tempY=deletion;
    }
    else
    {
        tempY=findSuccessor(deletion);
    }
    if(tempY->left!=nullptr)
    {
        tempX=tempY->left;
    }
    else
    {
        tempX=tempY->right;
    }
    if(tempX != nullptr){
        tempX->parent = tempY->parent;
    }
    if(tempY->parent==nullptr)
    {
        root=tempX;
    }
    else
    {
        if(tempY== tempY->parent->left){
            tempY->parent->left=tempX;
        }
        else{
            tempY->parent->right=tempX;
        }
    }
    if(tempY !=deletion )
    {
        deletion->key=tempY->key;
    }
}
node* bst::searchMinKey()
{
    node* temp= root;
    while(temp->left!=nullptr)
    {
        temp=temp->left;
    }
    return temp;
}
node* bst::searchMaxKey()
{
    node* temp= root;
    while(temp->right!=nullptr)
    {
        temp=temp->right;
    }
    return temp;
}
node* bst::findSuccessor(node* element)
{
    if(element->right!=nullptr)
    {
        return searchMinKey();
    }
    node *temp=element->parent;
    while(temp!=nullptr && temp->left != element )
    {
        element=temp;
        temp=temp->parent;
    }
    return temp;
}
node* bst::findPredecessor(node* element)
{
    if(element->left!=nullptr)
    {
        return searchMaxKey();
    }
    node *temp=element->parent;
    while(temp!=nullptr && temp->right != element )
    {
        element=temp;
        temp=temp->parent;
    }
    return temp;
}
void bst::createLinearTree()
{
    node *temp=root;
    while(temp!=nullptr)
    {
        if(temp->left!=nullptr)
        {
            temp=temp->parent;//po rotacji tmp przesunie sie w dol ale ma zostac
        }
        else
        {
            temp=temp->right;
        }
    }
}
void bst::preorder(node *p){
    if(p== nullptr){
        return;
    }
    std::cout<<p->key << std::endl;

    preorder(p->left);

    preorder(p->right);
}
