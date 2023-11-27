#include <stdio.h>
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"

int main(int argc, char **argv) {
  lexer_T *lexer = init_lexer("let name = \"john doe\";\nprint(name);\n");

  parser_T *parser = init_parser(lexer);
  AST_T *root = parser_parse(parser);

  printf("%d\n", root->type);

  return 0;
}

