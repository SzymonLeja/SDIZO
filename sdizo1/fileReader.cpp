#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
//void readFile()
//{
//    std::ifstream infile("data.txt");
//    std::string line;
//    bool trus=true;
//    int *tab;
//    int i=0;
//    while (std::getline(infile, line))
//    {
//        std::istringstream iss(line);
//        int a;
//        if (!(iss >> a)) { break; } // error
//
//        if(!trus)
//        {
//            tab[i]=a;
//            i++;
//        }
//        else
//        {
//            trus=false;
//            tab= new int[a];
//        }
//
//    }
//    for( int j=0; j<i; j++)
//    {
//        std::cout << tab[j] << std::endl;
//    }
//}