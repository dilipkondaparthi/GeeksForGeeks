/* Question: The cost of a stock on each day is given in an array,
find the max profit that you can make by buying and selling in those days. 

Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=376 */

#include <iostream> 
#include<algorithm>
using namespace std;
 
int main() 
{ 
	int t,n;
	cin>>t;
	while(t--)
	{
            cin>>n;
            int a[n];
            int l=-1,h=-1; bool d=0;
            for(int i=0;i<n;i++)
                cin>>a[i];
           
            for(int i=0;i<n;i++)
            {   
                if(i==0 && a[i]<a[i+1])
                {d=1;l=i;}
                else if(i==n-1 && a[i]>a[i-1])
                {d=1;h=i;}
                else if(i>0 && i<n-1 && a[i]>a[i-1] && a[i]>a[i+1])
                {
                    d=1;
                    if(h==-1)
                        h=i;
                }
                else if(i>0 && i<n-1 && a[i]<a[i-1] && a[i]<a[i+1])
                {
                    d=1;
                    if(l!=-1 && h!=-1){
                    cout<<"("<<l <<" "<<h<<") ";
                    l=-1; 
                    h=-1;
                }
                    l=i;
                }
            }
              if(d==0)
                cout<<"No Profit"<<endl;  
              else if(l!=-1 && h!=-1)
                cout<<"("<<l<<" "<<h<<")"<<endl; 
        } 
	return 0;
}
