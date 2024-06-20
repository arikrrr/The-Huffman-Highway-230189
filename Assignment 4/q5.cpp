using namespace std;  
#include <string>
#include <iostream>

string smallestRotation(string S) {
    int n = S.size();
    string T = S + S;
    string min= T.substr(0, n);

    for (int i = 1; i < n; ++i) {
        string curr = T.substr(i, n);
        if (curr < min) {
            min = curr;
        }
    }
    return min;
}

int main(){
    string s;
    cin >> s;
    cout << smallestRotation(s);
    return 0;
}