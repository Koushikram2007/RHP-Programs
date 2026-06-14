
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int l1=str1.length(),l2=str2.length();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    int max=0;
    for (int i=1;i<=l1;i++){
        for (int j=1;j<=l2;j++){
            if (str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if (dp[i][j]>max){
                    max=dp[i][j];
                }
            }
            else{
                dp[i][j]=(dp[i][j-1]>dp[i-1][j])?dp[i][j-1]:dp[i-1][j];
            }
        }
    }
    cout<<max<<endl;
    return 0;
}
