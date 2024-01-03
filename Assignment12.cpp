// "Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the

// longest path from the root node down to the farthest leaf node"
#include <iostream>
#include <bits/stdc++.h>
#include<math.h>

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
        int ans=0;
        void insert(T value){
            Node<T> *new_node = new Node<T>(value);
            // if root is null, node is made as root
            
            if (root == NULL ){
                root = new_node;
            }
            // determine left or right node is free
            else
            {
                Node<T>* current=root; 
                Node<T>* parent=nullptr; 
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
        void display()
        {
            traverse(root);
        }
        //function display binary tree elements
        void traverse(Node<T>* node)
        {
            if(node!=nullptr)
            {
                cout<<node->data<<" ";
                traverse(node->right);
                traverse(node->left);
            }
        }
        int depth()
        {
            return length(root);
        }
        // Recursive function to calculate the depth of the binary tree
        int length(Node<T>* node)
        {
            if(node!=nullptr)
            {
                // Calculate the depth of the left and right subtrees
                int l=length(node->left);
                int r=length(node->right);

                // Return the maximum depth of the current subtree
                return max(l,r)+1;
            }
            else
            {
                return 0;
            }
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
    Btree.insert(10);
    Btree.insert(20);
    Btree.insert(5);
    Btree.insert(40);
    Btree.insert(90);
    Btree.insert(90);
    Btree.insert(4);
    Btree.insert(13);
    // Btree.display();
    Btree.depth();
    cout<<"Max depth Binary tree is "<<Btree.depth()<<endl;
    return 0;
}