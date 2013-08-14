CPP = g++
CPP_FLAGS = -Wall -L/usr/local/lib
MODULE = cjk-tokenizer

all: build

build: libcjk-tokenizer.a

cjk-hanconvert.o:
	$(CPP) $(CPP_FLAGS) -c cjk-hanconvert.cc

cjk-tokenizer.o:
	$(CPP) $(CPP_FLAGS) -c cjk-tokenizer.cc

unicode.o:
	$(CPP) $(CPP_FLAGS) -c unicode.cc

libcjk-tokenizer.a: unicode.o cjk-tokenizer.o cjk-hanconvert.o
	ar crv $@ unicode.o cjk-tokenizer.o cjk-hanconvert.o
	ranlib $@

test: libcjk-tokenizer.a test.cc
	$(CPP) $(CPP_FLAGS) -o $@ $@.cc -L. -lcjk-tokenizer
	./$@

clean:
	rm -rf *.o *~ *.a test
