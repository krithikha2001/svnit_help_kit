#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s) 
{
 int n = s.length();
 for (int i = 0; i < n/2; i++)
 {
	 if (s[i]!=s[n-i-1])
	 {
	 	return false;
	 }
 }
 return true;
 
}
int main()
{
 string s;
 cout<<"Enter the string for finding longest palindrome subsequence:";
 cin >> s;
 int n = s.length();
 int l=0;
 string res;
 for (int i = 0; i < 1<<n; i++) 
 {
	 string sub = "";
	 for (int j = 0; j < n; j++) 
	 {
		 if (i & 1<<j)	//1 * 2powerj
		 {
		 	sub = sub+s[j];	//to check if the jth bit from the right in i is equal to 1 or 0
		 }
	 }
	 if(ispalindrome(sub) && sub.length()>l)
	 { 
	 	res = sub;
	 	l = sub.length();
	 }
 }
 cout <<"\nThe length of longest palindromic sequence is:" <<res.length() << "\nThe longest palidromic subsequence string is:" << res;
 return 0;
}








/*
#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s) //to check if it is a palindrome or not
{
 int n = s.length();
 for (int i = 0; i < n/2; i++)
 {
	 if (s[i]!=s[n-i-1])
	 {
	 	return false;
	 }
 }
 return true;
 
}
int main()
{
 string s;
 cout<<"Enter the string for finding longest palindrome subsequence:";
 cin >> s;
 int n = s.length(),max=1,start=0;
 for (int i = 0; i < s.length(); i++) 
  {
        for (int j = i; j < s.length(); j++) 
		{
            int flag = 1;
 
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (s[i + k] != s[j - k])
                    flag = 0;
 
            if (flag && (j - i + 1) > max) 
			{
                start = i;
                max = j - i + 1;
            }
 		}
 }
  cout <<"\nThe Longest palindromic sequence is:";
 for (int i = start; i <= start+max-1; ++i)
        cout << s[i];
   cout << "\nThe length of longest palidromic subsequence string is:" << max;
   return 0;

}	
*/

