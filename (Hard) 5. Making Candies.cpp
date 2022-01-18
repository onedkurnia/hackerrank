#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumPasses' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER m
 *  2. LONG_INTEGER w
 *  3. LONG_INTEGER p
 *  4. LONG_INTEGER n
 */

#include<bits/stdc++.h>
using namespace std;

bool minimumPasses(long m, long w, long p, long n, long h) {
    long rem, rnds, res = m*w;
    
    if (m >= (n+w-1)/w){
        return true;
    }
    h--;
    
    if (h==0){
        return false;    
    }
     
    //while no 0 value
    while (1) {
        rem = n-res;
        rnds = (rem + m*w - 1) / (m*w);
        if (rnds<=h){
            return true;    
        } 
        if (res<p) {
            rem = p-res;
            rnds = (rem+m*w-1) / (m*w);
            h -= rnds;
            if (h<1){
                return false;      
            } 
            res += rnds*m*w;
        }
        res -= p;
        //Deciding to add machine or worker 
        if (m > w) {
            w++;
        } else {
            m++;
        }
    }
    return false;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long m = stol(first_multiple_input[0]);

    long w = stol(first_multiple_input[1]);

    long p = stol(first_multiple_input[2]);

    long n = stol(first_multiple_input[3]);

    //long result = minimumPasses(m, w, p, n); 
    
    long a = 1, b = 1000000000000;
    do {
        //Shifting 1 digit in binary
        long mid = (a + b) >> 1;
        if (minimumPasses(m, w, p, n, mid)) {
            b = mid;
        } else {
            a = mid + 1;
        }
    } while (a < b);
    
    fout << a << "\n";

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
