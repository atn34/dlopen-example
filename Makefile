.PHONY: all clean
all: app.so main.exe

%.o: %.cc
	g++ -c -fPIC -g $< -o $@ -fvisibility=hidden -fvisibility-inlines-hidden

app.so: app.o dep.o
	g++ -shared -o $@ $^ -fvisibility=hidden -fvisibility-inlines-hidden

main.exe: main.cc app.h
	g++ $< -ldl -g -o $@

clean:
	rm -f *.o *.so *.exe
