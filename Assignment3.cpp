// Given an array of integers nums which is sorted in ascending order, and
// an integer target , write a function to search target in nums . If target
// exists, then return its index. Otherwise, return -1 .
// You must write an algorithm with 0(log n) runtime complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int find_target(vector <int> nums, int target );

int main()
{
    int target {};
    //sorted integer array
    vector <int> numbers {1,2,3,4,5,6,7,8,10,13,21};
    cout << "Enter target : ";
    cin >> target;
    cout << "Target is at : "<<find_target(numbers, target) <<endl;
    return 0;
}
int find_target(vector <int> nums, int target )
{
    //searching the target in array
    auto it=find(nums.begin(), nums.end(), target);
    if (it != nums.end())
    {
        //calculating the index of the target
        return it-nums.begin();
    }
    else
    {
        return -1;
    }
}