// testerForFileReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
    string line;
    ifstream file;

    file.open("../Data/races.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
			int pos =0;
			int size = line.size();
			cout << size << endl;
			string temp = line;
			for( int i =0 ; i <  10; i++){
				pos = temp.find_first_of('|' );
				cout << temp.substr(1,pos-1) << endl;
				temp = temp.substr(pos+1, size);
			}
		}
    }
    else {
        cout << "file not found" << endl;
    }

    file.close();
    return 0;
}




