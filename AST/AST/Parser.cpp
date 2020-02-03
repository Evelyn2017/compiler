//
//  Parser.cpp
//  AST
//
//  Created by Evelyn on 2020/2/3.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include "Parser.hpp"


Parser:: Parser (Lexer lexer, Token token) {
    this->lexer = lexer;
    this->current_token = token;
}

void Parser:: error() {
    throw "Invalid syntax!";
}
