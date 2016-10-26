#!/usr/bin/env pyrate

default_context.basepath_object_file = 'tmp'

use_toolchain('llvm', version >= 3.7, cpp_std = 'c++14',
	cpp_opts = '-Weverything -fno-rtti -Wno-c++98-compat-pedantic -Wno-padded -g -O3 -fsanitize=undefined -fsanitize=address',
	link_exe_opts = '-g -O3 -fsanitize=undefined -fsanitize=address')

executable('check.bin', [match('check*.cpp')])