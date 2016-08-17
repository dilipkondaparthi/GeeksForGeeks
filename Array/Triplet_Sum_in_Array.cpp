/* Given an array A[] of n numbers and another number x, 
Determine whether or not there exist three elements in A[] whose sum is exactly x.
Expected time complexity is O(n^2).
Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=732
*/

#include<iostream> 
#include<algorithm>
using namespace std;
 
bool tripletsum(int a[],int n,int k)
{
      for(int i=n-1;i>=2;i--)
            {
                int l=0,r=i-1;
                while(l<r)
                {
                    if(a[l]+a[r]+a[i]==k)
                        return true;
                    else if(a[l]+a[r]+a[i]>k)
                        r--;
                    else
                        l++;
                }
            } 
return false;
}

int main() { 
	int t,n,k;
	cin>>t;
	while(t--)
	{
            cin>>n>>k;
            int a[n];
            for(int i=0;i<n;i++)
                cin>>a[i];
            
            sort(a,a+n); 
            tripletsum(a,n,k)?cout<<"1"<<endl:cout<<"0"<<endl; 
        }
 
	return 0;
}
