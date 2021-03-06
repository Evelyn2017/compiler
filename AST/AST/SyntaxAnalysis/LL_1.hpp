//
//  LL_1.hpp
//  AST
//
//  Created by Evelyn on 2020/2/2.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#ifndef LL_1_hpp
#define LL_1_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include "../Lexer.hpp"

#define max_size 100

using namespace std;

/**
 data structure of a production.
 "#": epsilon
 */
struct Production {
    char left;
    string right;
};

class LL1Analyzer {
protected:
    // number of productions in Grammer G.
    int N = 0;
    Production production[max_size];
    
    vector<char> terminal;
    vector<char> non_terminal;
    
    set<char> first_set[max_size];
    set<char> follow_set[max_size];
    set<char> *nullable_set;
    
    bool is_non_terminal(char c);
    
    void make_first_set(char S);
    void make_follow_set(char S);
    
    void make_nullable_set();
    
    int get_index_terminal(char t);
    int get_index_non_terminal(char n_t);
    
    
    
public:
    LL1Analyzer(int N) {};
    LL1Analyzer() {};
    
    void output_first_set();
    void output_follow_set();
    void crack_grammer(string g);
    vector<string> split(string str, char a);
    
};

#endif /* LL_1_hpp */
