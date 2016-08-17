// Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?
// Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=660

#include<iostream> 
#include<algorithm>
using namespace std;
 
int main() { 
	int t,n;
	cin>>t;
	while(t--)
	{
            cin>>n;
            int f[n+1];
            f[0]=1;
            f[1]=1;
            f[2]=2;
            
            for(int i=3;i<n+1;i++)
            {
                f[i]=f[i-1]+f[i-2]+f[i-3];
            }
            cout<<f[n]<<endl;
  }
         
 
	return 0;
}
