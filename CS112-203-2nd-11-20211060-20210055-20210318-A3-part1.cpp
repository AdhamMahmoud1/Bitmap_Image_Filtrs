#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void Black_white_1()
{
    int avg;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0 ; j < SIZE; j++)
        {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(image[i][j] > avg)
            {
                image[i][j] =255;
            }
            else    
                image[i][j] = 0;
        }
    }
}

void FlibImage_4()
{
    char flip_choice;
    cout << "Flip (h)orizontally or (v)ertically ? ";
    cin >> flip_choice ; 
    towlower(flip_choice);
    if(flip_choice == 'h')
    {
        for (int i = 1; i <= SIZE/2; i++)
        {
            for(int j = 1; j <= SIZE; j++)
            {
                swap(image[i][j], image[SIZE -1 -i][j]);
            }
            
        }
    }else if(flip_choice == 'v')
    {
        for (int i = 1; i <= SIZE; i++)
        {
            for(int j = 1; j <= SIZE/2; j++)
            {
                swap(image[i][j], image[i][SIZE - 1- j]);
            }
            
        }
    }
    
}
void DetectImage()
{
    int dif;
    for (int i = 1; i <= SIZE; i++)
    {
        {
            for(int j = 1; j <= SIZE; j++)
            {
                if(image[i][j] > image[i+1][j])
                {
                    dif = image[i][j] - image[i+1][j];
                }if(image[i][j] < image[i+1][j])
                {
                    if(dif < (image[i+1][j] - image[i][j]))
                        dif = image[i+1][j] - image[i][j];
                }if(image[i][j] > image[i][j+1])
                {
                    if(dif < (image[i][j] - image[i][j+1]))
                        dif = image[i][j] - image[i][j+1];
                }if(image[i][j] < image[i][j+1])
                {
                    if(dif < (image[i][j+1] - image[i][j]))
                        dif = image[i][j+1] - image[i][j];
                }
                

                if(dif >35)
                {
                    image[i][j] = 0;
                }else
                {
                    image[i][j] = 255;
                }
            }
            
        }
    }
}

void MirrorImage_a()
{
    char choice;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?";
    cin >> choice;
    if (choice == 'l')
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = SIZE; j > 0; j--)
            {
                image[i][j] = image[i][SIZE - j];
            }
        }
    }if (choice == 'r')
    {
        for(int i = SIZE; i > 0; i--)
        {
            for(int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][SIZE - j];
            }
        }
    }if(choice == 'd')
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = SIZE; j > 0; j--)
            {    
                image[i][j] = image[SIZE - i][j];
            }        
        }
    }if(choice == 'u')
    {
        for(int i = SIZE; i > 0; i--)
        {
            for(int j = 0; j < SIZE; j++)
            {    
                image[i][j] = image[SIZE - i][j];
            }        
        }
    }
}

void blur(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j+1]+image[i][j+2]+image[i+1][j+1]+image[i+2][j+2]+image[i+1][j+2]+image[i+2][j+1])/9;
        }
    }
}
void merge(){
    unsigned char image2 [SIZE][SIZE];
    char imageFileName2[100];

    cout<<"Enter the source image file name: ";
    cin>>imageFileName2;
    strcat(imageFileName2,".bmp");
    readGSBMP(imageFileName2,image2);
    for (int i =0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image[i][j]=(image2[i][j] + image[i][j])/2;
        }
    }
}
void loadImage()
{
    char imageName[100];
    cout<<"Please enter the image file name: ";
    cin >> imageName;
    strcat ( imageName,".bmp");
    readGSBMP(imageName, image);
}
void saveRotateImage()
{
    char image_name[100];
    cout<<"Please enter the name of he new image: ";
    cin >> image_name;
    strcat(image_name, ".bmp");
    writeGSBMP(image_name, new_image);
}
void saveImage()
{
    char image_name[100];
    cout << "Please enter the name of he new image: ";
    cin >> image_name;
    strcat(image_name, ".bmp");
    writeGSBMP(image_name, image);
}
void invertImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void rotateImage()
{
    int choice;
    cout<<"Please choose the type of rotating image:\n1_90\n2_180\n3_270"<<endl;
    cin >> choice;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (choice == 1)
            {
                new_image[255 - j][255 - i] = image[i][255 - j];
            }
            else if (choice == 2)
            {
                new_image[255 - i][255 - j] = image[i][j];
            }
            else if (choice ==3)
            {
                new_image[255 - j][i] = image[i][j];
            }    
        }
    }
}
void enlargeImage()
{
    int n;
    cout<<"Please choose the quarter you want to Enlarge: ";
    cin >> n;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (n==1){
                new_image[i][j] = image[i/2][j/2];
            }
            else if (n==2){
                new_image[i][j] = image[i/2][SIZE/2 + j/ 2];
            }
            else if (n==3){
                new_image[i][j] = image[SIZE / 2 + i / 2][j / 2];
            }
            else if (n==4){
                new_image[i][j] = image[SIZE / 2 + i / 2][SIZE / 2 + j / 2];
            }  
        }
    }
}



void moveQuarter(int idex, int i, int j )
{
    int temp = j;
    if (idex==1)
        for (int k=0; k < SIZE/2; i++,k++)
        {
            j = temp;
            for (int z=0; z< SIZE/2; j++,z++)
                new_image[i][j]=image[k][z];
        }
    else if (idex==2)
        for (int k = 0; k< SIZE/2; i++,k++)
        {
            j = temp;
            for (int z = SIZE/2; z< SIZE; j++,z++)
                new_image[i][j]=image[k][z];
        }
    else if (idex ==3)
        for (int k=  SIZE/2 ; k<SIZE; i++,k++)
        {
            j = temp;
            for (int z=0; z< SIZE/2; j++,z++)
                new_image[i][j]=image[k][z];
        }
    else if (idex ==4)
        for (int k =  SIZE/2; k < SIZE; i++,k++)
        {
            j = temp;
            for (int z = SIZE/2; z< SIZE; j++,z++)
                new_image[i][j]=image[k][z];
        }
}
void shuffleImage()
{
    int n ;
    cout << "Enter the order of quarters you want: ";
    for (int i =0 ; i <4 ; i++)
    {
        cin>>n;
        if (i==0) moveQuarter(n,0,0);
        else if (i==1) moveQuarter(n,0,SIZE/2);
        else if (i==2) moveQuarter(n,SIZE/2,0);
        else if (i==3) moveQuarter(n,SIZE/2,SIZE/2);
    }
}
void display()
{
    string n;
    loadImage();
    cout << "Hello user\nplease select a filtr to apply or 0 to exit: " << endl;
    do
    {
        cout << "1- Black & White filter\n";
        cout << "2- Invert Filter\n";
        cout << "3- Merge Filter\n";
        cout << "4- Flip Image\n";
        cout << "5- Rotate Iimage\n";
        cout << "7- Detect Image\n";
        cout << "8- Enlarge Image\n";
        cout << "a- Mirror Image\n";
        cout << "b- Shuffle Image\n";
        cout << "c- Blur Image\n";
        cout << "s- Save the Image to a file\n";
        cout << "0- Exit" << endl;

        // this piece of code to check if there is any extra empty lines 
        if(cin.peek() == '\n')
        {
            cin.ignore();
        }


        cin >> n;
        if (n=="1")
        {
            Black_white_1();
            saveImage();
        }
        else if (n=="2")
        {
            invertImage();
            saveImage();
        }
        else if (n=="3")
        {
            merge();
            saveImage();
        }
        else if (n=="4")
        {
            FlibImage_4();
            saveImage();
        }
        else if (n=="5")
        {
            rotateImage();
            saveImage();
        }else if (n == "7")
        {
            DetectImage();
            saveImage();

        }else if(n=="8")
        {
            enlargeImage();
            saveRotateImage();
        }else if (n == "a")
        {
            MirrorImage_a();
            saveImage();
        }
        else if(n=="b")
        {
            shuffleImage();
            saveRotateImage();
        }
        else if(n == "c")
        {
            blur();
            saveImage();
        }
        else if (n=="s")
        {
            saveImage();
        }
    } while (n != "0");
    
    
}
int main()
{
    display();

    return 0;
}

