#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
using std::vector;
using std::size_t;

// TODO: Your answer for question 2 goes here

int maximumGates(const vector<int> &arrives,const vector<int> &departs){

  if(arrives.empty()){
    return 0;
  }
  int gates = 1;
  for(size_t i = 0;i<(arrives.size()-1);i++){
    if(departs[i]>=arrives[i+1]){
        gates++;
      }
  }
  return gates;
}



// Do not write any code below this line


#endif
