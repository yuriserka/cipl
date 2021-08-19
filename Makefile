# https://pt.wikibooks.org/wiki/Programar_em_C/Makefiles
EXEC_NAME := tradutor
BUILD_DIR := build
SRC_DIR := src
DEP_DIR := $(BUILD_DIR)/.deps
OBJ_DIR := $(BUILD_DIR)/.objs

SRCS := $(shell find src -name '*.c')
MAKE_DIR = @mkdir -p $(@D)
DEL_FILES = $(RM) *~ $(OBJS) $(DEPS) $(EXEC)
EXEC := $(EXEC_NAME)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(SRCS:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
CXX := gcc
INCLUDES := -I"lib/"
CXXFLAGS := -std=gnu99
CFLAGS := $(INCLUDES) -g -Wall -pedantic -Wpedantic -Werror -lm -lfl

# $@  Nome da regra. 
# $<  Nome da primeira dependência 
# $^ Lista de dependências
# $? Lista de dependências mais recentes que a regra.
# $* Nome do arquivo sem sufixo

.PHONY: all clean format mem_check docs

all: clean runbison runflex $(EXEC)

runbison:
	@echo Running bison
	@bison --defines="lib/bison/grammar.h" --output="src/main.c" src/bison/math.y

runflex:
	@echo Running flex
	@flex $(SRC_DIR)/flex/math.l

$(EXEC): $(OBJS)
	@echo Generating executable $@
	@$(CXX) $^ $(CXXFLAGS) $(CFLAGS) -o $@

$(DEP_DIR)/%.d: $(SRC_DIR)/%.c
	@$(MAKE_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d
	@$(MAKE_DIR)
	@echo Compiling $<
	@$(CXX) -c $< $(DEPFLAGS) $(CXXFLAGS) $(CFLAGS) -o $@

$(DEPS):
include $(wildcard $(DEPS))

clean:
	@echo Deleting generated files  
	@$(DEL_FILES)
	@echo Deleting flex autogenerated files
	@$(RM) lib/flex/scanner.h
	@echo Deleting bison autogenerated files
	@$(RM) lib/bison/grammar.h
	@$(RM) src/main.c

format:
	@clang-format -style=google -dump-config > .clang-format
	@echo Formatting src/ and lib/
	@./formatter $(SRC_DIR) && ./formatter lib/
	@rm ./.clang-format

mem_check: all
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(EXEC) $(filename)

docs:
	doxygen ./Doxyfile

-include $(wildcard $(DEPS))