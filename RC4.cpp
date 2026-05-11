#include <bits/stdc++.h>
#define int long long
#define db double
#define yes "YES\n"
#define no "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
const int N = 256 ; 
void solve(){
    
    //string key , plain_text ; cin >> key ; cin.ignore() ; getline(cin,plain_text) ; 
    string key , plain_text ; cin >> key >> plain_text ; 

    function<string(string p , string k)> RC4 =[&](string p , string k) -> string {
        vector<int> v(N , 0) ; 
        for(int i = 1 ; i < N ; ++i) v[i] = i ; 
        
        int ridx = 0 ; 
        int ks = (int)k.size() ; 
        for(int i = 0 ; i < N ; ++i) {
            ridx = (ridx + v[i] + k[i % ks]) % N ; 
            swap(v[i] , v[ridx]) ;  
        }
        
        int lidx = 0 ; 
        ridx = 0 ;
        int  ps = (int)p.size() ; 
        string res = p ;
        for(int i = 0 ; i < ps ; ++i) {
            lidx = (lidx + 1) % N ; 
            ridx = (ridx + v[lidx]) % N ; 
            swap(v[lidx] , v[ridx]) ; 
            int fidx = v[(v[lidx] + v[ridx]) % N] ;   
            res[i] = p[i] ^ fidx ; 
        }
        
        return res ;
    }; 


    string cipher_text = RC4(plain_text , key) ;
    cout << "Encrypted Text Is : \n" ; 
    for(auto c : cipher_text) cout << hex << setw(2) << setfill('0') << (int)c << " " ;
    cout << "\n" ; 
    cout << "\n" ; 

    string decrypted_text = RC4(cipher_text , key) ; 
    bool ok = false ; 
    decrypted_text == plain_text ? ok = true : ok = false ; 
    ok ? cout << "Decrypted Text Is : " << decrypted_text : cout << "There is an Issue" ; 
    cout << "\n" ;


}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int gas = 1;
    //cin >> gas; 
    while(gas--) solve();
    
    return pow(1-1, 2);
}