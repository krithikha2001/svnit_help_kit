<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int cost[5]={1,1,1,1,1};
bool check(string s1, string s2, int n, int m, string tmp)
{
	int ptr1 = 0, ptr2 = 0;
	char ch;
	for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++)
	{
		ch = tmp[i];
		if (ch == 'C')
		{
			if (s1[ptr1] == s2[ptr2])
			{
				ptr1++;
				ptr2++;
			}
		}
		else if (ch == 'R')
		{
			ptr1++;
			ptr2++;
		}
		else if (ch == 'D')
		{
			ptr1++;
		}
		else if (ch == 'I')
		{
			ptr2++;
		}
		else if (ch == 'T')
		{
			if (ptr1 <= n - 2 && ptr2 <= m - 2)
			{
				if (s1[ptr1] == s2[ptr2 + 1] && s1[ptr2] == s2[ptr1 + 1])
				{
					ptr1 += 2;
					ptr2 += 2;
				}
			}
		}
		else
		{
			if (ptr2 == m)
			{
				ptr1 = n;
				break;
			}
			// if (ptr1 == n)
			// {
			// ptr2 = m;
			// break;
			// }
		}
	}
	if (ptr1 == n && ptr2 == m)
		return true;
	else
		return false;
}
// Checks all Possible Operations
int editd(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	long int lmt = pow(6, m + n) - 1;
	int res = INT_MAX;
	for (int i = 0; i <= lmt; i++)
	{
		string tmp;
		int nums = i;
		for (int j = 0; j < max(m,n); j++)
		{
			tmp = to_string(nums % 6) + tmp;
			nums /= 6;
		}
		bool fl = false;
		for (int k = 0; k < tmp.length(); k++)
		{
			if (tmp[k] == '0')
			{
				fl = true;
				break;
			}
		}
		// Skip Number with 0 -> No Operation
		if (fl != false)
			continue;
		string tmp2;
		 
		for (int k = 0; k < tmp.length(); k++)
		{
			if (tmp[k] == '1')
				tmp2 += 'C';
			else if (tmp[k] == '2')
				tmp2 += 'R';
			else if (tmp[k] == '3')
				tmp2 += 'D';
			else if (tmp[k] == '4')
				tmp2 += 'I';
			else if (tmp[k] == '5')
				tmp2 += 'T';
			else
				tmp2 += 'K';
		}
		bool is_possible = check(s1, s2, n, m, tmp2);
		if (is_possible)
		{
			int cost1 = 0;
			for (int k = 0; k < tmp2.length(); k++)
			{
				if (tmp2[k] == 'C')
				cost1 += cost[4];
				else if (tmp2[k] == 'R')
				cost1 += cost[2];
				else if (tmp2[k] == 'I')
				cost1 += cost[1];
				else if (tmp2[k] == 'T')
				cost1 += cost[0];
				else if (tmp2[k] == 'D')
				cost1 += cost[3];
			}
			if (cost1 < res)
			{
				// cout << tmp2 << endl;
				res = cost1;
			}
		}
		}
		return res;
}
int main()
{
 int n,m,i,j;
 string s1,s2;
 cout<<"Enter  1st string : ";
 cin>>s1;
 cout<<"Enter 2nd string : ";
 cin>>s2;
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
 cout<<"The minimum number of operation for convertion : "<<editd(s1,s2)<<endl;
 return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
int cost[5]={1,1,1,1,1};
bool check(string s1, string s2, int n, int m, string tmp)
{
	int ptr1 = 0, ptr2 = 0;
	char ch;
	for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++)
	{
		ch = tmp[i];
		if (ch == 'C')
		{
			if (s1[ptr1] == s2[ptr2])
			{
				ptr1++;
				ptr2++;
			}
		}
		else if (ch == 'R')
		{
			ptr1++;
			ptr2++;
		}
		else if (ch == 'D')
		{
			ptr1++;
		}
		else if (ch == 'I')
		{
			ptr2++;
		}
		else if (ch == 'T')
		{
			if (ptr1 <= n - 2 && ptr2 <= m - 2)
			{
				if (s1[ptr1] == s2[ptr2 + 1] && s1[ptr2] == s2[ptr1 + 1])
				{
					ptr1 += 2;
					ptr2 += 2;
				}
			}
		}
		else
		{
			if (ptr2 == m)
			{
				ptr1 = n;
				break;
			}
			// if (ptr1 == n)
			// {
			// ptr2 = m;
			// break;
			// }
		}
	}
	if (ptr1 == n && ptr2 == m)
		return true;
	else
		return false;
}
// Checks all Possible Operations
int editd(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	long int lmt = pow(6, m + n) - 1;
	int res = INT_MAX;
	for (int i = 0; i <= lmt; i++)
	{
		string tmp;
		int nums = i;
		for (int j = 0; j < max(m,n); j++)
		{
			tmp = to_string(nums % 6) + tmp;
			nums /= 6;
		}
		bool fl = false;
		for (int k = 0; k < tmp.length(); k++)
		{
			if (tmp[k] == '0')
			{
				fl = true;
				break;
			}
		}
		// Skip Number with 0 -> No Operation
		if (fl != false)
			continue;
		string tmp2;
		 
		for (int k = 0; k < tmp.length(); k++)
		{
			if (tmp[k] == '1')
				tmp2 += 'C';
			else if (tmp[k] == '2')
				tmp2 += 'R';
			else if (tmp[k] == '3')
				tmp2 += 'D';
			else if (tmp[k] == '4')
				tmp2 += 'I';
			else if (tmp[k] == '5')
				tmp2 += 'T';
			else
				tmp2 += 'K';
		}
		bool is_possible = check(s1, s2, n, m, tmp2);
		if (is_possible)
		{
			int cost1 = 0;
			for (int k = 0; k < tmp2.length(); k++)
			{
				if (tmp2[k] == 'C')
				cost1 += cost[4];
				else if (tmp2[k] == 'R')
				cost1 += cost[2];
				else if (tmp2[k] == 'I')
				cost1 += cost[1];
				else if (tmp2[k] == 'T')
				cost1 += cost[0];
				else if (tmp2[k] == 'D')
				cost1 += cost[3];
			}
			if (cost1 < res)
			{
				// cout << tmp2 << endl;
				res = cost1;
			}
		}
		}
		return res;
}
int main()
{
 int n,m,i,j;
 string s1,s2;
 cout<<"Enter  1st string : ";
 cin>>s1;
 cout<<"Enter 2nd string : ";
 cin>>s2;
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
 cout<<"The minimum number of operation for convertion : "<<editd(s1,s2)<<endl;
 return 0;
}
>>>>>>> 4113b8d2c58f52cfdcecb384a4a40fea913e2ffe
