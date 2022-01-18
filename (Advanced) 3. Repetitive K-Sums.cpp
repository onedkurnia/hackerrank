//https://www.hackerrank.com/challenges/repeat-k-sums/problem?isFullScreen=true
//Repetitive K-Sums

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int sum, finish, t, n, k;
long long s, a[100000];
map <long long, int> temp;

void dfs(int now, int c, int b) {
    //Counting number of recursive
    if (c==now+1 || b==0) {
        sum++;
        return;
    }

    //recursive dfs
    for (int i=0; i<=b; i++){
        dfs(now+1, c, b-i);    
    }
}

void dfsdfs(int now, long long num, int b) {
    //Renew num value
    if (now==0){
        num += b*a[0];  
    }

    //Erase temp[num]
    if (b==0 || now==0) {
        temp[num]--;
        if (temp[num]==0){
            temp.erase(num);
        }
        return;
    }

    //recursive dfsdfs
    for (int i=0; i<=b; i++){
        dfsdfs(now-1, num+i*a[now], b-i);   
    }    
}

int main() {  
    //Input T
    cin >> t;
    
    //Looping Test Case for T
    finish=t;
    do {
        //Input N and K
        cin >> n >> k;
        sum = 0;
        dfs(0, n, k);
        
        //Input Si
        for (int i=0; i<sum; i++) {
            cin >> s;
            temp[s]++;
        }

        for (int i=0; i<n; i++) {
            //Taking first value from map temp
            long long now = temp.begin()->first;
            //result for a[0]
            if (i==0) {
                a[i] = now/k;
                temp[now]--;
                if (temp[now] == 0){
                    temp.erase(now);    
                } 
            } else {
                //result for a[i]
                a[i] = now - a[0]*(k-1);

                for (int j=1; j<=k; j++){
                    dfsdfs(i-1, a[i]*j, k-j);    
                }
            }
        }

        //Output
        for (int i=0; i<n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        finish--;
    } while (finish != 0);

    return 0;
}
