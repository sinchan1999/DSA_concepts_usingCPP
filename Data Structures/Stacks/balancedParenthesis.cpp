/*
1: Open brackets must be closed by the same type of brackets.
2: Open brackets must be closed in the correct order.
Input: str = “( )[ { } ( ) ]”

Output: True
Explanation: As every open bracket has its corresponding 
close bracket. Match parentheses are in correct order 
hence they are balanced.

Input: str = “[ ( )”

Output: False

Explanation: As ‘[‘ does not have ‘]’ hence it is 
not valid and will return false.


Approach: 

1: Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
2: Whenever we get the closing bracket we will check if the stack is non-empty or not.
3: If the stack is empty we will return false, else if it is nonempty then 
we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.

4: If it is not the opposite pair of the closing bracket then return false, else move ahead.
5: After we move out of the string the stack has to be empty if it is non-empty then 
return it as invalid else it is a valid string.

FOR MORE DETAILS:  https://takeuforward.org/data-structure/check-for-balanced-parentheses/
*/


#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
int main()
{
    string s="()[{}()])";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}

/*Time Complexity: O(N)

Space Complexity: O(N)*/