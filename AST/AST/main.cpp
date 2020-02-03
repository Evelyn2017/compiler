//
//  main.cpp
//  AST
//
//  Created by Evelyn on 2020/2/1.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include "Lexer.hpp"
#include "Parser.hpp"
#include <iostream>
using namespace std;

std:: ostream& operator<< (std:: ostream &strm, const Token& token) {
    return strm << "Token <" <<  token.type << ", " << token.value << ">" << endl;
}

int main(int argc, const char * argv[]) {
    string t = "1+ 2";
    Lexer x = Lexer(t);
    cout<< x.get_next_token() <<endl;
    cout<<x.get_next_token()<<endl;
    cout<<x.get_next_token()<<endl;
    
    return 0;
}
