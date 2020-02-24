//
//  LL_1.cpp
//  AST
//
//  Created by Evelyn on 2020/2/2.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include "LL_1.hpp"

bool LL1Analyzer:: is_non_terminal(char c) {
    if (c <= 'Z' && c >= 'A')
        return true;
    return false;
}



// TODO: generate first set.
void LL1Analyzer:: make_first_set(char S) {
    // init
    set<char> first[max_size] = {};
    
}


void LL1Analyzer:: make_follow_set(char S) {
   
}

void LL1Analyzer:: make_nullable_set() {
    for (int i = 0; i < this->N; i++) {
        if (production[i].right == "#")
            nullable_set->insert(production[i].left);
    }
}

int LL1Analyzer:: get_index_terminal(char t) {
    for (int i = 0; i < terminal.size(); i++) {
        if (t == terminal[i])
            return i;
    }
    return -1;
}

int LL1Analyzer:: get_index_non_terminal(char n_t) {
    for (int i = 0; i < non_terminal.size(); i++  ) {
        if (n_t == non_terminal[i])
            return i;
    }
    return -1;
}

void LL1Analyzer::  crack_grammer(string g) {
    set<char> non_t;
    set<char> t;
    
    string line;
    ifstream g_file(g);
    if (!g_file.is_open()) {
        cout<<"error openning file" <<endl;
        exit(1);
    }
    while (getline(g_file, line)) {
        vector<string> p = split(line, ':');
        // left part of a production is always a non_ternimal.
        char p_left = p[0].front();
        this->non_terminal.push_back(p_left);
        
        vector<string> p_right = split(p[1], ' ');
//        this->terminal.push_back(p_right);
        
    }
    
    set<char> :: iterator it;
    for (it = non_t.begin(); it != non_t.end(); it++) {
        cout<<*it<<" ";
    }
    
}

/**
 split production left and right.

 @param str S : XY
 @param a :
 @return [S, XY]
 */
vector<string> LL1Analyzer:: split(string str, char a) {
    vector<string> strvec;
    string:: size_type pos1, pos2;
    pos1 = 0;
    pos2 = str.find(a);
    while (string:: npos != pos2) {
        strvec.push_back(str.substr(pos1, pos2 - pos1));
        
        pos1 = pos2 + 1;
        pos2 = str.find(a, pos1);
    }
    
    strvec.push_back(str.substr(pos1));
    return strvec;
}

int main() {
    LL1Analyzer ll1;
    string filename = "g.txt";
    cout<<ll1.split("S:XY", ':')[1]<<endl;
}

