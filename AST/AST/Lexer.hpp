//
//  Lexer.hpp
//  AST
//
//  Created by Evelyn on 2020/2/3.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

enum token_type {
    NUMBER,
    PLUS,
    MINUS,
    END
};

class Token {
public:
    token_type type;
    string value;
    
    Token() {};
    Token(token_type, string);
    
    void error();
};

///////////////////////////////////////////////
// Lexical analysis part.                    //
///////////////////////////////////////////////
class Lexer{
public:
    string text;
    // a pointer to input string `text`.
    int pos;
    char current_char;
    
    Lexer();
    Lexer(string text);
    void error();
    Token get_next_token();
    
private:
    void advance();
    void skip_whitespace();
    int integer();
};


#endif /* Lexer_hpp */
