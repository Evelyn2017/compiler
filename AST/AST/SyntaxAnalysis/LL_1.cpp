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
