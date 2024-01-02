// Given a binary tree, determine if it is height-balanced.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node* left;
        Node* right;
        Node(T value): data(value), left(nullptr), right(nullptr){}
};

template <class T>
class BinaryTree{
    public:
        Node<T>* root {nullptr};
        int count=0;
        //function to add elements to Binary tree
        void insert(T value)
        {
            Node<T> *new_node = new Node<T>(value);

            // if root is null, new node is made as root
            if (root == NULL ){
                root = new_node;
            }
            else
            {
                Node<T>* current=root; 
                Node<T>* parent=nullptr;

                // determine left or right node is free
                while(current!=nullptr)
                {
                    parent=current; 
                    if(current->data>=value)
                    {
                       current=current->left;
                    }
                    else
                    {
                        current=current->right;
                    }
                }
                if (parent->data >= value)
                {
                    parent->left = new_node;
                }
                else
                {
                    parent->right = new_node;
                }
            }
        }
        //function to display all elements in tree
        void display()
        {
            traverse(root);
        }
        void traverse(Node<T>* node)
        {
            if(node!=nullptr)
            {
                cout<<node->data<<" ";
                traverse(node->right);
                traverse(node->left);
            }
        }
        //funtion to check height balanced or not
        void check()
        {
            checkbal(root);
            if(checkbal(root)==0)
            {
                cout<<"Tree is Not balanced"<<endl;

            }
            else{
                cout<<"Tree is balanced"<<endl;
            }
        }
        int checkbal(Node<T>* node)
        {
            if(node!=nullptr)
            {
                count=0;
                int rcount=getheight(node->right);
                count=0;
                int lcount=getheight(node->left);
                if(abs(rcount-lcount)>1)
                {
                    return 0;//height is not balanced
                }
                else
                {
                    return checkbal(node->left) && checkbal(node->right);
                }
            }
            return 1;// If the node is nullptr, it is balanced
        }
        //funtion to get height of node
        int getheight(Node<T>* node)
        {
            if(node!=nullptr)
            {
                count++;
                getheight(node->left);
                getheight(node->right);
            }
            return count;
        }

        ~BinaryTree()
        {
            destroy(root);
        }
        //function to release the memory used by the nodes
        void destroy(Node<T>* node)
        {
            if(node!=nullptr)
            {

                destroy(node->left);
                destroy(node->right);
                delete node;
            }
        }
};
int main()
{
    BinaryTree<int> Btree;
    Btree.insert(4);
    Btree.insert(2);
    Btree.insert(1);
    Btree.insert(3);
    Btree.insert(5);
    Btree.insert(6);
    // Btree.insert(70);
    // Btree.display();
    Btree.check();
    return 0;
}