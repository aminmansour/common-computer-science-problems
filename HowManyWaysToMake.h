#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H
#include <vector>
#include<iostream>
using std::vector;
using namespace std;

// TODO: Your answer for question 1a goes here


int howManyWaysToMake( int coinTotal,const vector<int> &coinStack){
  //creates a array which will accumlate the amount of ways to make total current total starting from 1 untill
 //coinTotal is reached. To find amount of ways at any given total, we take index amount of coins in array away from index current total and plus it with the previous amount
 //of solutions for the previous coin but for the same total. we do this for each and add them together until it accumlates to the total coinTotal.
 if(coinTotal!= 0 ){
 int solutionsForCoinTotal = 0;
 vector<int> waysToMake(coinTotal);
 for(int coin:coinStack){
   int prev = 1;
        int amountOfSolutionsForCurrentCoin = coin;
        while(amountOfSolutionsForCurrentCoin <= coinTotal){
              if(amountOfSolutionsForCurrentCoin==coinTotal){
                waysToMake[amountOfSolutionsForCurrentCoin] = solutionsForCoinTotal + prev;
                solutionsForCoinTotal = waysToMake[amountOfSolutionsForCurrentCoin];
              }else{
                waysToMake[amountOfSolutionsForCurrentCoin] = waysToMake[amountOfSolutionsForCurrentCoin] + prev;
              }
              amountOfSolutionsForCurrentCoin++;
              prev =  waysToMake[amountOfSolutionsForCurrentCoin-coin];
        }
      }
      return solutionsForCoinTotal;
    }
    return 0;
}


// Do not write any code below this line

#endif
