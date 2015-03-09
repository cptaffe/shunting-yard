
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>

State *make_state(char *input) {
	State *state = calloc(sizeof(State), 1);
	state->out = make_tree(NULL);
	state->in = input;
	return state;
};

void free_state(State *state) {
	free_tree(state->out);
	free_link(state->opstk);
	free(state);
}
