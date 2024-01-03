// "Given a binary search tree (BST), find the lowest common ancestor (LCA) 

// node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common 
// ancestor is defined between two nodes p and q as the lowest node in T
// that has both p and q as descendants (where we allow a node to be a
// descendant of itself).”"


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
        void traverse(Node<T>* node)
        {
            if(node!=nullptr)
            {
                cout<<node->data<<" ";
                traverse(node->right);
                traverse(node->left);
            }
        }
        T checklca()
        {
            T a,b;
            cout<<"Enter the Two nodes ";
            cin>>a>>b;
            return lca(root,a,b);
        }
        // Recursive function to find the LCA of two nodes in the BST
        T lca(Node<T>* root,int n1,int n2)
        {
            if(root==NULL)
            {
                return 0;
            }
            if(root->data>n1 && root->data >n2)
            {
                return lca(root->left,n1,n2);
            }
            if(root->data<n1 && root->data <n2)
            {
                return lca(root->right,n1,n2);
            }
            return root->data;
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
    Btree.insert(30);
    Btree.insert(7);
    // Btree.display();
    int result=Btree.checklca();
    cout<<"lowest common ancestor is :"<<result<<endl;
    return 0;
}