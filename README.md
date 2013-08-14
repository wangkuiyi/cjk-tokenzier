CJK Tokenzier
=============

This is a simple unigram CJK tokenizer in C++.

## History

I took code from [Richard Boulton's project](https://github.com/rboulton/cjk-tokenizer), which in turn took code from [Yung-chung Lin's project](http://code.google.com/p/cjk-tokenizer).

Yun-chung's code depends on `unicode.h` and `libunicode.a`; however, we do not know how come these files.

Richard rewrote part of Yun-chung's code to decouple it from the `unicode` library, but use Unicode functions provided by [Xapian](http://xapian.org), an open source CJK search engine.

What I did is to extract the Unicode functions from Xapian so to make this CJK-tokenzier project self-dependent.

## Usage

You can simply checkout the source code and run `make` to build the cjk-tokenzier library.

You an also run a simple example by `make test`.  The source code of the example is at `test.cc`.
