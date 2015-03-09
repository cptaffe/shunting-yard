
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdio.h>

int infix(char *str) {
	State *state = make_state(str);
	void *func = &p_start;

	while (func != NULL) {
		func = ((void *(*)(State *)) func)(state);
	}

	print_tree(state->out);
	printf("\n");

	free_state(state);
	return 0;
}
