// Given two strings s and t , return true if t is an anagram of s , and
// false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly once
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string  s,t;
    cout<<"Enter the first string :"<<endl;
    cin>>s;//get 1st string from user
    cout<<"Enter the second string :"<<endl;
    cin>>t;//get 2nd string from user
    transform(s.begin(),s.end(),s.begin(),::tolower);//converting string1 to lowercase
    transform(t.begin(),t.end(),t.begin(),::tolower);//converting string2 to lowercase
    sort(s.begin(),s.end());//sorting 1st string
    sort(t.begin(),t.end());//sorting 2nd string
    if(s==t)
    {
        cout<<"Is anagram";//printing result Is anagram
    }
    else
    {
        cout<<"Not anagram";//printing result Not anagram
    }
    return 0;
}
