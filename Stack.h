#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using std::cout;
using std::exception;
using std::string;
using std::stod;
using pep::vector;
using std::istringstream;

// TODO: Your code for question 3 goes here
class Stack{
private:
  vector<double> stack;
  int size;
  int top;
  int cap;

public:

  Stack():size(0),top(-1),cap(30){
    stack.resize(cap);
  }

  bool empty() const{
    return (size==0);
  }

  void push(const double input){
    if(stack.size()==(top+1)){
        cap *= 2;
        stack.resize(cap);
    }
      stack[++top] = input;
      ++size;
  }

  double pop(){
    if(empty()){
      cout<<"The stack is empty so removing failed.";
        return 0;
    }
    else{
      double returningValue = stack[top];
      stack[top] = 0;
      --top;
      --size;
      return returningValue;
    }
  }


};

double evaluate(const string input){
  Stack s;
  istringstream symbols(input);
  while (symbols) {
    string symbol;
    symbols >> symbol;
    if(symbol == "+" ){
      double a = s.pop();
      double b = s.pop();
      s.push(b+a);
    }else if (symbol=="-"){
      double a = s.pop();
      double b = s.pop();
      s.push(b-a);
    }else if(symbol=="/"){
      double a = s.pop();
      double b = s.pop();
      s.push(b/a);
    }else if(symbol == "*"){
      double a = s.pop();
      double b = s.pop();
      s.push(b*a);
    }
    else{
      try{
        s.push(stod(symbol));
      }
      catch(exception &e){
        continue;
      }
    }

  }

    return s.pop();
  }


// Do not write anything below this line

#endif
