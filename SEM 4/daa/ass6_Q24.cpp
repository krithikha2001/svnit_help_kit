<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

int edit_dist(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for (int i = 0; i < m + 1; i++){
        dp[i][0] = min(i * del_c, kill_c);
    }
    for (int j = 0; j < n + 1; j++){
        dp[0][j] = j * ins_c;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] =INT_MAX;
            if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + copy_c;
            if (i >= 2 && j >= 2){
                if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]){
                    dp[i][j] = min(dp[i][j], twid_c + dp[i - 2][j - 2]);
                }
            }
            dp[i][j] = min(dp[i][j], ins_c + dp[i][j - 1]); 
            dp[i][j] = min(dp[i][j], del_c + dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], rep_c + dp[i - 1][j - 1]); 
        }
    }
    return dp[m][n];
}

int main(){
    string str1,str2;
    cout<<"Enter the String to Convert: ";
    cin >> str1;
    cout<<"Enter the Desired string: ";
    cin >> str2;
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
    cout << "\nUSING BOTTOM UP ALGORITHM \n"; 
    cout<<"\nMinimum number of Operations required to Convert : "<< edit_dist(str1, str2)<<endl;
    return 0;
=======
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int copy_c, rep_c, ins_c, del_c, twid_c, kill_c;

int edit_dist(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for (int i = 0; i < m + 1; i++){
        dp[i][0] = min(i * del_c, kill_c);
    }
    for (int j = 0; j < n + 1; j++){
        dp[0][j] = j * ins_c;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] =INT_MAX;
            if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + copy_c;
            if (i >= 2 && j >= 2){
                if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]){
                    dp[i][j] = min(dp[i][j], twid_c + dp[i - 2][j - 2]);
                }
            }
            dp[i][j] = min(dp[i][j], ins_c + dp[i][j - 1]); 
            dp[i][j] = min(dp[i][j], del_c + dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], rep_c + dp[i - 1][j - 1]); 
        }
    }
    return dp[m][n];
}

int main(){
    string str1,str2;
    cout<<"Enter the String to Convert: ";
    cin >> str1;
    cout<<"Enter the Desired string: ";
    cin >> str2;
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
    cout << "\nUSING BOTTOM UP ALGORITHM \n"; 
    cout<<"\nMinimum number of Operations required to Convert : "<< edit_dist(str1, str2)<<endl;
    return 0;
>>>>>>> 4113b8d2c58f52cfdcecb384a4a40fea913e2ffe
}