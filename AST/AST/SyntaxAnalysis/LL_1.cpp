//
//  LL_1.cpp
//  AST
//
//  Created by Evelyn on 2020/2/2.
//  Copyright © 2020 Evelyn. All rights reserved.
//
//  TODO: jugde if a grammer is an LL(1) grammer.
#include "LL_1.hpp"

bool LL1Analyzer:: is_non_terminal(char c) {
    if ((c >= '0' && c <= '9') || c == '*' || c == '+' || c == '(')
        return true;
    return false;
}

// TODO: generate first set.
void LL1Analyzer:: make_first_set(char S) {
    
}


void LL1Analyzer:: make_follow_set(char S) {
   
}

int LL1Analyzer:: get_index_terminal(char t) {
    return 0;
}

int LL1Analyzer:: get_index_non_terminal(char n_t) {
    return 0;
}
