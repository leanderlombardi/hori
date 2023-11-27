#include "include/parser.h"
#include "include/lexer.h"

parser_T *init_parser(lexer_T *lexer) {}

void parser_eat(parser_T *parser, int token_type) {}

AST_T parser_parse(parser_T *parser) {}

AST_T *parser_parse_statement(parser_T *parser) {}

