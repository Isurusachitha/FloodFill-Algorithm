/***********************************************************************************************************************************************
Courese      :    CO2201 Data Structures and Algorithms
Year         :    2018
Name         :    HERATH HMMISB
Index No     :    16_ENG_029
Lab No       :    3
Date         :   02-05-2018

**********************************************************************************************************************************************************/

//Header Files
#include <iostream>
#include <math.h>
#include<fstream>
#include <string>
#include <vector>

//Declare namespace
using namespace std;


// declaring variables

//char imgPixel[10][25];

vector< vector<char> >imgPixel;

//declaring functions
 void ReadFile();
 void DisplayImg();
 void FloodFill(int x,int y,char OldChrC,char NewChrC);

//Main functions

int main(){

    int Xd=0;
    int Yd=0;
    char OldColorChar;

   ReadFile();

   std::cout << " \n      Starting Image " << '\n';
   std::cout << "-------------------------------------------------\n\n" << '\n';
   DisplayImg();

   ValidLabel2: std::cout << "\nX coordinate of the initial pixel :" ;
                cin>>Yd;

                if(Yd<0 || Yd >9){
                std::cout << " \n invalid Y coordinate : enter valid coordinate within range ( 0 - 9) " << '\n';
                goto ValidLabel2;

                 }

   ValidLabel1 : std::cout << "Y coordinate of the initial pixel :"  ;
                 cin>>Xd;

                if(Xd<0 || Xd >24){
                  std::cout << " \n invalid X coordinate : enter valid coordinate within range ( 0 - 24) " << '\n';
                  goto ValidLabel1;

                }






   OldColorChar=imgPixel[Yd][Xd];
   std::cout << " \n Initial point Pixcel value :  " << OldColorChar <<'\n';
   FloodFill(Xd,Yd,OldColorChar,'-');

   std::cout << " \n     After applying Flooding algorithem " << '\n';
   std::cout << "------------------------------------------------\n\n" << '\n';
   DisplayImg();



  //resturn statement
  return 0;
}

void ReadFile() {

	int Yd = 0;

	string str;
	char chr;



	ifstream infile("ImageTxt.txt");  // TXT image which is using for floodfilling

	while(!infile.eof()){

          vector<char> tempVec;

	       	getline(infile, str);    // get whole line as string



      for (int Xd=0; Xd<str.length(); ++Xd){  // divide string into char

          chr= str.at(Xd) ;

            //imgPixel[Yd][Xd]=chr;
            tempVec.push_back(chr);
      }

	   cout << endl;  // move to new line

     imgPixel.push_back(tempVec);

     ++Yd;

	}

	infile.close();
//  std::cout << "line " << Yd<<'\n';

}

void DisplayImg(){

     for (int y = 0; y < 10; y++) {

        for (int x = 0; x < 25; x++) {

                std::cout << imgPixel[y][x] ;
        }
       std::cout << '\n';
     }

}


void FloodFill(int x,int y,char OldChrC,char NewChrC){

 if( (x>=0 && x <imgPixel[1].size() ) && ( y>=0 && y<imgPixel.size()  ) ){  // limiting recurvisity within the range of the image

       if(imgPixel[y][x]==OldChrC){

           imgPixel[y][x]=NewChrC;  // Changeing color of selected Pixcel

             FloodFill(x,y+1,OldChrC,NewChrC);   // Flooding to other Pixcel by Recursivity
             FloodFill(x,y-1,OldChrC,NewChrC);
             FloodFill(x+1,y,OldChrC,NewChrC);
             FloodFill(x-1,y,OldChrC,NewChrC);


       }
   }
}
