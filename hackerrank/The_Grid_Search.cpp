//https://www.hackerrank.com/challenges/the-grid-search
//Junhua Chen

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
using namespace std;

int pos_substr(string l, string s, int start,int length){
    size_t result = l.substr(start,length).find(s);

    if ( result != std::string::npos){
       // cout << l.substr(start,length)<<" "<<s<<endl;
        return result;
    }else{
        return -1;
    }
}

void print_next(std::vector<string> v,int x,int y,int r,int c){
    for ( int i = 0; i < r ; i ++){
        cout << v[x+i].substr(y,c) << endl;
    }
    cout << endl<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N = 0;
    cin >> N;
    int R = 0, C = 0, r= 0, c= 0;
    for (int n = 0; n < N;n++){

    cin >> R >> C;
    vector<string> large(R,string(C, ' '));
    
    vector<vector<int> >map(R,vector<int>(C,0));
    string line;
    for ( int i = 0; i < R; i++){
        cin >> line;
        large[i] = line;
    }
    
    cin >> r >> c;
    vector<string> small(r,string(c, ' '));
    for ( int i = 0; i < r;i++){
        cin >> line;
        small[i] = line;
    }
    bool found = false;
    for (int i = 0 ; i+r <= R;i++){
        string l = large[i];

        for ( int  j = 0; j < C; j+=0){
                int count = 0;
                int pos = pos_substr(large[i],small[count],j,C-j);
                //cout <<i <<" "<<j <<" "<<pos <<endl;
                int start = pos;
                if ( pos == -1 ){
                    j ++;
                    continue;
                }else{
                    j = max(j+1,pos +1);
                }
                int k = 1;
                // cout <<"Pos: "<<pos <<" k "<<k<<endl;
                for( ; k < r;k++){
                    pos = pos_substr(large[i+k],small[k],start,C-start);
                    //cout <<"Pos: "<<pos <<" k "<<k<<endl;
                    if ( pos != 0){
                        break;
                    }
                }
               // cout <<" ===== "<<k <<endl;
                if(k == r){
                    found = true;
                    j = C+1;
                    i = C+1;
                }
        }
    }
    if(found){
        cout << "YES\n";
    }else{
        cout <<"NO\n";
    }
}
    return 0;
}
