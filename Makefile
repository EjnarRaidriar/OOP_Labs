all: testForester testFisher testMiner

testForester:testForester.o
	g++ $< -o $@

testFisher:testFisher.o
	g++ $< -o $@

testMiner:testMiner.o
	g++ $< -o $@

testForester.o:testForester.cpp
	g++ -c -Wall -O0 $^

testFisher.o:testFisher.cpp
	g++ -c -Wall -O0 $^

testMiner.o:testMiner.cpp
	g++ -c -Wall -O0 $^

clean:
	rm *.o testForester testFisher testMiner	