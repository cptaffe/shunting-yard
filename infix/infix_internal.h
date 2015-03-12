
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef INFIX_INTERNAL_H_
#define INFIX_INTERNAL_H_

#include <infix.h>

#include <stdint.h>

typedef enum {
	OP,
	INT,
	FLOAT,
} Type;

typedef enum {
	RPAREN, // (
	LPAREN, // )
	MUL,    // *
	DIV,    // /
	ADD,    // +
	SUB,    // -
	RSHIFT, // >>
	LSHIFT, // <<
} Operator;

typedef struct {
	Type t;
	union {
		Operator op;
		int i;
		float f;
	};
} Obj;

Obj *make_tobj(Operator op);
Obj *make_iobj(int i);
void free_obj(Obj *obj);
void print_obj(Obj *obj);

// Linked List
typedef struct Link {
	Obj *obj;
	struct Link *next;
} Link;

Link *make_link(Obj *obj);
void free_link(Link *link);

// Binary Tree
typedef struct Tree {
	Obj *obj;
	struct Tree *child[2];
} Tree;

Tree *make_tree(Obj *obj);
void free_tree(Tree *tree);
void tree_insert(Tree **tree, Obj *obj);
void print_tree(Tree *tree);

typedef struct {
	char *in;
	int pos;     // current position
	Link *opstk; // operator stack
	Link *last;
	Tree *out; // binary tree output.
} State;

State *make_state(char *input);
void free_state(State *state);

// lexer functions
char next(State *state);
void back(State *state, char c);
char peek(State *state);

// parser functions
void *p_start(State *state);
void *p_op(State *state);
void *p_num(State *state);

#endif // INFIX_H_
