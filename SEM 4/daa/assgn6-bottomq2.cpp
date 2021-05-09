#include<bits/stdc++.h>
using namespace std;
int cost[5]={1,1,1,1,1};

int editd(string str1,string str2,int n,int m)
{
 int i,j;
 int dp[n+1][m+1];
 
for(i=0;i<=n;i++)
{
	for(j=0;j<=m;j++)
	{
		if(i==0)
		{
			 dp[i][j]=j*cost[1]; //insert all
		}
		else if(j==0)
		{
			 dp[i][j]=i*cost[3]; //delete all
		}
		else if(str1[i-1]==str2[j-1])
		{
			 dp[i][j]=dp[i-1][j-1];
		} 
		else
		{
			int o0=INT_MAX,o1,o2,o3,o4;
		 	if(str1[i-2]==str2[j-1]&&str1[i-1]==str2[j-2]&&i>=2&&j>=2)
		 	{
		 		o0=dp[i-2][j-2]+cost[0];//twiddle
		 	}
			 o1=cost[1]+dp[i][j-1];//insert
			 o2=cost[2]+dp[i-1][j-1];//replace
			 o3=cost[3]+dp[i-1][j];//delete
			 o4=cost[4]+dp[i-1][j-1];//copy
			 dp[i][j]=min(o0,min(o1,min(o2,min(o3,o4))));
		}
	}
  }
 return dp[n][m];
}
int main()
{
	  string s1,s2;
	 cout<<"Enter  1st string : ";
	 cin>>s1;
	 cout<<"Enter 2nd string : ";
	 cin>>s2;
	 int n=s1.length();
	 int m=s2.length();
	 cout<<"Enter the cost of operations : \n";
	 cout<<"Twiddle : ";
	 cin>>cost[0];
	 cout<<"Insert : ";
	 cin>>cost[1];
	 cout<<"Replace : ";
	 cin>>cost[2];
	 cout<<"Delete : ";
	 cin>>cost[3];
	 cout<<"Copy : ";
	 cin>>cost[4];
	 cout<<"The minimum number of operation for convertion : "<<editd(s1,s2,n,m)<<endl;
	 return 0;
}
