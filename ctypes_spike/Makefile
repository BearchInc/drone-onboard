all: clean compile lib

clean:
	-rm *.o

compile:
	g++ -c -fPIC *.cpp -Iincludes

lib:
	g++ *.o -shared -o libspike.so
