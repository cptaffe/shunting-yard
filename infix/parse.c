
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

static int whitespace(char c);
static int isop(char *str);

static int isop(char *str) {
	int i, s = 0;
	char *ops[] = {
		"+",
		"-",
		"*",
		"/",
		"<<",
		">>",
	};

	for (i = 0; i < (sizeof(ops) / sizeof(char *)); i++) {
		s |= (strcmp(ops[i], str) == 0) ? 1 : 0;
	}

	return s;
}

static int whitespace(char c) {
	return (c == ' ' || c == '\t' || c == '\n') ? 1 : 0;
}

void *p_op(State *state) {
	char c, str[100] = {0};
	int i;
	Operator op;

	for (i = 0; i < ((sizeof(str) / sizeof(char)) - 1)
		&& (c = next(state)) != EOF
		&& !isdigit(c)
		&& !whitespace(c); i++) {
		str[i++] = c;
	}

	back(state, c);

	// get rid of whitespace
	while ((c = peek(state)) != EOF && whitespace(c)) {
		next(state);
	}

	if (isop(str) == 0) {
		return NULL;
	} else {
		if (strcmp(str, "+") == 0) {
			op = ADD;
		} else if (strcmp(str, "-") == 0) {
			op = SUB;
		} else if (strcmp(str, "*") == 0) {
			op = MUL;
		} else if (strcmp(str, "/") == 0) {
			op = DIV;
		} else if (strcmp(str, "<<") == 0) {
			op = LSHIFT;
		} else if (strcmp(str, ">>") == 0) {
			op = RSHIFT;
		} else {
			// should never get here
			return NULL;
		}

		tree_insert(&state->out, make_tobj(op));
	}

	return &p_num;
}

void *p_num(State *state) {
	char c, str[100] = {0};
	int i;

	for (i = 0; i < ((sizeof(str) / sizeof(char)) - 1)
		&& (c = next(state)) != EOF
		&& isdigit(c); i++) {
		str[i++] = c;
	}

	back(state, c);

	// get rid of whitespace
	while ((c = peek(state)) != EOF && whitespace(c)) {
		next(state);
	}

	tree_insert(&state->out, make_iobj(strtol(str, NULL, 10)));

	return &p_op;
}

void *p_start(State *state) {
	char c = peek(state);

	if (isdigit(c)) {
		return &p_num;
	} else {
		// must start with number.
		return NULL;
	}
}
