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
    
    vector<Token> token_stream;
    
    Lexer();
    Lexer(string text);
    void error();
    
    // return the next token and consume it.
    Token get_next_token();
    // look ahead a token w/o consumption.
    Token peek();
    
private:
    // move pointer `pos` ahead.
    void advance();
    // move pointer `pos` backward.
    void retreat();
    void skip_blank();
    bool is_digit();
    int next_digit();
};


#endif /* Lexer_hpp */
