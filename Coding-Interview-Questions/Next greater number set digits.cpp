/* Given a number n, find the smallest number that has same set of digits as n and is greater than n.
If x is the greatest possible number with its set of digits, then print “not possible”.

Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=384 */

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
 
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int main() { 
	int testcases;
	cin>>testcases;
        string x;
	while(testcases--)
	{
            cin>>x;
            int l=x.size(),d=0,t=INT_MAX,check=INT_MAX;
            
            for(int i=l-1;i>0;i--)
            { 
                    if(x[i-1]<x[i])
                    {  
                        int j=i;
                        while(j<l)
                        {
                            if(x[i-1]<x[j])
                            { 
                                if(x[j]<check)
                                {
                                    check=x[j];
                                    t=j;
                                } 
                            }
                             j++;
                        }
                        swap(&x[i-1],&x[t]);
                        d=1;
                        sort(x.begin()+i,x.end()); 
                        break;
                    }
            } 
             (d==0)?cout<<"not possible"<<endl:cout<<x<<endl; 
        } 
	return 0;
}
