// "Given head , the head of a linked list, determine if the linked list has
// a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be
// reached again by continuously following the next pointer . Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false "
// "Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle nod"
#include<iostream>
#include<cmath>
#include<thread>
using namespace std;
template<class T>
//creating Node
class Node
{
    public:
        T data;//Node data
        Node<T>* next;//next Node pointer
        Node(T value):data(value),next(nullptr){}
};
template<class T>
class linkedlist
{
    public:
        Node<T>* head=NULL;
    //function to insert data into linkedlist
    void insert(T value)
    {
        //creating newNode
        Node<T>* newNode=new Node<T>(value);
        if(head==NULL)
        {
            head=newNode;
            newNode->next=head;
        }
        else
        {
            auto current=head;
            //finding the last node
            while((current->next)!=head)
            {
                current=current->next;
            }
            current->next=newNode;
            newNode->next=head;
        }
    }
    //function to display data in the linkedlist
    void display()
    {
        auto current=head;
        cout<<"Data in the linkedlist"<<endl;
        while(current->next!=head) 
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<current->data<<" ";
        cout<<endl;
    }
    void cycle()
    {
        int count=0;
        auto fast=head;
        auto slow=head;
        while(true) 
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<"Cycle Not Exist";
        }
        else
        {
            cout<<"Cycle Exist";
        }
        cout<<endl;
    }
    
};
int main()
{
    linkedlist<int> ls;
    //inserting elements to linkedlist
    ls.insert(3);
    ls.insert(5);
    ls.insert(9);
    ls.insert(2);
    ls.insert(2);
    ls.cycle();
    return 0;
}