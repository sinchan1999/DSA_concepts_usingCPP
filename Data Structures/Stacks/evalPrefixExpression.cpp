/*Approach:

>> Initialise a pointer ptr at the end of the expression.

>> If the character at the pointer ptr is an operand push it into the stack

>> If the character at pointer ptr is an operator then pop the top two elements from the stack.
Perform the calculations on these elements according to the operator, and push the result back into the stack

>>Decrement pointer ptr by 1 and repeat step 2 & step 3 until the entire expression is not scanned

>>The Result is stored at the top of the Stack Print / Return it

Expression: * 4 5       Expression: + 5 * 4 6
Output: 20              Output: 29

>> For more details ---->https://takeuforward.org/data-structure/evaluation-of-prefix-expression/    
 */



#include <bits/stdc++.h>

using namespace std;

bool chk(char c) {
  // If the character is a digit then it must be an operand
  return isdigit(c);
}

double prefix(string s) {
  stack < double > Stack;

  for (int j = s.size() - 1; j >= 0; j--) {

    // Push operand to Stack To convert exprsn[j] to digit subtract '0' from exprsn[j].
    if (chk(s[j]))
      Stack.push(s[j] - '0');

    else {

      // Operator encountered. Pop two elements from Stack
      double o1 = Stack.top();
      Stack.pop();
      double o2 = Stack.top();
      Stack.pop();

      // Use switch case to operate on o1 and o2 and perform o1 O o2.
      switch (s[j]) {
      case '+':
        Stack.push(o1 + o2);
        break;
      case '-':
        Stack.push(o1 - o2);
        break;
      case '*':
        Stack.push(o1 * o2);
        break;
      case '/':
        Stack.push(o1 / o2);
        break;
      }
    }
  }

  return Stack.top();
}

int main() {
  string s = "+5*46"; // Expression string
  cout << prefix(s) << endl;
  return 0;
}


/*Time Complexity: O(N)

Space Complexity: O(N)*/