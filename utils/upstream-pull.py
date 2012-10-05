#!/usr/bin/env python
# Copyright Dave Abrahams 2012. Distributed under the Boost
# Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# This script pulls and merges in all upstream changes on the master
# branch from both the llvm and clang mirror repositories.

import subprocess, os

def git(*args, **kw):
    return subprocess.check_call(['git']+args[0], *args[1:], **kw)

git(['pull', '--no-commit', 'http://github.com/llvm-mirror/llvm', 'master'])
clang = os.path.join(__file__, os.pardir, os.pardir, 'tools', 'clang')
git(['pull', '--commit', 'http://github.com/llvm-mirror/clang', 'master'], cwd=clang)
git(['add', clang])
git(['commit', '-m', 'upstream merge'])
