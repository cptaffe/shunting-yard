# Copyright (c) 2015 Connor Taffe. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
	'targets': [
		{
			'target_name': 'libinfix',
			'type': 'static_library',
			'dependencies': [],
			'sources': [
				'infix/infix.h',
				'infix/infix.c',
			]
		},
		{
			'target_name': 'infix',
			'type': 'executable',
			'dependencies': [
				'libinfix',
			],
			'defines': [],
			'include_dirs': [
				'infix',
			],
			'sources': [
				'infix/libinfix.a',
				'main.c',
			],
		},
	],
}
