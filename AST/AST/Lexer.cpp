//
//  Lexer.cpp
//  AST
//
//  Created by Evelyn on 2020/2/3.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include "Lexer.hpp"

Token:: Token(token_type type, string value) {
    this->type = type;
    this->value = value;
}

Lexer:: Lexer() {
    this->num = 0;
}

Lexer:: Lexer(string text) {
    this->text = text;
    this->pos = 0;
    this->num = 0;
    this->current_char = this->text[0];
}

void Lexer:: error() {
    throw "Invalid lexicality!";
}

/**
  move `pos` pointer advance and set the `current_char` variable.
 */
void Lexer:: advance() {
    this->pos += 1;
    if (this->pos > this->text.length() - 1) {
        this->current_char = NULL;
    }
    else
        this->current_char = this->text[this->pos];
}

/**
  used in peek(), not moving the `pos` pointer ahead while calling next_digit().
 */
void Lexer:: retreat(Token token) {
    long len = token.value.length();
    int i;
    for(i = 0; i < len; i++) {
        this->pos -= 1;
        this->current_char = this->text[this->pos];
    }
}

void Lexer:: skip_blank() {
    while (this->pos < this->text.length()  && this->current_char == ' ') {
        this->advance();
    }
}

/**
 return a multi-integer digit. e.g. 123
 @return 123
 */
int Lexer:: next_digit() {
    string res;
    while (this->pos < this->text.length() && is_digit()) {
        res += this->current_char;
        this->advance();
    }
    return atoi(res.c_str());
}

bool Lexer:: is_digit() {
    if (this->current_char <= '9' && this->current_char >= '0') {
        return true;
    }
    return false;
}

Token Lexer:: get_next_token() {
    while (this->pos < this->text.length()) {
        
        if (this->current_char == ' ') {
            this->skip_blank();
            continue;
        }
        
        if (this->is_digit()) {
            return Token(NUMBER, std:: to_string(this->next_digit()));
        }
        
        
        if (this->current_char ==  '+') {
            this->advance();
            return Token(BINARYOP, "+");
        }
        
        if (this->current_char == '-') {
            this->advance();
            return Token(BINARYOP, "-");
        }
        
        this->error();
    }
    return Token(END, "NULL");
}

Token Lexer:: peek() {
    Token token = get_next_token();
    retreat(token);
    return token;
}

