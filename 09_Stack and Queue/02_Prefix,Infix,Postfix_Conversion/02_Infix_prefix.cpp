// Infix to Prefix

// Mark as Completed

// 50


// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a prefix expression.

// Examples:

// Example 1:
// Input: x+y*z/w+u
// Output: ++x/*yzwu
// Explanation: Infix to prefix

// Example 2:
// Input: a+b
// Output: +ab
// Explanation: Infix to prefix
// Solution
// Disclaimer: Don't jump directly to the solution, try it out yourself first.

// What is infix expression?
// The traditional method of writing mathematical expressions is called infix expressions.
// It is of the form <operand><operator><operand>.
// As the name suggests, here the operator is fixed inside between the operands. e.g. A+B here the plus operator is placed inside between the two operators, (A*B)/Q.
// Such expressions are easy to understand and evaluate for human beings. However, the computer finds it difficult to parse - Information is needed about operator precedence and associativity rules, and brackets that override these rules.
// Hence we have postfix and prefix notations which make the computer take less effort to solve the problem.
// What is prefix expression?
// The prefix expression as the name suggests has the operator placed before the operand is specified.
// It is of the form <operator><operand><operand>.
// It works entirely in the same manner as the postfix expression.
// While evaluating a prefix expression, the operators are applied to the operands immediately on the right of the operator.
// For evaluation, we evaluate it from left to right. Prefix expressions are also called polish notation.
// Approach:
// First, reverse the infix expression given in the problem.
// Scan the expression from left to right.
// Whenever the operands arrive, print them.
// If the operator arrives and the stack is found to be empty, then simply push the operator into the stack.
// If the incoming operator has higher precedence than the TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has the same precedence with a TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has lower precedence than the TOP of the stack, pop, and print the top of the stack. Test the incoming operator against the top of the stack again and pop the operator from the stack till it finds the operator of lower precedence or same precedence.
// If the incoming operator has the same precedence with the top of the stack and the incoming operator is ^, then pop the top of the stack till the condition is true. If the condition is not true, push the ^ operator.
// When we reach the end of the expression, pop, and print all the operators from the top of the stack.
// If the operator is ')', then push it into the stack.
// If the operator is '(', then pop all the operators from the stack till it finds the ‘)’ bracket in the stack.
// If the top of the stack is ')', push the operator on the stack.
// In the end, reverse the output. And print it.
// Code:

#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
  if (C == '-' || C == '+')
    return 1;
  else if (C == '*' || C == '/')
    return 2;
  else if (C == '^')
    return 3;
  return 0;
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = infix.size();
  stack < char > char_stack;
  string output;

  for (int i = 0; i < l; i++) {

    // If the scanned character is an
    // operand, add it to output.
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (infix[i] == '(')
      char_stack.push('(');

    // If the scanned character is an
    // ‘)’, pop and output from the stack
    // until an ‘(‘ is encountered.
    else if (infix[i] == ')') {
      while (char_stack.top() != '(') {
        output += char_stack.top();
        char_stack.pop();
      }

      // Remove '(' from the stack
      char_stack.pop();
    }

    // Operator found
    else {
      if (isOperator(char_stack.top())) {
        if (infix[i] == '^') {
          while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        } else {
          while (getPriority(infix[i]) < getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        }

        // Push current Operator on stack
        char_stack.push(infix[i]);
      }
    }
  }
  while (!char_stack.empty()) {
    output += char_stack.top();
    char_stack.pop();
  }
  return output;
}

string infixToPrefix(string infix) {
  /* Reverse String
   * Replace ( with ) and vice versa
   * Get Postfix
   * Reverse Postfix  *  */
  int l = infix.size();

  // Reverse infix
  reverse(infix.begin(), infix.end());

  // Replace ( with ) and vice versa
  for (int i = 0; i < l; i++) {

    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);

  // Reverse postfix
  reverse(prefix.begin(), prefix.end());

  return prefix;
}

int main() {
  string s = ("(p+q)*(c-d)");
  cout << "Infix expression: " << s << endl;
  cout << "Prefix Expression: " << infixToPrefix(s) << endl;
  return 0;
}