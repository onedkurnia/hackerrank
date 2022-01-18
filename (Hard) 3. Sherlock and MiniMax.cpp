//https://www.hackerrank.com/challenges/sherlock-and-minimax/copy-from/251615862?isFullScreen=true
//Sherlock and MiniMax

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sherlockAndMinimax' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER p
 *  3. INTEGER q
 */

int sherlockAndMinimax(vector<int> arr, int p, int q) {
    int diff, res, msize, asize, min, max;
    vector<int> m;
    
    //Moving vector arr to array a
    asize=arr.size();
    int a[asize];
    for (int i=0; i<asize; i++){
        a[i]=arr[i];
    }
    
    //Result when arr only consist of 1 element
    if (asize == 1){
        //Result = bigest difference with M
        if (abs(a[0]-p) >= abs(a[0]-q)){
            res=p;
        } else {
            res=q;
        }
    } else {
        //Sorting value in array a
        sort(a, a + sizeof a / sizeof a[0]);
        
        //Input boundaries in M
        m.push_back(p);
        m.push_back(q);
        
        //Selecting M
        for (int i=0; i<asize-1; i++){
            diff = a[i+1] - a[i];
            //Input as M when a[i] inside the boundaries
            if (p<=(a[i]+diff/2) && (a[i]+diff/2)<=q){
                m.push_back(a[i]+diff/2);    
            }
            //Input as M when a[i+1] inside the boundaries 
            if (p<=(a[i+1]-diff/2) && (a[i+1])<=q){
                m.push_back(a[i+1]-diff/2);
            }
        }
        msize = m.size();

        //Sorting value in array M
        sort(m.begin(), m.end());
        
        //Looking for the Min and Max value
        max = 0;
        for (int i=0; i<msize; i++){
            min = 1000000000;
            //Looking for the Min value of |a-m|
            for (int j=0; j<asize; j++)
                if (abs(a[j]-m[i]) < min){
                    min = abs(a[j]-m[i]);
                }
            //Looking for the Max value of Min
            if (min>max){
                max = min;
                res = m[i];
            }
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int p = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    int result = sherlockAndMinimax(arr, p, q);

    fout << result << "\n";

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
