//https:www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem?isFullScreen=true
//Floyd : City of Blinding Lights

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, u, v, w, s, q, q1, q2;
    vector<vector<int>> vec;
    
    //Input n and m    
    cin >> n >> m;
    
    //Resizez Vector
    vec.resize((n+1), vector<int>((n+1), -1));
    s = vec.size();

    //initiate 0 value
    for (int i=0; i<s; i++){
        vec[i][i] = 0;  
    }

    //Input u, v and w
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        vec[u][v] = w;
    }
    
    //Connection Loop
    for (int k=0; k<s; k++){
        //Vertical Loop
        for (int i=0; i<s; i++){
            //Diagonal Loop
            for (int j=0; j<s; j++){
                //Check if there is a path
                if (vec[i][k] !=-1 && vec[k][j] !=-1){
                    //change value if there is a shorter path
                    if (vec[i][j] == -1 || vec[i][j] > vec[i][k] + vec[k][j]){
                        vec[i][j] = vec[i][k] + vec[k][j];
                    }  
                }
            }
        }    
    }
    
    cin >> q;
    //Print output
    for (int i=0; i<q; i++){
        cin>>q1>>q2;
        cout<<vec[q1][q2]<<endl;
    }

  return 0;
}
