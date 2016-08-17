/* Question: Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer and k <= n. 
Find the maximum repeating number in this array.
For example, let k be 10 the given array be arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, 
the maximum repeating number would be 2 if there are two or more maximum repeating numbers, 
print the element having least value.
Expected time complexity is O(n) and extra space allowed is O(1).
Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=593  */
#include <iostream>
#include<climits> 
#include<algorithm>
using namespace std;
 
int main() { 
	int t,n,k;
	cin>>t;
	while(t--)
	{
            cin>>n>>k;
            int max=INT_MIN;   
            int a[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            
            for(int i=0;i<n;i++)
            {
                a[a[i]%k]+=k;
            }
            
            max=a[0]/k;
            
            for(int i=0;i<n;i++)
            {
                if(max<a[i]/k)
                {
                    max=a[i]/k; 
                }
            }
            
                for(int i=0;i<n;i++)
            {
                if(max==a[i]/k)
                { 
                 cout<<i<<endl; 
                 break;   
                }
            }
        }
           
	return 0;
}
