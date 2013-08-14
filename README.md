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

The source code of a simple example is at `test.cc`.  You an also run it by `make test`.  This should generate outputs like follows:

     [~/Projects/cjk-tokenzier]
     wangyi@localhost:cjk-tokenzier$make test
     g++ -Wall -L/usr/local/lib -c unicode.cc
     g++ -Wall -L/usr/local/lib -c cjk-tokenizer.cc
     g++ -Wall -L/usr/local/lib -c cjk-hanconvert.cc
     ar crv libcjk-tokenizer.a unicode.o cjk-tokenizer.o cjk-hanconvert.o
     a - unicode.o
     a - cjk-tokenizer.o
     a - cjk-hanconvert.o
     ranlib libcjk-tokenizer.a
     g++ -Wall -L/usr/local/lib -o test test.cc -L. -lcjk-tokenizer
     ./test
     Original string: 美女遊戲等你挑戰周蕙最新鈴搶先下載茄子醬耍可愛一流华沙是波兰的首都，也是其最大的城市。납치 여중생 공포에 떠는데'…경찰 200m 거리 25분만에 출동寛永通宝の一。京都方広寺の大仏をこわして1668年（寛文8）から鋳造した銅銭。ㄅㄆㄇㄈㄉㄊㄋㄌㄧㄨㄩGiant Microwave Turns Plastic Back to Oil
     Tokenized result: [美] [女] [遊] [戲] [等] [你] [挑] [戰] [周] [蕙] [最] [新] [鈴] [搶] [先] [下] [載] [茄] [子] [醬] [耍] [可] [愛] [一] [流] [华] [沙] [是] [波] [兰] [的] [首] [都] [，] [也] [是] [其] [最] [大] [的] [城] [市] [。] [납] [치] [여] [중] [생] [공] [포] [에] [떠] [는] [데] ['…] [찰] [200m] [거] [리] [25] [만] [에] [출] [동] [寛] [永] [通] [宝] [の] [一] [。] [京] [都] [方] [広] [寺] [の] [大] [仏] [を] [こ] [わ] [し] [て] [1668] [（] [寛] [文] [8] [か] [ら] [鋳] [造] [し] [た] [銅] [銭] [。] [ㄅ] [ㄆ] [ㄇ] [ㄈ] [ㄉ] [ㄊ] [ㄋ] [ㄌ] [ㄧ] [ㄨ] [ㄩ] [Giant] [Microwave] [Turns] [Plastic] [Back] [to] [Oil]
