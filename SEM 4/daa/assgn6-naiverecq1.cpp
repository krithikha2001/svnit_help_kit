#include<bits/stdc++.h>
using namespace std;

string lps(string str,int l,int h)
{
	 if(l>h) 
	 {
	 	return string("");
	 }
	 else if(l==h)
	 {
		 string temp=""; 
		 return temp+str[l];
	 }
	 else if(str[l]==str[h])
	 {
		 if(h-l==1) 
		 {
			 string temp="";
			 return temp+str[l]+str[h]; 
		 }
		 else
		 {
		 	return (str[l]+lps(str,l+1,h-1)+str[h]);
		 }
	 } 
	 else if(lps(str,l+1,h).length()>=lps(str,l,h-1).length()) 
	 {
		 return lps(str,l+1,h);
	 }
	 else
	 {
	 	return lps(str,l,h-1);
	 }
}

int main()
{
 int n;
 string s;
 cout<<"Enter the string for finding longest palindrome subsequence:";
 cin >> s;
 n = s.length();

 string res=lps(s,0,n-1);
cout <<"\nThe length of longest palindromic sequence is:" <<res.length() << "\nThe longest palidromic subsequence string is:" << res;
 return 0;
}

