// COMSC 210 lab 14 Zakariya Abdi
#include <iostream>
using namespace std;

class color {
    private:
        int red;
        int green;
        int blue;
    
    public:
    color(int r = 0, int g = 0, int b = 0){}

    //function to setter 
    void setred(int r){red = r;}
    void setgreen(int g){green = g;}
    void setblue(int b){blue = b;}

    //function for getter
    int getred(){return red;}
    int getgreen(){return green;}
    int getblue(){return blue;}

    //function to output the colors 
    void print() const{
        cout <<"The color (R is " << red <<", G: " << green << ", B: " << blue << ")" << endl;
    }
};

int main(){
    //different color objects
    color color1; 
    color color2; (255, 0, 0);//color red
    color color3; (0, 255, 0); // color blue
    color color4; (0, 0, 255); //color green

    //values for the color
    color1.setred(128);
    color2.setblue(128);
    color3.setgreen(128);

    //outputs the colors
 cout << "Color 1: ";
    color1.print();

    cout << "Color 2: ";
    color2.print();

    cout << "Color 3: ";
    color3.print();

    cout << "Color 4: ";
    color4.print();

    return 0;

    
}