// C++ code to reverse a stack using recursion

/*IDEA: The idea of the solution is to hold all values in Function Call Stack until the stack 
becomes empty.When the stack becomes empty, insert all held items one by one at the bottom of the stack. 
*/

/* STEPS:
Follow the steps mentioned below to implement the idea:
>> Create a stack and push all the elements in it.
>> Call reverse(), which will pop all the elements from the stack and pass the popped element to function insert_at_bottom()
>> Whenever insert_at_bottom() is called it will insert the passed element at the bottom of the stack.
>> Print the stack     */


#include <bits/stdc++.h>
using namespace std;

// Below is a recursive function that inserts an element at the bottom of a stack.
void insert_at_bottom(stack<int>& st, int x)
{

	if (st.size() == 0) {
		st.push(x);
	}
	else {

       /*All items are held in Function Call Stack until we reach end of the stack	When the stack becomes empty,
        the st.size() becomes 0, the above if part is executed and the item is inserted at the bottom  */ 
		int a = st.top();
		st.pop();
		insert_at_bottom(st, x);

	// push allthe items held in Function Call Stack once the item is inserted at the bottom 
		st.push(a);
	}
}

// Below is the function that reverses the given stack using insert_at_bottom()
void reverse(stack<int>& st)
{
	if (st.size() > 0) {

		// Hold all items in Function Call Stack until we reach end of the stack
		int x = st.top();
		st.pop();
		reverse(st);

        /*Insert all the items held in Function Call Stack one by one from the bottom to top. Every item is
		 inserted at the bottom*/ 
		insert_at_bottom(st, x);
	}
	return;
}

// Driver Code
int main()
{
	stack<int> st, st2;
	// push elements into the stack
	for (int i = 10; i <= 50; i+=10) {
		st.push(i);
	}

	st2 = st;

	cout << "Original Stack" << endl;
	// printing the stack after reversal
	while (!st2.empty()) {
		cout << st2.top() << " ";
		st2.pop();
	}
	cout<<endl;

	// function to reverse the stack
	reverse(st);
	cout << "Reversed Stack" << endl;
	// printing the stack after reversal
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}

/*Time Complexity: O(N2). 
Auxiliary Space: O(N) use of Stack */