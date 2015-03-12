
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>
#include <stdio.h>

Obj *make_tobj(Operator op) {
	Obj *obj = calloc(sizeof(Obj), 1);
	obj->t = OP;
	obj->op = op;
	return obj;
}

Obj *make_iobj(int i) {
	Obj *obj = calloc(sizeof(Obj), 1);
	obj->t = INT;
	obj->i = i;
	return obj;
}

void free_obj(Obj *obj) { free(obj); }

void print_obj(Obj *obj) {
	if (obj == NULL) {
		printf("()");
	} else {
		if (obj->t == OP) {
			if (obj->op == ADD) {
				printf("+");
			} else if (obj->op == SUB) {
				printf("-");
			} else if (obj->op == MUL) {
				printf("*");
			} else if (obj->op == DIV) {
				printf("/");
			} else if (obj->op == LSHIFT) {
				printf("<<");
			} else if (obj->op == RSHIFT) {
				printf(">>");
			} else {
				// should never reach
				printf("?");
			}
		} else if (obj->t == INT) {
			printf("%d", obj->i);
		}
	}
}
