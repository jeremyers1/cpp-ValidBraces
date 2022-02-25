/* After trying for 2 hours and failing ... I finally gave up and searched Google and found the following code that works. My attempt is at the bottom. Mine works for everything except ({})[({})] and )(}{][  

  Challenge is found here: https://www.codewars.com/kata/5277c8a221e209d3f6000b56 
  
Source: https://www.tutorialspoint.com/valid-parentheses-in-cplusplus 

I added all the comments to help me learn what is going on. Yes, I am BRAND NEW to C++
*/

#include <iostream>
#include <stack>
using namespace std;
bool isBalancedExp(string exp) {
   stack<char> stk; // create a stack, which is LIFO - last in, first out 
   char x;
   for (int i=0; i<exp.length(); i++) {  // will iterate through whole string
      if (exp[i]=='('||exp[i]=='['||exp[i]=='{') { // checks to see if character is an opening brace
         stk.push(exp[i]); // if opening brace exists, put it on top of stack, closing braces never get put on stack
         continue;
      }
      if (stk.empty()) // if the stack is empty, end
         return false;
      switch (exp[i]) { // switch checks closing braces to see if it matches opening brace on top of stack
      case ')':
         x = stk.top(); // assign top opening brace in stack to x
         stk.pop(); // then remove top element from stack
         if (x=='{' || x=='[') // if closing brace in exp[i] does not match opening brace in x, return false
            return false;
         break;
      case '}':
         x = stk.top();
         stk.pop();
         if (x=='(' || x=='[')  
            return false;
         break;
      case ']':
         x = stk.top();
         stk.pop();
         if (x =='(' || x == '{') 
            return false;
         break;
      } // end switch
   } // If no closing brace is found, returns to for loop and gets next opening brace to put on top of stack
   return (stk.empty()); // when for loop ends, empty the stack
}
int main() {
   string expresion = "()[(){()}]";
   if (isBalancedExp(expresion))
      cout << "This is Balanced Expression";
   else
      cout << "This is Not Balanced Expression";
}


/* 

#include <iostream>
#include <string>

using namespace std;

bool valid_braces(std::string braces) {
  int length = braces.size();
  bool pairs = true;
 // cout << "length of braces is " << braces.size() << endl;
 // cout << "Bool pairs begins at " << pairs << endl;

  // first check for odd number of braces for easy false
  if (length % 2 == 1) {
    pairs = false;
  }
  else {
    // Convert brace pairs to letters for comparison purposes
    for (int i = 0; i < length; i++) {
      if (braces[i] == '(' || braces[i] == ')') {
        braces[i] = 'a';
      }
      else if (braces[i] == '[' || braces[i] == ']') {
        braces[i] = 'b';
      }
      else if (braces[i] == '{' || braces[i] == '}') {
        braces[i] = 'c';
      }
    }
  cout << "New string: " << braces << endl;

    for (int i = 0; i < length-1; i++) {
  //    cout << "Int i is: " << i << endl;

      if (braces[i] == braces[i+1] ) {
   //     cout << "checking together: " << braces[i] << " and " << braces[i+1] << endl;
        i++;
      }
      else if (braces[i] == braces[length-1]) {
   //     cout << "checking ends: " << braces[i] << " and " << braces[length - 1] << endl;
       length--;
      }
   //   else if (braces[i] == ) {      }
      else {
        pairs = false;
       cout << pairs << endl;
      }
    }
  }
  cout << pairs << endl;
  return pairs;
}

int main() {

valid_braces("({})[({})]");

}

*/ 