//https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
//Matrix Layer Rotation

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    // Row
    int m = matrix.size(); 
    // Column
    int n = matrix[0].size();
    // Number of rotation group
    int k = min(m,n)/2; 
    int tmp, res[m][n];
            
    //replacing matrix to res        
    for(int i = 0; i < m; i++) {
        for(int j = 0; j< n; j++) {
            res[i][j]=matrix[i][j];
        }
    }
    
    //Rotation per Group
    for (int a=0; a<k; a++){
        //Rotate each group (modulo of the same repetition)
        for (int i=0; i<r%(2*((m-1-(2*a))+(n-1-(2*a)))); i++){
            //saving res[0][0] value 
            tmp=res[a][a];
            //Upper diagonal movement
            for (int j=a; j<n-(a+1); j++){
                res[a][j]=res[a][j+1];
            }
            //Right vertical movement
            for (int j=a; j<m-(a+1); j++){
                res[j][n-(a+1)]=res[j+1][n-(a+1)];
            }
            //Lower diagonal movement
            for (int j=n-(a+1); j>a; j--){
                res[m-(a+1)][j]=res[m-(a+1)][j-1];
            }
            //Left vertical movement
            for (int j=m-(a+1); j>a; j--){
                res[j][a]=res[j-1][a];
            }
            //complete the last part
            res[a+1][a]=tmp;
        } 
    }
    
    //Writing output
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


