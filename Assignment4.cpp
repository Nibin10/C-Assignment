// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways
// can you climb to the top?

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count_steps(int n);

int main(){
    int input,steps;
    cout << "Enter number of steps : ";
    cin >> input ;
    steps = count_steps(input);
    cout << "Number of ways : " << steps << endl;
    return 0;
}
int count_steps(int n)
{
    vector<int> ways={1,2};
    int sum;
    if (n<=2)
    {
        return n;
    }
    while (ways.size() <= n)
    {
        //finding next element in the fibonacci series 
        sum=accumulate(ways.end()-2, ways.end(),0);
        //adding next element to fibonacci series
        ways.emplace_back(sum);
        
    }
    return ways.at(n-1);
}