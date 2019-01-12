CXX=g++
SRC=source/hello.cc
EXE=main

$(EXE): libhello.so
	$(CXX) -o $@ -l $< -Iinclude

libhello.so: hello.o
	$(CXX) -shared -o $@ $^ 

hello.o: $(SRC) include/hello.h
	$(CXX) -fpic -o $@ -c $< -Iinclude
