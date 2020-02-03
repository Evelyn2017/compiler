//
//  Parser.hpp
//  AST
//
//  Created by Evelyn on 2020/2/3.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "Lexer.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;

///////////////////////////////////////////////
// Parser part.                              //
///////////////////////////////////////////////
class Parser {
public:
    Lexer lexer;
    Token current_token;
    
    Parser() {};
    Parser(Lexer lexer, Token token);
    
    void error();
    
    Token peek();
    Token consume();
    
};

Parser:: Parser (Lexer lexer, Token token) {
    this->lexer = lexer;
    this->current_token = token;
}

void Parser:: error() {
    throw "Invalid syntax!";
}


#endif /* Parser_hpp */
