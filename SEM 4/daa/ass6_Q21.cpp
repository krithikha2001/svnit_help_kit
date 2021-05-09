<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;
int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

bool check(string s1, string s2, int n, int m, string tmp){
    int ptr1 = 0, ptr2 = 0;
    char ch;
    for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++){
        ch = tmp[i];
        if (ch == 'C')
		{
            if (s1[ptr1] == s2[ptr2])
			{
                ptr1++;
                ptr2++;
            }
        }
        else if (ch == 'R'){
            ptr1++;
            ptr2++;
        }
        else if (ch == 'D'){
            ptr1++;
        }
        else if (ch == 'I'){
            ptr2++;
        }
        else if (ch == 'T'){
            if (ptr1 <= n - 2 && ptr2 <= m - 2){
                if (s1[ptr1] == s2[ptr2 + 1] && s1[ptr2] == s2[ptr1 + 1]){
                    ptr1 += 2;
                    ptr2 += 2;
                }
            }
        }
        else{
            if (ptr2 == m){
                ptr1 = n;
                break;
            }
        }
    }
    if (ptr1 == n && ptr2 == m)
        return true;
    else
        return false;
}

int naive(string s1, string s2){
    int n = s1.length(), m = s2.length();
    long int lmt = pow(7, m + n) - 1;
    int res = INT_MAX;
    for (int i = 0; i <= lmt; i++){
        string tmp;
        int nums = i;
        for (int j = 0; j < max(m,n); j++){
            tmp = to_string(nums % 7) + tmp;
            nums /= 7;
        }
        bool fl = false;
        for (int k = 0; k < tmp.length(); k++){
            if (tmp[k] == '0'){
                fl = true;
                break;
            }
        }
        if (fl != false)
            continue;
        string tmp2;
        for (int k = 0; k < tmp.length(); k++){
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
        if (is_possible){
            int cost = 0;
            for (int k = 0; k < tmp2.length(); k++){
                if (tmp2[k] == 'C')
                    cost += copy_c;
                else if (tmp2[k] == 'R')
                    cost += rep_c;
                else if (tmp2[k] == 'I')
                    cost += ins_c;
                else if (tmp2[k] == 'T')
                    cost += twid_c;
                else if (tmp2[k] == 'D')
                    cost += del_c;
                else
                    cost += kill_c;
            }
            if (cost < res){
                res = cost;
            }
        }
    }
    return res;
}

int main(){
    string str1,str2;
    cout<<"Enter the String to Convert: ";
    cin >> str1;
    cout<<"Enter the Desired string: ";
    cin >> str2;
    int n = str1.length();
    int m = str2.length();
    cout<<"Enter the Cost of Operations : \n";
    cout<<"Copy: ";
    cin>>copy_c;
    cout<<"Replace: ";
    cin>>rep_c;
    cout<<"Delete: ";
    cin>>del_c;
    cout<<"Insert: ";
    cin>>ins_c;
    cout<<"Twiddle: ";
    cin>>twid_c;
    cout<<"Kill: ";
    cin>>kill_c;
    cout << "\nUSING NAIVE ITERATIVE ALGORITHM \n"; 
    cout<<"\nMinimum number of Operations required to Convert : "<< naive(str1,str2)<<endl;
    return 0;
}
=======
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;
int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

bool check(string s1, string s2, int n, int m, string tmp){
    int ptr1 = 0, ptr2 = 0;
    char ch;
    for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++){
        ch = tmp[i];
        if (ch == 'C')
		{
            if (s1[ptr1] == s2[ptr2])
			{
                ptr1++;
                ptr2++;
            }
        }
        else if (ch == 'R'){
            ptr1++;
            ptr2++;
        }
        else if (ch == 'D'){
            ptr1++;
        }
        else if (ch == 'I'){
            ptr2++;
        }
        else if (ch == 'T'){
            if (ptr1 <= n - 2 && ptr2 <= m - 2){
                if (s1[ptr1] == s2[ptr2 + 1] && s1[ptr2] == s2[ptr1 + 1]){
                    ptr1 += 2;
                    ptr2 += 2;
                }
            }
        }
        else{
            if (ptr2 == m){
                ptr1 = n;
                break;
            }
        }
    }
    if (ptr1 == n && ptr2 == m)
        return true;
    else
        return false;
}

int naive(string s1, string s2){
    int n = s1.length(), m = s2.length();
    long int lmt = pow(7, m + n) - 1;
    int res = INT_MAX;
    for (int i = 0; i <= lmt; i++){
        string tmp;
        int nums = i;
        for (int j = 0; j < max(m,n); j++){
            tmp = to_string(nums % 7) + tmp;
            nums /= 7;
        }
        bool fl = false;
        for (int k = 0; k < tmp.length(); k++){
            if (tmp[k] == '0'){
                fl = true;
                break;
            }
        }
        if (fl != false)
            continue;
        string tmp2;
        for (int k = 0; k < tmp.length(); k++){
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
        if (is_possible){
            int cost = 0;
            for (int k = 0; k < tmp2.length(); k++){
                if (tmp2[k] == 'C')
                    cost += copy_c;
                else if (tmp2[k] == 'R')
                    cost += rep_c;
                else if (tmp2[k] == 'I')
                    cost += ins_c;
                else if (tmp2[k] == 'T')
                    cost += twid_c;
                else if (tmp2[k] == 'D')
                    cost += del_c;
                else
                    cost += kill_c;
            }
            if (cost < res){
                res = cost;
            }
        }
    }
    return res;
}

int main(){
    string str1,str2;
    cout<<"Enter the String to Convert: ";
    cin >> str1;
    cout<<"Enter the Desired string: ";
    cin >> str2;
    int n = str1.length();
    int m = str2.length();
    cout<<"Enter the Cost of Operations : \n";
    cout<<"Copy: ";
    cin>>copy_c;
    cout<<"Replace: ";
    cin>>rep_c;
    cout<<"Delete: ";
    cin>>del_c;
    cout<<"Insert: ";
    cin>>ins_c;
    cout<<"Twiddle: ";
    cin>>twid_c;
    cout<<"Kill: ";
    cin>>kill_c;
    cout << "\nUSING NAIVE ITERATIVE ALGORITHM \n"; 
    cout<<"\nMinimum number of Operations required to Convert : "<< naive(str1,str2)<<endl;
    return 0;
}
>>>>>>> 4113b8d2c58f52cfdcecb384a4a40fea913e2ffe
