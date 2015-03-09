
// Copyright (c) 2015 Connor Taffe. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <stdio.h>

#include <infix.h>

int main() {
	char *exp = "1+2*3-6";
	printf("'%s' => %d\n", exp, infix(exp));
	return 0;
}
