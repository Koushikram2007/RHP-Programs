/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const int diff[8][2]={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
    int R,C;
    cin>>R>>C;
    vector<vector<int>> arr(R,vector<int>(C,0));
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    int max=0;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            int sum=0;
            for (int k=0;k<8;k++){
                int ar=i+diff[k][0],ac=j+diff[k][1];
                if (ar>=0 && ac>=0 && ar<R && ac<C){
                    sum+=arr[ar][ac];
                }
            }
            if (sum>max){
                max=sum;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}