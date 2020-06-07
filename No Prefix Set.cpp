  #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* children[10];
    bool isEndOfWord;
};

TrieNode* getNode(){
    TrieNode* node=new TrieNode;
    for(int i=0;i<10;i++){
        node->children[i]=NULL;
    }
    node->isEndOfWord=false;
    return node;
}

bool searchAndFind(string s, TrieNode* node){
    TrieNode *n = node;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(n->children[index]==NULL){
            n->children[index]=getNode();
        }else{
            if(n->children[index]->isEndOfWord || i==s.length()-1) return true;
        }
        n=n->children[index];
    }
    n->isEndOfWord=true;
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    unordered_set<string> st;
    TrieNode *root = getNode();
    bool f=true;
    while(t--){
        string s;
        cin>>s;
        if(f){
            if(searchAndFind(s, root)){
                cout<<"BAD SET"<<"\n";
                cout<<s<<"\n";
                f=false;
            }
        }
    }
    if(f) cout<<"GOOD SET"<<"\n";
    return 0;
}
