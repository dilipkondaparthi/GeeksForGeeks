/* Question: You are involved in a betting game whose rules are as follows :
a) If you win a round, the bet amount will be added to your current sum and next bet amount will become $1;
b) If you lose a round, the bet amount will be reduced from your current sum and next bet will become twice the previous.
c) game ends either when all the rounds are complete or when you don't have sufficient sum.
Initially, you are given with a string consisiting of characters from the set {'W', 'L'}, where 'W' indicates a win 
and 'L' indicates a loss, and initial sum is 4. Initial bet amount for the 1st round will be $1.

You need to find and print the amount at the end of the game (final sum)
and in case you do not have enough money in between the game to play the next round, then print -1. 

Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=671 */

#include<iostream> 
#include<algorithm>
using namespace std;
 
  int betgame(string x,int n)
  {  
      int betamount=1,cursum=4;
      for(int i=0;i<n;i++)
      {
          if(cursum<betamount)
              return -1;
          if(x[i]=='W')
          {
              cursum+=betamount;
              betamount=1;
          }
          else
          {
              cursum-=betamount;
              betamount*=2;
          } 
      }
      return cursum;
  }

int main() 
{ 
	int t;
  string x;
	cin>>t;
	while(t--)
	{
      cin>>x; 
      cout<<betgame(x,x.size())<<endl; 
  }
         
 
	return 0;
}
