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
using std::stoi;
using pep::vector;
using std::istringstream;

// TODO: Your code for question 3 goes here
class Stack{
private:
  vector<double> stack;
  int size;
  int top;

public:

  Stack():size(0),top(-1){
    stack.resize(30);
  }

  bool empty() const{
    return (size==0);
  }

  void push(const double input){
    if(stack.size()==(top+1)){
      cout<<"The stack is full, adding failed.";
    }
    else{
      stack[++top] = input;
      ++size;
    }
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
        s.push(stoi(symbol));
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
