//lab 16 comsc 210 Zakariya Abdi
#include <iostream>
using namespace std;

class color {
private:
    int red;
    int green;
    int blue;

public:
    // default constructor
    color() : red(0), green(0), blue(0) {}

    //parameter constructor
    color(int r, int g, int b) : red(r), green(g), blue(b) {}

    //partial constructor
    color(int r, int g) : red(r), green(g), blue(0) {}

    //partial constructor
    color(int r) : red(r), green(0), blue(0) {}

    //setter functions
    void setred(int r) { red = r; }
    void setgreen(int g) { green = g; }
    void setblue(int b) { blue = b; }

    // getter functions
    int getred() { return red; }
    int getgreen() { return green; }
    int getblue() { return blue; }

    // function to print the colors
    void print() const {
        cout << "The color (R: " << red << ", G: " << green << ", B: " << blue << ")" << endl;
    }
};

int main() {
    //different color objects
    color color1;
    color color2(255, 0, 0); // red
    color color3(0, 255, 0); // green
    color color4(0, 0, 255); // blue

    // Using the partial constructor (only red and green specified, blue defaults to 0)
    color color5(128, 64); // color with red=128, green=64, blue=0

    // Using the partial constructor (only red specified, green and blue default to 0)
    color color6(200);

    //ouputs the colors
    cout << "Color 1: ";
    color1.print();

    cout << "Color 2: ";
    color2.print();

    cout << "Color 3: ";
    color3.print();

    cout << "Color 4: ";
    color4.print();

    cout << "Color 5: ";
    color5.print();

    cout << "Color 6: ";
    color6.print();

    return 0;
}
