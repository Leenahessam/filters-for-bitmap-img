// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char newImage [SIZE][SIZE];
unsigned char image[SIZE][SIZE];
unsigned char photo[SIZE][SIZE];
unsigned char temp [SIZE][SIZE];
unsigned char x;
unsigned char image2[SIZE][SIZE];
unsigned char newpicture [SIZE][SIZE];
unsigned char img_prt [SIZE][SIZE];
unsigned char one [SIZE][SIZE];
unsigned char two [SIZE][SIZE];
unsigned char three [SIZE][SIZE];
unsigned char four [SIZE][SIZE];
void loadImage ();
void flip_Image2();
void blur();
void saveImage ();
void Invert_Image ();
void black_whiteImage();
void flip_Image();
void Rotate();
void darken_lighten_Image();
void detect_Image_edges();
void savephoto();
void saveImage1();
void save();
void savee();
void enlarge();
void Merge();
void mirror_Image();
void shuffle2();
void ans1(unsigned char img_prt[SIZE][SIZE]);
void ans2(unsigned char img_prt[SIZE][SIZE]);
void ans3(unsigned char img_prt[SIZE][SIZE]);
void ans4(unsigned char img_prt[SIZE][SIZE]);
void Shrink();
int choice ;
int Rotat;
int operation;


int main()
{



cout<<" Ahlan ya user ya habibi \n"
<<"Please enter file name of the image to process:\n"
<<"Please select a filter to apply or 0 to exit:  \n"
<<"1- Black & White Filter\n"
<<"2- Invert Filter\n"
<<"3- Merge Filter\n"
<<"4- Flip Image\n"
<<"5- Darken and Lighten Image\n"
<<"6- Rotate Image\n"
<<"7- Detect Image Edges\n"
<<"8- Enlarge Image\n"
<<"9- Shrink Image\n"
<<"10-mirror \n"
<<"11- Shuffle \n"
<<"12-blur \n"
<<"s- Save the image to a file\n"
<<"0-Exit \n";
cin >> choice ;
if (choice==8){
    loadImage();
    enlarge();
    savephoto();
}
if (choice==9){
    loadImage();
    Shrink();
    saveImage1();
}
if (choice==10){
    loadImage();
    mirror_Image();
    save();     }
else if (choice==12){
    loadImage();
    blur();
    savee();
}
else if (choice==7)
{
    loadImage();
    detect_Image_edges();
    save();
}

if (choice !=8 && choice !=9 && choice !=10 && choice !=12 && choice !=7){
loadImage();
if (choice==1)
{
    black_whiteImage();

}
else if (choice==2)
{
    Invert_Image();
}
else if (choice==3){
    Merge();
}
else if (choice==4)
{
    int z;
    cout <<"1- horizontal , 2- vertical  \n" ;
    cin>>z;
    if (z==1)
    {
        flip_Image();
    }
    if (z==2)
    {
        flip_Image2();
    }

}
else if (choice==5)
{
    cout<<" choice 1 - if you want to darken "<<endl;
    cout<<" choice 2 - if you want to lighten "<<endl;
    cin>>operation;
    darken_lighten_Image();
}
else if (choice==6)
{
   cout<<" What the value of rotation that you want :";
   cin >>Rotat;
   if (Rotat==90){
   Rotate();}
   else if (Rotat==180){
    Rotate();
    Rotate();
   }
   else if (Rotat==270){
    Rotate();
    Rotate();
    Rotate();
   }

}



  else if (choice==11){
  shuffle2();
   }


  saveImage();

}
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage(){
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
void save(){
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, temp);
}
void savee(){
       char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image2);
}
void savephoto(){
    char photoFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> photoFileName;

   // Add to it .bmp extension and load image
   strcat (photoFileName, ".bmp");
   writeGSBMP(photoFileName, photo);
}
void black_whiteImage() {

          for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                // do something with the image
                if (image[i][j]>=127)
                    image[i][j]=255;
                else
                   image[i][j]=0;
             }

          }


}
//void shuffle(){

//}
void enlarge(){
    int g;
    cout<<"Please , enter number of the part you want to save \n [1 for the left part upward] \n [2 for right part upward] \n [3 for the left part downward] \n [4 for the right part downward]"<<endl;
    cin>>g;
    int col=0;
    int row=0;
     if (g==1){
     for ( int i = 0; i < SIZE; i+=2 ){
            col = 0;
            for ( int j = 0; j < SIZE; j+=2){
                photo[ i ][ j ]  = image[row][col];
                photo[ i ][j+1]  = image[row][col];
                photo[i+1][ j ]  = image[row][col];
                photo[i+1][j+1]  = image[row][col];
                col++;

            }
            row++;
        }}

     else if (g==4){
        int col=0;
        int row = SIZE / 2;
        for ( int i = 0; i < SIZE; i += 2 ){
            col = SIZE / 2;
            for ( int j = 0; j < SIZE; j += 2){

                photo[ i ][ j ] = image[row][col];
                photo[ i ][j+1] = image[row][col];
                photo[i+1][ j ] = image[row][col];
                photo[i+1][j+1] = image[row][col];
                col++;
            }
            row++;
        }
     }
     else if (g==2){
       for ( int i = 0; i < SIZE ; i += 2 ){
            col = SIZE / 2 ;

            for ( int j = 0; j < SIZE ; j += 2){

                photo[ i ][ j ] = image[row][col];
                photo[ i ][j+1] = image[row][col];
                photo[i+1][ j ] = image[row][col];
                photo[i+1][j+1] = image[row][col];
                col++;

            }
            row++;
        }

     }
     else if (g==3){
      int row = SIZE / 2;
      int col=0;
        for ( int i = 0; i < SIZE; i += 2 ){
            col = 0;
            for ( int j = 0; j < SIZE; j += 2){

                photo[ i ][ j ] = image[row][col];
                photo[ i ][j+1] = image[row][col];
                photo[i+1][ j ] = image[row][col];
                photo[i+1][j+1] = image[row][col];
                col++;

            }
            row++;
        }

     }}
void Merge ()
{ char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, newImage);

     for (int i=0 ; i<SIZE ; i++)
     {
         for ( int j=0 ; j<SIZE ; j++)
         {
             image[i][j] = (image[i][j]+newImage[i][j])/2 ;

         }

     }

}
void mirror_Image()
{
    int choise;
    cout<<"1-left .\n"
        <<"2-right.\n"
        <<"3-upper.\n"
        <<"4-down .\n";
    cin>>choise;
    if (choise==1)
    {
        for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE/2; j++)
             {
               temp[i][j] =image[i][j];
               temp[i][SIZE-1-j] =image[i][j];
             }
          }
    }

    if (choise==2)
    {
        for (int i = 0; i < SIZE; i++)
          {
             for (int j = SIZE/2; j<SIZE ; j++)
             {
               temp[i][j] =image[i][j];
               temp[i][SIZE-1-j] =image[i][j];
             }
          }
    }
   if (choise==3)
    {
        for (int i = 0; i < SIZE/2; i++)
          {
             for (int j = 0; j<SIZE ; j++)
             {
               temp[i][j] =image[i][j];
               temp[SIZE-1-i][j] =image[i][j];
             }
        }
   }
   if (choise==4)
    {
        for (int i =SIZE/2; i < SIZE; i++)
          {
             for (int j =0; j<SIZE ; j++)
             {
               temp[i][j] =image[i][j];
               temp[SIZE-1-i][j] =image[i][j];
             }
        }
   }

}


//_________________________________________
void Invert_Image() {
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j]=255-image[i][j];
    }
  }
}





 void blur(){

 long long average;

     for (int i = 1; i < SIZE-1; i++) {
     for (int j = 1; j<SIZE-1; j++) {
     long long SUM=0;
     SUM=SUM+image[i][j]+image[i+1][j]+image[i-1][j]+image[i][j+1]+image[i][j-1]+image[i+1][j+1]+image[i-1][j-1]+image[i-1][j+1]+image[i+1][j-1];
     average=(SUM/9);
     image2[i][j]=average;

      }

      }

      }




void saveImage1(){
    char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, newpicture);

}



void ans1(unsigned char img_prt[SIZE][SIZE])
{
 for (int i=0;i<128 ;i++){
        for (int j=0;j<128;j++){
            image[i][j]=img_prt[i][j];
            }
 }}




void ans2(unsigned char img_prt[SIZE][SIZE])
{
    int x=0,y=0;
 for (int i=0;i<128 ;i++){
         x++;
         y=0;
        for (int j=128;j<256;j++){
            image[i][j]=img_prt[x][y];
            y++;}
 }}



void ans3(unsigned char img_prt[SIZE][SIZE])
{
    int x=0,y=0;
    for (int i=128;i<256 ;i++){
         x++;
         y=0;
        for (int j=0;j<128;j++){
            image[i][j]=img_prt[x][y];
            y++;}
 }}





void ans4(unsigned char img_prt[SIZE][SIZE])

{  int x=0,y=0;
 for (int i=128;i<256 ;i++){
         x++;
         y=0;
        for (int j=128;j<256;j++){
            image[i][j]=img_prt[x][y];
            y++;}
 }
}



void shuffle2()
{int a,b,c,d;
      int x=0,y=0;
    for (int i=0;i<128 ;i++){
            y=0;
            x++;
        for (int j=0;j<128;j++){
            one[i][j]=image[i][j];
            y++;}}
        y=0,x=0;
    for (int i=0;i<128 ;i++){
           y=0;
           x++;
        for (int j=128;j<256;j++){
            two[x][y]=image[i][j];
            y++;}}
     y=0,x=0;
    for (int i=128;i<256 ;i++){
           y=0;
           x++;
        for (int j=0;j<128;j++){
            three[x][y]=image[i][j];
            y++;}}
    y=0,x=0;
    for (int i=128;i<256 ;i++){
           y=0;
           x++;
        for (int j=128;j<256;j++){
            four[x][y]=image[i][j];
            y++;}}
 cout<<"the order of the image you want: "
 <<"your choice: ";
 cin>>a>>b>>c>>d;

 if (a==1){
    ans1(one);
 }
 else if (a==2){
    ans1(two);
 }
 else if (a==3){
    ans1(three);
 }
 else if (a==4){
    ans1(four);
 }
 if (b==1){
    ans2(one);
 }
 else if (b==2){
    ans2(two);
 }
 else if (b==3){
    ans2(three);
 }
 else if (b==4){
    ans2(four);
 }
 if (c==1){
    ans3(one);
 }
 else if (c==2){
    ans3(two);
 }
 else if (c==3){
    ans3(three);
 }
 else if (c==4){
    ans3(four);
 }
 if (d==1){
    ans4(one);
 }
 else if (d==2){
    ans4(two);
 }
 else if (d==3){
    ans4(three);
 }
 else if (d==4){
    ans4(four);
 }




}




void Shrink(){

char imageFileName[100];

    cout << " Shrink to \n 1- half \n 2- quarter \n 3-third"<<endl;
    int choose;
    cin>>choose;


   for (int i=0 ; i<SIZE ; i++)
     {
         for ( int j=0 ; j<SIZE ; j++)
         {
            newpicture[i][j]=255;
         }
     }

if (choose==1)
    {


    for (int i=0 , k=0 ; k<SIZE ; i++ , k+=2)
    {
        for (int j=0 , h=0 ; h<SIZE ; j++ , h+=2)
        {
            newpicture[i][j]=(image[k][h]+image[k+1][h+1])/2 ;
        }
    }

    }

if (choose==2)
{

for (int i=0 , k=0 ; k<SIZE ; i++ , k+=4)
    {
    for (int j=0 , h=0 ; h<SIZE ; j++ , h+=4)
        {

        newpicture[i][j]=(image[k][h]+image[k+1][h+1]+image[k+2][h+2]+image[k+3][h+3]+image[k+4][h+4])/4;

        }
    }
}
 if (choose==3)
 {
     for (int i=0 , k=0 ; k<SIZE ; i++ , k+=3)
    {
    for (int j=0 , h=0 ; h<SIZE ; j++ , h+=3)
        {

        newpicture[i][j]=(image[k][h]+image[k+1][h+1]+image[k+2][h+2]+image[k+3][h+3])/3 ;

        }
    }

 }

}




void flip_Image() {

          for (int i = 0; i < SIZE/2; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                // do something with the image
               x=image[i][j];
               image[i][j]=image[SIZE-1-i][j];
               image[SIZE-1-i][j]=x;
               // else
               //     image[i][j]=0;
             }

          }


}
void flip_Image2() {

          for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE/2; j++)
             {
                // do something with the image
               x=image[i][j];
               image[i][j]=image[i][SIZE-1-j];
               image[i][SIZE-1-j]=x;
               // else
               //     image[i][j]=0;
             }

          }


}
void darken_lighten_Image() {

          for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                 // do something with the image
                 if (operation==1)
                 {
                     image[i][j]=(image[i][j])/2;
                 }
                 else
                 {
                             if (image[i][j]<127 )
                      {
                          image[i][j]=(image[i][j])+127;
                          if (image[i][j]>=127)
                          {
                              image[i][j]=(image[i][j])-64;
                          }

                      }
                 }


             }

          }


}
void Rotate (){
    int O=SIZE-1;
    for (int i=0;i<SIZE ;i++){
        for (int j=0;j<SIZE;j++){
            newImage[i][j]=image[i][j];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=newImage[j][O];
        }
        O=O-1;
    }}

void detect_Image_edges() {
   // black_whiteImage();
          for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; )
             {
                // int t=0;
               //  x=image[i][j]-image[i][j+1];
                // do something with the image
                if (image[i][j]==image[i+1][j+1])
                {
                    while (true&&j<SIZE)
                    {
                        if (image[i][j]!= image[i][j+1] || image[i+1][j] != image[i][j])
                        {
                           temp[i][j] =0;
                        }
                         else
                        {
                              temp[i][j]=255;
                        }
                        j++;
                    }


                }

                else
                {
                    temp[i][j]=255;
                    j++;
                }


             }

          }

}


