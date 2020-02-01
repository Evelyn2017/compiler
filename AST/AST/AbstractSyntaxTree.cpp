//
//  AbstractSyntaxTree.cpp
//  AST
//
//  Created by Evelyn on 2020/2/1.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include <stdio.h>
using namespace std;

enum kind {NUMBER, PLUS, MUL};

class Expr {
    enum kind kind;
};

class Expr_NUMBER {
public:
    enum kind kind;
    int n;
    
    Expr_NUMBER(int n);
};

Expr_NUMBER:: Expr_NUMBER(int n) {
    this->kind = NUMBER;
    this->n = n;
}

class Expr_PLUS {
public:
    enum kind kind;
    Expr *left;
    Expr *right;
    
    Expr_PLUS(Expr *left, Expr *right);
};

Expr_PLUS:: Expr_PLUS(Expr *left, Expr *right) {
    this->kind = PLUS;
    this->left = left;
    this->right = right;
};

class Expr_MUL {
public:
    enum kind kind;
    Expr *left;
    Expr *right;
    
    Expr_MUL(Expr *left, Expr *right);
};

Expr_MUL:: Expr_MUL(Expr *left, Expr *right) {
    this->kind = MUL;
    this->left = left;
    this->right = right;
};

