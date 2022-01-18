//https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem?isFullScreen=true
//The Longest Increasing Subsequence

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'longestIncreasingSubsequence' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
int longestIncreasingSubsequence(vector<int> arr) {
    int ub, res, n=arr.size();
    int temp[n];
    vector<int> a;
    
    //input temp as arr
    for (int i=0; i<n; i++){
        temp[i]=arr[i];    
    }
    
    a.push_back(temp[0]);
    for(int i=1; i<n; i++) {
        //Searching temp[i] position
        ub = (upper_bound(a.begin(), a.end(), temp[i]) - a.begin());
        //If temp[i] on last position
        if(ub == a.size()) {
            //Check if the value is increasing 
            if(temp[i] > a[a.size()-1]) {
                a.push_back(temp[i]);
            }
        } else {
            //Check if temp[i] on first position 
            if(ub == 0) {
                a[0] = temp[i];
            }
            //Check if the value is increasing  
            if(temp[i] > a[ub-1]){
                a[ub] = temp[i];
            }
        }
    }
    
    res=a.size();
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

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
