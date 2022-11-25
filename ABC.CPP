#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
string a,b,c;
void input(){
    FastIO;
    freopen("ABC.INP","r",stdin);
    freopen("ABC.OUT","w",stdout);
    cin >> a >> b >> c;
}
string bignum_add(string a, string b){
    string ans = "";
    while(a.size() != b.size())
        (a.size() > b.size())
            ? b = '0' + b
            : a = '0' + a;
    int cr = 0;
    for(int i=a.size()-1; i>=0; i--){
        int t = a[i] - (int)'0' + b[i] - (int)'0' + cr;
        cr = t / 10;
        t %= 10;
        ans = (char)(t+(int)'0') + ans;
    }
    return ((cr == 0) ? ans : "1"+ans);
}
string bignum_sub(string a, string b){
    string ans = "";
    int br = 0;
    while(a.size() != b.size())
        (a.size() > b.size())
            ? b = '0' + b
            : a = '0' + a;
    for(int i=a.size()-1; i>=0; i--){
        int t = a[i] - b[i] - br;
        if(t < 0){
            t += 10;
            br = 1;
        }else br =0;
        ans= (char)(t%10+(int)'0') + ans;
    }
    while(ans.size() > 1 && ans[0] == '0') ans.erase(0,1);
    return ans;
}
string bignum_div(string a, int b){
    string ans = "";
    int idx = 0;
    int temp = a[idx] - '0';
    while (temp < b)
        temp = temp * 10 + (a[++idx] - '0');
    while (a.size() > idx) {
        ans += (temp / b) + '0';
        temp = (temp % b) * 10 + a[++idx] - '0';
    }
    return ((ans.size() == 0) ? "0" : ans);
}
void sol(){
    string tong=bignum_div(bignum_add(bignum_add(a,b),c),2);
    cout << bignum_sub(tong,b) << ' ';
    cout << bignum_sub(tong,c) << ' ';
    cout << bignum_sub(tong,a);
}
int32_t main(){
    input();
    sol();
}