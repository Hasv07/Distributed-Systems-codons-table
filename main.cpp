#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
typedef vector<long long> vi;
typedef pair<long long,long long> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pai
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define loop(i, len) for (long long i = 0; i < len; ++i)
#define loopr(i, len) for (long long i = len; i >=0; --i)

#define LOCAL 0
char* codon_table[4][4][4] =
        {
                {
                        {"Phe", "Phe", "Leu", "Leu"},
                        {"Ser", "Ser", "Ser", "Ser"},
                        {"Tyr", "Tyr", "Stop", "Stop"},
                        {"Cys", "Cys", "Stop", "Trp"}
                },
                {
                        {"Leu", "Leu", "Leu", "Leu"},
                        {"Pro", "Pro", "Pro", "Pro"},
                        {"His", "His", "Gln", "Gln"},
                        {"Arg", "Arg", "Arg", "Arg"}
                },
                {
                        {"Ile", "Ile", "Ile", "Met"},
                        {"Thr", "Thr", "Thr", "Thr"},
                        {"Asn", "Asn", "Lys", "Lys"},
                        {"Ser", "Ser", "Arg", "Arg"}
                },
                {
                        {"Val", "Val", "Val", "Val"},
                        {"Ala", "Ala", "Ala", "Ala"},
                        {"Asp", "Asp", "Glu", "Glu"},
                        {"Gly", "Gly", "Gly", "Gly"}
                }
        };

string lines[1365];
map<char,int> m={{'t',0},{'c',1},{'a',2},{'g',3}};
map<string,int> codon;
string cod;
int main() {
    ifstream f;
    f.open("C:\\Users\\hassa\\CLionProjects\\untitled\\InputSeq.txt");
    ll n=0;
    double cnt=0;
    ll c=0;
    while(f.is_open()) {

        while (getline(f, lines[n]))n++;
        f.close();
    }
    double l1= clock();
    loop(i,1365)
    {
       loop(j,lines[i].size())
       {
           if(lines[i][j]=='g'||lines[i][j]=='t'||lines[i][j]=='a'||lines[i][j]=='c')
           {
               c++;
               cod+=lines[i][j];
               if(c==3)
               {
                   cnt++;
                   string x=codon_table[m[cod[0]]][m[cod[1]]][m[cod[2]]];
                   if(!codon.count(x))codon.insert({x,0});
                   codon[x]+=1;
                   c=0;
                   cod.clear();
               }
           }
       }

    }
    double l2= clock();
    double time=l2-l1;
    cout<<time/(1.0*(2800000000))<<endl;
    for(auto&t:codon)
    {
        cout<<t.first<<'\t'<<t.second<<'\t'<<(t.second/cnt*1.0)*100<<'\n';
    }
}