#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;
int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

int edit_dist(string s1, string s2, int i, int j){
    if (i == -1 && j == -1){
        return 0;
    }
    if (i == -1){
        return (j + 1) * ins_c;
    }
    if (j == -1){
        return min(kill_c, (i + 1) * del_c);
    }
    int ans = INT_MAX;
    if (s1[i] == s2[j]){
        ans = min(ans, copy_c + edit_dist(s1, s2, i - 1, j - 1));
    }
    if (i >= 1 && j >= 1){
        if (s1[i] == s2[j - 1] && s1[i - 1] == s2[j]){
            ans = min(ans, twid_c + edit_dist(s1, s2, i - 2, j - 2));
        }
    }
    ans = min(ans, ins_c + edit_dist(s1, s2, i, j - 1)); 
    ans = min(ans, del_c + edit_dist(s1, s2, i - 1, j)); 
    ans = min(ans, rep_c + edit_dist(s1, s2, i - 1, j - 1)); 
    return ans;
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
    cout << "\nUSING NAIVE RECURSIVE ALGORITHM \n";
    cout<<"\nMinimum number of Operations required to Convert : "<< edit_dist(str1,str2, n, m)<<endl;
    return 0;
}

