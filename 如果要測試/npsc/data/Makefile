generate:
	mkdir -p secret
	g++ -W -Wall -Wextra -std=c++17 -O2 gen.cpp -o gen
	g++ -W -Wall -Wextra -std=c++17 -O2 ../submissions/accepted/ac.cpp -o sol
	ulimit -s unlimited && ./gen
	rm -rf gen sol
clean:
	rm -rf secret
