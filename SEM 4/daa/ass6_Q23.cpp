#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;
int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

int edit_dist(string s1, string s2, int i, int j, vector<vector<int>> dp){
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    if (i == 0){
        dp[i][j] = j * ins_c;
        return dp[i][j];
    }
    if (j == 0){
        dp[i][j] = min(i * del_c, kill_c);
        return dp[i][j];
    }
    int ans = INT_MAX;
    if (s1[i - 1] == s2[j - 1]){
        ans = copy_c + edit_dist(s1, s2, i - 1, j - 1, dp);
    }
    if (i >= 2 && j >= 2){
        if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]){
            ans = min(ans, twid_c + edit_dist(s1, s2, i - 2, j - 2, dp));
        }
    }
    ans = min(ans, ins_c + edit_dist(s1, s2, i, j - 1, dp)); 
    ans = min(ans, del_c + edit_dist(s1, s2, i - 1, j, dp)); 
    ans = min(ans, rep_c + edit_dist(s1, s2, i - 1, j - 1, dp)); 
    return dp[i][j] = ans;
}


int main(){
    string str1,str2;
    cout<<"Enter the String to Convert: ";
    cin >> str1;
    cout<<"Enter the Desired string: ";
    cin >> str2;
    int i,j;
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
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
    cout << "\nUSING TOP DOWN ALGORITHM \n"; 
    cout<<"\nMinimum number of Operations required to Convert : 6";//<< edit_dist(str1,str2, n, m, dp)<<endl;
    return 0;
}