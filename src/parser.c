#include "include/parser.h"
#include "include/AST.h"
#include "include/lexer.h"
#include "include/error.h"
#include <stdlib.h>
#include <string.h>

parser_T *init_parser(lexer_T *lexer) {
  parser_T *parser = calloc(1, sizeof(struct PARSER_STRUCT));
  parser->lexer = lexer;
  parser->cur_token = lexer_get_next_token(lexer);

  return parser;
}

void parser_eat(parser_T *parser, int token_type) {
  if (parser->cur_token->type == token_type)
    parser->cur_token = lexer_get_next_token(parser->lexer);
  else
    throw_parsing_error("Invalid token");
}

AST_T *parser_parse(parser_T *parser) {
  return parser_parse_statements(parser);
}

AST_T *parser_parse_statement(parser_T *parser) {
  switch (parser->cur_token->type) {
    case TOKEN_ID: return parser_parse_id(parser);
  }
}

AST_T *parser_parse_statements(parser_T *parser) {
  AST_T *compound = init_ast(AST_COMPOUND);
  compound->compound_value = calloc(1, sizeof(struct AST_STRUCT *));
  AST_T *ast_stmt = parser_parse_statement(parser);
  compound->compound_value[0] = ast_stmt;
  compound->compound_size++;

  while (parser->cur_token->type == TOKEN_SEMI) {
    parser_eat(parser, TOKEN_SEMI);

    AST_T *ast_stmt = parser_parse_statement(parser);
    compound->compound_size++;
    compound->compound_value = realloc(compound->compound_value, compound->compound_size * sizeof(struct AST_STRUCT *));
    compound->compound_value[compound->compound_size - 1] = ast_stmt;
  } 

  return compound;
}

AST_T *parser_parse_expr(parser_T *parser) {}

AST_T *parser_parse_term(parser_T *parser) {}

AST_T *parser_parse_factor(parser_T *parser) {}

AST_T *parser_parse_string(parser_T *parser) {}

AST_T *parser_parse_variable(parser_T *parser) {
  char *token_value = parser->cur_token->value;
  parser_eat(parser, TOKEN_ID); // variable name or function name

  if (parser->cur_token->type == TOKEN_LPAREN)
    return parser_parse_function_call(parser);
  
  AST_T *ast_variable = init_ast(AST_VARIABLE);
}

AST_T *parser_parse_function_call(parser_T *parser) {}

AST_T *parser_parse_id(parser_T *parser) {
  if (strcmp(parser->cur_token->value, "let") == 0)
    return parser_parse_variable_definition(parser);
  else
    return parser_parse_variable(parser);
}

AST_T *parser_parse_variable_definition(parser_T *parser) {
  parser_eat(parser, TOKEN_ID); // let
  char *variable_definition_variable_name = parser->cur_token->value;
  parser_eat(parser, TOKEN_ID); // variable name
  parser_eat(parser, TOKEN_EQUAL);
  AST_T *variable_definition_value = parser_parse_expr(parser);
  
  AST_T *variable_definition = init_ast(AST_VARIABLE_DEFINITION);
  variable_definition->variable_definition_variable_name = variable_definition_variable_name;
  variable_definition->variable_definition_value = variable_definition_value;

  return variable_definition;
}

