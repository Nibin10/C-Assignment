// Given two binary strings a and b return their sum as a binary string

#include <iostream>
#include <bits/stdc++.h>
#include <bitset>//for bit representation

using namespace std;
string binary_add(string first, string second);
int main(){
    string first_string {}, second_string {}, result {};
    cout << "Enter first binary string : " ;
    cin >> first_string;
    cout << "Enter second binary string : " ;
    cin >> second_string;
    result = binary_add(first_string, second_string);
    cout << "Result : " << result << endl;
    return 0;
}
string binary_add(string first, string second)
{
    int num1 {}, num2 {};
    //converting first string to bit representation
    bitset<64> b_first(first);
    //converting second string to bit representation
    bitset<64> b_second(second);

    //converting Bit representation to unsigned long
    num1 = b_first.to_ulong();
    //converting Bit representation to unsigned long
    num2 = b_second.to_ulong();
    
    //Finding the sum
    int sum = num1 + num2;
    //coverting int sum -> bit rep ->string
    string result = bitset<64>(sum).to_string();

    //deleting zeros
    int res=stoi(result);
    result=to_string(res);
    return result;
}