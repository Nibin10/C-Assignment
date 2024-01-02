// "Suppose you have n versions [1, 2, ..., n] and you want to find out
// the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which returns whether
// version is bad. Implement a function to find the first bad version"

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//data of versions
map<int,string> mp {{1,"good"},{2,"good"},{3,"good"},{4,"good"},{5,"bad"},{6,"good"}};
int isBadVersion(int version);
int main()
{    
    int version;
    string result;
    cout<<"Enter the version to check :";
    cin>>version;
    int output=isBadVersion(version);
    int length=mp.size();
    if(length<version)
    {
        cout<<"version is out of range"<<endl;
        return 0;
    }
    else
    {
        //
    }
    if(version<output)
    {
        result="Good";
    }
    else
    {
        result="Bad";
    }
    cout<<"Version "<<version<<" is "<<result<<endl;
    return 0;
}
//funtion to return the first bad version
int isBadVersion(int version)
{
    //traversing through all version
    for(auto it:mp)
    {
        //checking the bad version
        if(it.second=="bad")
        {
            //returning the first bad version
            return it.first;
        }
    }
    return version;
}
