all: testForester

testForester:testForester.o
	g++ $< -o $@

testForester.o:testForester.cpp
	g++ -c -Wall -O0 $^

clean:
	rm *.o testForester