// Copyright 2020 A.SHT
#include "MyStack.h"
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  MyStack<char> oper(infix.size());
  MyStack<char> var(infix.size());
  for(auto i : infix) {
    if (i == '(')
      oper.push(i);
    else if (i == ')') {
      while (oper.get() != '(')
        var.push(oper.pop());
      oper.pop();
    }
    else if (i >= '0' && i <= '9')
      var.push(i);
    else if (i == '+' || i == '-') 
      if(oper.isEmpty() || oper.get() == '(')
        oper.push(i);
      else {
        while (!(oper.isEmpty() || oper.get() == '('))
          var.push(oper.pop());
        oper.push(i);
      }
    else if (i == '*' || i == '/')
      if (oper.isEmpty() || (oper.get() != '*' && oper.get() != '/'))
        oper.push(i);
      else {
        while (!(oper.isEmpty() || (oper.get() != '*' && oper.get() != '/')))
          var.push(oper.pop());
        oper.push(i);
      }
  }
  while(!oper.isEmpty())
    var.push(oper.pop());
  infix.clear();
  while(!var.isEmpty()) {
    infix.insert(infix.begin(), ' ');
    infix.insert(infix.begin(), var.pop());
  }
  infix.pop_back();
  return infix;
}
