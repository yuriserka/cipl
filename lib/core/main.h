#pragma once

#include "data-structures/context.h"

int cipl_main(int argc, char *argv[]);

void init_global_context(Context *global_ctx);

void print_all_contexts();

void print_ast();
