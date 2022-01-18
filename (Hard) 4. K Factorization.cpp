//https://www.hackerrank.com/challenges/k-factorization/problem?isFullScreen=true
//K Factorization
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kFactorization' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY A
 */

vector<int> kFactorization(int n, vector<int> A) {
    int s, temp, finish, r, t;
    vector<int> res, value;
    
    //Convert vector A to array arr
    s = A.size();
    int arr[s];
    for (int i=0; i<s; i++){
        arr[i]=A[i];
    }
    
    //Sorting arr value
    sort(arr, arr + sizeof arr / sizeof arr[0], greater<int>());
    
    //Searching for states
    temp=n;
    res.push_back(temp);
    do {
        finish=1;
        for (int i=t; i<s; i++){
            if (temp%arr[i]==0){
                temp=temp/arr[i];
                res.push_back(temp);
                finish=0;
                break;
            }
        }
        if (temp==1){
            finish=1;
        }
    }
    while (finish != 1);
    
    //Sorting result
    sort(res.begin(), res.end());
    
    //Output
    r = res.size();
    if (temp==1){
        for (int i=0; i<r; i++){
            value.push_back(res[i]);
        }
    } else {
        value.push_back(-1);
    }
    
    return value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(k);

    for (int i = 0; i < k; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    vector<int> result = kFactorization(n, A);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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
