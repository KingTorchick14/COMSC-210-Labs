//Lab 15 COMSC 210 Zakariya Abdi
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Movie {
private:
    string movie;
    int yearReleased;
    string screenWriter;

public:
    // Constructor
    Movie(string m = "", int y = 0, string s = "") : movie(m), yearReleased(y), screenWriter(s) {}

    // Setter methods
    void setTitle(string m) { movie = m; }
    void setYearReleased(int y) { yearReleased = y; }
    void setScreenWriter(string s) { screenWriter = s; }

    // Getter methods
    string getTitle() const { return movie; }
    int getYearReleased() const { return yearReleased; }
    string getScreenWriter() const { return screenWriter; }

    //function output the movie data
    void print() const {
        cout << "Movie: " << movie << ", Year: " << yearReleased << ", Screenwriter: " << screenWriter << endl;
    }
};

int main() {
    // Vector to store Movie objects
    vector<Movie> movies;

    // function to open the .txt file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // stores the input data
    string title;
    int year;
    string screenWriter;

    // function to read the data
    while (getline(inputFile, title)) {
        inputFile >> year;
        inputFile.ignore(); 
        getline(inputFile, screenWriter);

        // makes a movie object and fills it with data
        Movie tempMovie;
        tempMovie.setTitle(title);
        tempMovie.setYearReleased(year);
        tempMovie.setScreenWriter(screenWriter);
        
        movies.push_back(tempMovie);
    }

    //closes the .txt file
    inputFile.close();

    // outputs the data
    cout << "Movies List: " << endl;
    for (const auto& movie : movies) {
        movie.print();
    }

    return 0;
}
