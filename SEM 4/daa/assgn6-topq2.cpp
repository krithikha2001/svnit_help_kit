<<<<<<< HEAD
#include<bits/stdc++.h>

using namespace std;
#define N 1000
int dp[N][N], cost[5] = {1,1,1,1,1};
int editdist(string str1, string str2, int n, int m) {

        if (dp[n][m] != -1) {
                return dp[n][m];
        }
        if (n == 0) {
                dp[n][m] = m * cost[1];
        } else if (m == 0) {
                dp[n][m] = n * cost[3];
        } else if (str1[n - 1] == str2[m - 1]) {
                dp[n][m] = editdist(str1, str2, n - 1, m - 1);
        } else {
                int p0 = INT_MAX, p1, p2, p3, p4;
                if (str1[n - 2] == str2[m - 1] && str1[n - 1] == str2[m - 2] && n >= 2 && m >= 2) {
                        p0 = cost[0] + editdist(str1, str2, n - 2, m - 2); //twiddle
                }
                p1 = cost[1] + editdist(str1, str2, n, m - 1); //insert
                p2 = cost[2] + editdist(str1, str2, n - 1, m - 1); //replace
                p3 = cost[3] + editdist(str1, str2, n - 1, m); //delete
                p4 = cost[4] + editdist(str1, str2, n - 1, m - 1); //copy 
                dp[n][m] = min(p0, min(p1, min(p2, min(p3, p4))));
        }
        return dp[n][m];
}
int main() {
        string s1, s2;
        cout << "Enter the 1st string : ";
        cin >> s1;
        cout << "Enter the 2nd string : ";
        cin >> s2;
        for (int i = 0; i <= s1.length(); i++) {
                for (int j = 0; j <= s2.length(); j++) {
                        dp[i][j] = -1;
                }
        }
        cout << "Enter the cost of : \n";
        cout << "Twiddle : ";
        cin >> cost[0];
        cout << "Insert : ";
        cin >> cost[1];
        cout << "Replace : ";
        cin >> cost[2];
        cout << "Delete : ";
        cin >> cost[3];
        cout << "Copy : ";
        cin >> cost[4];
        cout << "The minimum cost(top down): " << editdist(s1, s2, s1.length(), s2.length()) << endl;
        return 0;
}
=======
#include<bits/stdc++.h>

using namespace std;
#define N 1000
int dp[N][N], cost[5] = {1,1,1,1,1};
int editdist(string str1, string str2, int n, int m) {

        if (dp[n][m] != -1) {
                return dp[n][m];
        }
        if (n == 0) {
                dp[n][m] = m * cost[1];
        } else if (m == 0) {
                dp[n][m] = n * cost[3];
        } else if (str1[n - 1] == str2[m - 1]) {
                dp[n][m] = editdist(str1, str2, n - 1, m - 1);
        } else {
                int p0 = INT_MAX, p1, p2, p3, p4;
                if (str1[n - 2] == str2[m - 1] && str1[n - 1] == str2[m - 2] && n >= 2 && m >= 2) {
                        p0 = cost[0] + editdist(str1, str2, n - 2, m - 2); //twiddle
                }
                p1 = cost[1] + editdist(str1, str2, n, m - 1); //insert
                p2 = cost[2] + editdist(str1, str2, n - 1, m - 1); //replace
                p3 = cost[3] + editdist(str1, str2, n - 1, m); //delete
                p4 = cost[4] + editdist(str1, str2, n - 1, m - 1); //copy 
                dp[n][m] = min(p0, min(p1, min(p2, min(p3, p4))));
        }
        return dp[n][m];
}
int main() {
        string s1, s2;
        cout << "Enter the 1st string : ";
        cin >> s1;
        cout << "Enter the 2nd string : ";
        cin >> s2;
        for (int i = 0; i <= s1.length(); i++) {
                for (int j = 0; j <= s2.length(); j++) {
                        dp[i][j] = -1;
                }
        }
        cout << "Enter the cost of : \n";
        cout << "Twiddle : ";
        cin >> cost[0];
        cout << "Insert : ";
        cin >> cost[1];
        cout << "Replace : ";
        cin >> cost[2];
        cout << "Delete : ";
        cin >> cost[3];
        cout << "Copy : ";
        cin >> cost[4];
        cout << "The minimum cost(top down): " << editdist(s1, s2, s1.length(), s2.length()) << endl;
        return 0;
}
>>>>>>> 4113b8d2c58f52cfdcecb384a4a40fea913e2ffe
