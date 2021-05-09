#include<bits/stdc++.h>
using namespace std;
int cost[5]={1,1,1,1,1};
int editd(string str1,string str2,int n,int m)
{
	 if(n==0)
	 {
	 	return m;
	 }
	 if(m==0)
	 {
	 	return n;
	 }
	 if(str1[n-1]==str2[m-1])
	 {
	 	return editd(str1,str2,n-1,m-1);
	 }
	 
	 int o1,o2,o3,o4,o0=INT_MAX;
	 o1=cost[1]+editd(str1,str2,n,m-1); //insert
	 o2=cost[2]+editd(str1,str2,n-1,m-1);//replace
	 o3=cost[3]+editd(str1,str2,n-1,m);//delete
	 o4=cost[4]+editd(str1,str2,n-1,m-1);//copy
	 if(str1[n-2]==str2[m-1]&&str1[n-1]==str2[m-2]&&n>=2&&m>=2)
	 {
	 	o0= cost[0]+editd(str1,str2,n-2,m-2);//twiddle
	 }
	 return min(o0,min(o1,min(o2,min(o3,o4))));
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
