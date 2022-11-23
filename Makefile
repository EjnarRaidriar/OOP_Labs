all: testWorker

testWorker:testWorker.o
	g++ $< -o $@

testWorker.o:testWorker.cpp
	g++ -c -O0 $^

clean:
	rm *.o testWorker