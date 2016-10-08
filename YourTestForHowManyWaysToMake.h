#ifndef YOUR_TEST_FOR_HOW_MANY_WAYS_TO_MAKE_H
#define YOUR_TEST_FOR_HOW_MANY_WAYS_TO_MAKE_H

#include "HowManyWaysToMake.h"
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int testHowManyWaysToMake() {
    // TODO: your test case for question 1b goes inside this function, instead of the next line of code:
    vector<int> test ={2,4,10};
    int amount = howManyWaysToMake(20,test);
    if(amount == 10){
      cout << "The code passed: code correctly returns that there are 10 ways to make 20 out of {2,4,10}\n";
      return 0;
    }
    else{
      cout << "The code failed: code instead returns " << amount << " ways to make 20 out of {2,4,10} -- but the answer is 10\n";
      return 1;
    }

}


// Do not write any code below this line

#endif
