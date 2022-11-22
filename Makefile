all: testWorker

testWorker:testWorker.o Forester.h
	g++ $< -o $@

testWorker.o:testWorker.cpp Forester.h
	g++ -c $^

clean:
	rm *.o testWorker