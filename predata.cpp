#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>

#define LEN 1000
char line[LEN];
using namespace std;

int main(int argc, char *argv[]) {
	//cout << argv[1] << " " << argv[2] << endl;
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		printf("file %s not found.", "USA.txt");
		exit(-1);
	}
	bool first = true;
	int os, ot, ow;
	ofstream mydata(argv[2]);
	while (fgets(line, LEN, f)) {
		char *token;
		if ('p' == line[0]) {
			std::strtok(line, " \n");
			std::strtok(NULL, " \n");
			token = std::strtok(NULL, " \n");
			int n = std::atoi(token);
			token = std::strtok(NULL, " \n");
			int m = std::atoi(token);
			mydata << n <<  ' '<<m<<endl; 
			printf("the graph has %d vertexes and %d edges.\n", n, m);
		} else if ('a' == line[0]) {
			std::strtok(line, " \n");
			token = std::strtok(NULL, " \n");
			int s = std::atoi(token);
			token = std::strtok(NULL, " \n");
			int t = std::atoi(token);
			token = std::strtok(NULL, " \n");
			int w = std::atoi(token);
			if (first) {
				os = s, ot = t, ow = w;
				mydata << os <<  ' '<<ot<<' '<<ow<<endl;
			} else {
				assert(os == t && ot == s && ow == w);
			}
			first = !first;
//			printf("<%d,%d,%d>\n", s, t, w);
		} 
		//else {
		//	printf("[%s]\n", line);
		//}
	}
	mydata.close();
	return 0;
	
}