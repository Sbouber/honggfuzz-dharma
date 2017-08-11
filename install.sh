#!/bin/sh

apt-get install python2.7-dev clang-4.0 libbfd-dev ibunwind-dev libunwind8-dev libblocksruntime-dev
git clone https://github.com/google/honggfuzz.git tools/honggfuzz
git clone https://github.com/MozillaSecurity/dharma.git tools/dharma
cp -R tools/dharma/dharma/core .
cp -R tools/dharma/dharma/grammars .
cp tools/dharma/dharma/settings.py .
cp mangle.c tools/honggfuzz/
cd tools/honggfuzz
CC=clang-4.0 CXX=clang-4.0++ CFLAGS=-I/usr/include/python2.7 LDFLAGS=-lpython2.7 make