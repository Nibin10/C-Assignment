// "Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between 
// any two nodes in a tree. This path may or may not pass through the root"

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
        void diameter()
        {
            length(root);
        }
        // Recursively calculate the length of the tree, updating diameter
        int length(Node<T>* node)
        {
            if(node!=nullptr)
            {
                // Calculate the length of the left and right subtrees
                int l=length(node->left);
                int r=length(node->right);

                // Update the diameter with the maximum of the current diameter 
                //and the sum of left and right lengths
                ans =max(ans,(l+r));
                
                // Return the height of the current subtree
                return 1+max(l,r);
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
    // Btree.display();
    Btree.diameter();
    cout<<"Diameter of Binary tree is "<<Btree.ans<<endl;
    return 0;
}