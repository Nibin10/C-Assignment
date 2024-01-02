// Given a string s which consists of lowercase or uppercase letters,
// return the length of the longest palindrome that can be built with 
// those letters.
// Letters are case sensitive, for example, "Aa" is not considered a
// palindrome here
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s,rev,res;
    int lenres=0;
    cout<<"Enter the string :"<<endl;
    cin>>s;//get input from user
    int len=s.length(); //to find the length of the input string
    //cout<<len;
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            string temp=s.substr(i,j-i+1);
            //cout<<temp<<endl;
            string temp2=temp;
            reverse(temp.begin(),temp.end());
            if(temp==temp2)//check pallindrome
            {
                if(lenres<temp.length())//highest length string checking
                {
                    res=temp;//updating string to highest length
                    lenres=temp.length();//updating length of highest pallindrome
                } 
            }
        }
    }
    cout<<"longest pallindrome length is "<<lenres<<endl;
    return 0;
}