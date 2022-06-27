#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

//void generateFile()
//{
//    srand(time(NULL));
//    int maxSize=1000000;
//    ofstream myFile_Handler;
//    // File Open
//    myFile_Handler.open("data.txt");
//
//    for(int i=0; i<maxSize+1; i++)
//    {
//        if(i==0)
//        {
//            myFile_Handler << maxSize << endl;
//        }
//        else
//        {
//            myFile_Handler << rand()% maxSize << endl;
//        }
//    }
//    //myFile_Handler << "This is a sample test File. " << endl;
//    // myFile_Handler << "This is the second line of the file. " << endl;
//
//    // File Close
//    myFile_Handler.close();
//}