
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <infix_internal.h>

#include <stdlib.h>

Link *make_link(Obj *obj) {
	Link *link = calloc(sizeof(Link), 1);
	link->obj = obj;
	return link;
}

void free_link(Link *link) {
	if (link != NULL) {
		free_link(link->next);
		free_obj(link->obj);
		free(link);
	}
}
