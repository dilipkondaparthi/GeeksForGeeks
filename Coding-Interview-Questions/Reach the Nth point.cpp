/* Question: There are N points on the road ,you can step ahead by 1 or 2 .
Find the number of ways you can reach at point N. 
For example:for n=4 we have 5 possible ways [1,1,1,1]  [1,1,2]  [1,2,1]  [2,1,1]  [2 2].

Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=589  */

#include <iostream>  
#include<algorithm>
using namespace std;

int main() { 
	long long int t,n;
	cin>>t;
	while(t--)
	{
            cin>>n;
            long long  int dp[n+1];
            dp[0]=1;
            dp[1]=1;
            
            for(long long int i=2;i<=n;i++)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            
            cout<<dp[n]<<endl;
        }  
	return 0;
}
