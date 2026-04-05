complie: main.cpp
	g++ main.cpp -o BST
run: BST
	./BST
test: BST
	./BST 5 2 1 3 8 7 9
