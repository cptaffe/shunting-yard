
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>
#include <stdio.h>

Tree *make_tree(Obj *obj) {
	Tree *t = calloc(sizeof(Tree), 1);
	t->obj = obj;
	return t;
}

void free_tree(Tree *tree) {
	if (tree != NULL) {

		// recurse to free children
		free_tree(tree->child[0]);
		free_tree(tree->child[1]);

		// free object data.
		free_obj(tree->obj);

		// free tree structure
		free(tree);
	}
}

void tree_insert(Tree **tree, Obj *obj) {
	Tree *new = calloc(sizeof(Tree), 1);

	if ((*tree)->child[0] == NULL) {
		new = make_tree(obj);
		new->child[0] = *tree;
	} else if ((*tree)->child[1] == NULL) {
		new = make_tree(obj);
		(*tree)->child[1] = new;
		new = *tree;
	} else {
		new = make_tree(obj);
		new->child[0] = *tree;
	}

	*tree = new;
}

void print_tree(Tree *tree) {
	if (tree == NULL) {
		printf("()");
	} else {
		print_obj(tree->obj);
		if (tree->child[0] != 0 || tree->child[1] != 0) {
			printf("{");
			print_tree(tree->child[0]);
			printf(", ");
			print_tree(tree->child[1]);
			printf("}");
		}
	}
}
