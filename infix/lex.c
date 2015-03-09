
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>
#include <stdio.h>

// Lexer functions.

char next(State *state) {
	char c = state->in[state->pos++];
	if (c == 0) {
		return EOF;
	} else {
		return c;
	}
}

void back(State *state, char c) {
	if (c != EOF) {
		state->pos--;
	}
}

char peek(State *state) {
	char c = next(state);
	back(state, c);
	return c;
}
