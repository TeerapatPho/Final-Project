compile: main.cpp
	 g++ main.cpp -o final

run: final
	 ./final

clean: final
	 rm final