compile: main.cpp
	 g++ Board.cpp Game.cpp Option.cpp Place.cpp Player.cpp main.cpp -o final

run: final
	 ./final

clean: final
	 rm final