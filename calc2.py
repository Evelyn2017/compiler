# Token types

INTEGER, PLUS, MINUS, MUL, DIV, EOF = (
    'INTEGER', 'PLUS', 'MINUS', 'MUL', 'DIV', 'EOF')


class Token(object):

    def __init__(self, type, value):
        self.type = type
        # token value: non-negative integer value, '+', '-', '*', '/', or None.
        self.value = value

    def __str__(self):
        return "Token <{type}, {value}>".format(type=self.type,
                                                value=repr(self.value))

    def __repr__(self):
        return self.__str__()


class Tokenizer(object):

    def __init__(self, text):
        self.text = text

        self.pos = 0

        self.current_char = self.text[self.pos]

    def error(self):
        raise Exception("Invalid syntax!")

    def advance(self):
        self.pos += 1
        if self.pos > len(self.text) - 1:
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

    def skip_whitespace(self):
        if self.current_char is not None and self.current_char.isspace():
            self.advance()

    def integer(self):
        result = ''
        while self.current_char is not None and self.current_char.isdigit():
            result += self.current_char
            self.advance()

        return int(result)

    def get_next_token(self):
        while self.current_char is not None:
            if self.current_char.isspace():
                self.skip_whitespace()
                continue

            if self.current_char.isdigit():
                return Token(INTEGER, self.integer())

            if self.current_char == '+':
                self.advance()
                return Token(PLUS, '+')

            if self.current_char == '-':
                self.advance()
                return Token(MINUS, '-')

            if self.current_char == '*':
                self.advance()
                return Token(MUL, '*')

            if self.current_char == '/':
                self.advance()
                return Token(DIV, '/')

            self.error()

        return Token(EOF, None)


class Itprt(object):

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer
        self.current_token = self.tokenizer.get_next_token()

    def error(self):
        raise Exception("Invalid syntax!")

    def eat(self, token_type):
        if self.current_token.type == token_type:
            self.current_token = self.tokenizer.get_next_token()
        else:
            self.error()

    def factor(self):
        # factor: INTEGER
        token = self.current_token
        self.eat(INTEGER)
        return token.value

    def term(self):
        # term: factor((MUL | DIV) factor)*
        result = self.factor()

        while self.current_token.type in (MUL, DIV):
            token = self.current_token
            if token.type == MUL:
                self.eat(MUL)
                result = result * self.factor()
            if token.type == DIV:
                try:
                    self.eat(DIV)
                    div_factor = self.factor()
                    result = result / div_factor
                except Exception:
                    raise Exception("can not divided by zero!")


        return result

    def expr(self):
        """Arithmetic expression parser / interpreter
        14 + 2 * 3 - 6 / 2
        17

        expr  : term((PLUS | MINUS) term)*
        term  : factor((MUL | DIV) factor)*
        factor: INTEGER
        """
        result = self.term()

        while self.current_token.type in (PLUS, MINUS):
            token = self.current_token
            if token.type == PLUS:
                self.eat(PLUS)
                result = result + self.term()
            if token.type == MINUS:
                self.eat(MINUS)
                result = result - self.term()

        return result


def main():
    while True:
        try:
            text = input('calc> ')
        except EOFError:
            break
        if not text:
            continue
        tokenizer = Tokenizer(text)
        itprt = Itprt(tokenizer)
        result = itprt.expr()
        print(result)


if __name__ == '__main__':
    # main()
    text = "12 + 2 * 3"
    t = Tokenizer(text)
    print(t.integer())
    print(t.get_next_token())
    print(t.get_next_token())
    print(t.get_next_token())
    main()
