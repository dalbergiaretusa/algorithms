#include <bits/stdc++.h>
#define MAXN (int)1e6

using namespace std;
int pi[MAXN+7];

void KMP(string x) {
  int q=0;
  for(int i=2; i<x.length(); i++) {
    while(q>0 && x[q+1]!=x[i]) {
      q=pi[q];
    }
    if(x[q+1]==x[i]) {
      q++;
    }
    pi[i]=q;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  string pattern, word;
  cin >> pattern >> word;
  word = pattern + "#" + word;
  KMP(word);
  for(int i=0; i<word.length(); i++) {
    cout << pi[i] << " ";
  }
}
