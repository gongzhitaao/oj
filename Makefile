CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11

src := "$(shell find . -name '*.cpp' -mmin -1 -printf '%T+\t%p\n' | sort | tail -1 | awk '{print $$2}')"

all : main

main :
ifneq ($(src),"")
	$(CXX) -o a.out $(CXXFLAGS) $(src)
endif

clean :
	rm -f a.out

.PHONY : all clean main
