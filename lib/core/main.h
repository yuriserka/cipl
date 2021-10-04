#pragma once

#include "data-structures/context.h"

int cipl_main(int argc, char *argv[]);
int cipl_syntax();
int cipl_semantic();
int cipl_intermediate_code();

void print_all_contexts();
void main_ast_pretty();
void main_context_pretty();
