all:
	g++ main.cpp forms.cpp tree.cpp Services_BST.cpp Provider_Directory.cpp terminal.cpp -g -Wall -o chocan
	g++ main_UnitTest.cpp terminal_UnitTest.cpp forms.cpp tree.cpp Services_BST.cpp Provider_Directory.cpp terminal.cpp -g -Wall -o test
