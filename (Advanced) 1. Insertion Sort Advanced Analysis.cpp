//https://www.hackerrank.com/challenges/insertion-sort/problem?isFullScreen=true
//Insertion Sort Advanced Analysis

#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

unsigned long int insertionSort(vector<int>& arr, vector<int>& b, int l, int r) {
    unsigned long int res=0;
    if(r-l <= 1){
        return res;
    }
    
    int h, h1, h2, temp; 
    //median
    h = (l+r)/2;
    //first half limit
    h1 = h-1;
    //last half limit
    h2 = r-1;
    temp = h2;
    
    //repetitive function    
    res += insertionSort(b, arr, l, h)+insertionSort(b, arr, h, r);

    //Checking the range
    while (h1>=l && h2>=h) {
        //
        if(arr[h2] >= arr[h1]){
            b[temp--] = arr[h2--];    
        } else {
            //Counting total shifts
            res += h2-h+1;
            b[temp--] = arr[h1--];
        }
    } 
    
    while(h1 >= l){
        b[temp--] = arr[h1--];
    }
    
    while(h2 >= h){
        b[temp--] = arr[h2--];
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        vector<int> b(arr);
        
        long long result = insertionSort(arr, b, 0, n);

        fout << result << "\n";
    }

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

