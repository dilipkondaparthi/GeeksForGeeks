// Reverse a 32 bit given number.
// Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=576

#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
 
int main() { 
	long long int t,n;
	cin>>t;
	while(t--)
	{
            cin>>n;
            long long int a[32]={0};
            long long int sum=0, i=0;
            while(n!=0)
            {
              a[i++]=n%2;
              n=n/2;
            }
            
            for(int i=31;i>=0;i--)
            {
                sum+=a[i]*pow(2,31-i);
            }
            cout<<sum<<endl;
        } 
 
	return 0;
}
