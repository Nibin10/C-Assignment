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
        }
        else
        {
            auto current=head;
            //finding the last node
            while((current->next)!=nullptr)
            {
                current=current->next;
            }
            current->next=newNode;
        }
    }
    //function to display data in the linkedlist
    void display()
    {
        auto current=head;
        cout<<"Data in the linkedlist"<<endl;
        while(current)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    //funtion to find the middle element
    void middle()
    {
        int length=0;
        auto current=head;
        while(current)
        {
            length++;
            current=current->next;
        }
        //checking even
        if(length%2==0)
        {
            length=length/2;
        }
        else
        {
            length=ceil(length/2);
        }
        current=head;
        for(int i=0;i<length;i++)
        {
            current=current->next;
        }
        cout<<"Middle element is "<<current->data<<endl;
    }

};
int main()
{
    linkedlist<int> ls;
    //inserting elements to linkedlist
    //ls.insert(2);
    ls.insert(3);
    ls.insert(5);
    ls.insert(9);
    ls.insert(2);
    ls.insert(2);
    ls.display();
    ls.middle();
    return 0;
}