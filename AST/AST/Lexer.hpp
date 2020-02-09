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
#include <vector>
using namespace std;

enum token_type {
    NUMBER,
    UNARYOP,
    BINARYOP,
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
    int num;
    
    Lexer();
    Lexer(string text);
    void error();
    vector<Token> tokenizer();
    int token_num();
    
private:
    void advance();
    void skip_whitespace();
    int next_digit();
    Token get_next_token();
};


#endif /* Lexer_hpp */
