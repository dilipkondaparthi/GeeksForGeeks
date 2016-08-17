/* Given an integer array, you need to find the two elements such that their sum is closest to zero.
Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=354 */

#include <iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() { 
	int t,n;
	cin>>t;
	while(t--)
	{
            cin>>n;
            int a[n];
            for(int i=0;i<n;i++)
                cin>>a[i];
            
            sort(a,a+n);
            
            int i=0,sum=INT_MAX,j=n-1,d,l;
            
            while(i<j)
            {
                if( abs(a[i]+a[j])<abs(sum))
                {
                    d=i;l=j;
                    sum=a[i]+a[j]; 
                }
                
                if(a[i]+a[j]>0)
                        j--;
                else
                        i++; 
            }
            cout<<a[d]<<" "<<a[l]<<endl;
        } 
        
	return 0;
}
