//https://www.hackerrank.com/challenges/two-strings
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    cin >> T;
    for(int t = 0 ; t < T ; t++){
        //cout << t<<endl;
        string a;
        string b;
        cin >> a >> b;
        std::vector<bool> f(26,false);
        bool found = 0;
        for(int i = 0 ; i < a.length();i++){
            f[a[i]-97] = true;
        }
        for(int i = 0 ; i < b.length();i++){
            if(f[b[i]-97]){
                cout <<"YES\n";
                found = 1;
                i = b.length() +1;
            }
        }
        if (!found){
            cout <<"NO\n";
        }

    }
    return 0;
}
