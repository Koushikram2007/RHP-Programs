#include <iostream>
#include <vector>
using namespace std;

void solve(){
    string a,b; cin>>a>>b;
    int R=a.length(),C=b.length();  
    vector<int> pa(R+1,0);
    vector<int> pb(C+1,0);
    for(int i=0;i<R;i++){
        pa[i]=a[i]-'0';
    }
    for(int i=0;i<C;i++){
        pb[i]=b[i]-'0';
    }
    vector<vector<int>> dp(R+1,vector<int>(C+1,0));
    for (int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if ((pa[i-1]+pa[i])%10==(pb[j-1]+pb[j])%10){
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if (dp[R][C]==0){
        cout<<-1<<endl;
    } else {
        cout<<dp[R][C]<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=0;
    cin>>tc;
    while(tc--){
        solve();
    }
}