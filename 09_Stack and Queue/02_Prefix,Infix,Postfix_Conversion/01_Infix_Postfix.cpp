// Infix to Postfix


// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

// Examples:

// Example 1:
// Input: a+b*(c^d-e)^(f+g*h)-i
// Output: abcd^e-fgh*+^*+i-
// Explanation: Infix to postfix

// Example 2:
// Input: (p+q)*(m-n)
// Output: pq+mn-*
// Explanation: Infix to postfix
// Solution
// Disclaimer: Don't jump directly to the solution, try it out yourself first.

// What is infix expression?
// The traditional method of writing mathematical expressions is called infix expressions.
// It is of the form <operand><operator><operand>.
// As the name suggests, here the operator is fixed inside between the operands. e.g. A+B here the plus operator is placed inside between the two operators, (A*B)/Q.
// Such expressions are easy to understand and evaluate for human beings. However, the computer finds it difficult to parse - Information is needed about operator precedence and associativity rules, and brackets that override these rules.
// Hence we have postfix and prefix notations which make the computer take less effort to solve the problem.
// What is postfix expression?
// The postfix expression as the name suggests has the operator placed right after the two operands.
// It is of the form <operand><operand><operator>
// In the infix expressions, it is difficult to keep track of the operator precedence whereas here the postfix expression itself determines the precedence of operators (which is done by the placement of operators)i.e the operator which occurs first operates on the operand.
// E.g. PQ-C/, here – operation is done on P and Q and then / is applied on C and the previous result.
// A postfix expression is a parenthesis-free expression. For evaluation, we evaluate it from left to right.


// Approach: To convert Infix expression to Postfix
// 1. Scan the infix expression from left to right. 

// 2. If the scanned character is an operand, Print it. 

// 3. Else, 

// If the precedence of the scanned operator is greater than the precedence of the operator in the stack or the stack is empty or the stack contains a ‘(‘, push the character into the stack. 
// Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. 
// 4. If the scanned character is an ‘(‘, push it into the stack. 

// 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 

// 6. Repeat steps 2-5 until the entire infix expression is scanned. 

// 7. Print the output.

// 8. Pop and print the output from the stack until it is not empty.

// Code:


#include<bits/stdc++.h>

using namespace std;

//Function to return precedence of operators
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

  stack < char > st; //For stack operations, we are using C++ built in stack
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Prefix expression: " << result << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}