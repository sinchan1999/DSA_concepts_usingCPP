/* Reverse a given sentence by its words*/


#include <bits/stdc++.h>
using namespace std;

void reverseSent(string s)
{
    stack<string> st;
    int i;
    for(i=0; i<s.length(); i++)
    {
        string words="";
        while( (s[i] != ' ') && (i<s.length()) )
        {
            words = words + s[i];
            i++;
        }
        st.push(words);
    }
        
        while(!st.empty())
        {
            cout<<st.top()<<" "; //As we ignored the space in prev. loop!
            st.pop();
        }
        
    
    
}

int main()
{
    string sent="How is the weather today? Nice weather but rain is unpredictable here!!!";
    reverseSent(sent);
}

