#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

// node that stores the movie reviews
struct MovieReviewNode {
    float rating;
    string comment;
    MovieReviewNode* next;

    MovieReviewNode(float r, string c) : rating(r), comment(c), next(nullptr) {}
};

// class to represent the movie title and the review
class Movie {
private:
    string title;
    MovieReviewNode* head;

    // function to add a review at the head of the linked list
    void addReview(float rating, const string& comment) {
        MovieReviewNode* newNode = new MovieReviewNode(rating, comment);
        newNode->next = head;
        head = newNode;
    }

public:
    // constructor to initialize the node
    Movie(const string& title) : title(title), head(nullptr) {}

    // function to read reviews from an file and assign the random ratings
    void loadReviews(const string& fileName) {
        ifstream file(fileName);
        if (!file) {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }

        string comment;
        while (getline(file, comment)) {
            float randomRating = generateRandomRating();  
            addReview(randomRating, comment);  
        }

        file.close();
    }

    // function to display all reviews and the calc the average  rating
    void displayReviews() const {
        MovieReviewNode* temp = head;
        float totalRating = 0;
        int count = 0;

        cout << "Reviews for movie: " << title << endl;
        while (temp != nullptr) {
            cout << "Rating: " << temp->rating << "\nComment: " << temp->comment << "\n\n";
            totalRating += temp->rating;
            count++;
            temp = temp->next;
        }

        if (count > 0) {
            float averageRating = totalRating / count;
            cout << "Average Rating: " << averageRating << "\n\n";
        } else {
            cout << "No reviews to display.\n\n";
        }
    }

    // static function to get a review between 1.0 and 5.0
    static float generateRandomRating() {
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_real_distribution<float> dist(1.0, 5.0);

        return static_cast<float>(round(dist(gen) * 10) / 10.0); 
    }
};

// main function to show the movie reviews and the class
int main() {
    
    vector<Movie> movies;

    // creates two different movie objects
    Movie movie1("ActionMovie");
    Movie movie2("HorrorMovie");

    // gets the reviews from an external file
    movie1.loadReviews("actionmovie.txt");
    movie2.loadReviews("horrormovie.txt");

    // adds a movie to the vector
    movies.push_back(movie1);
    movies.push_back(movie2);

    // displasy the review for each of the movies
    for (const Movie& movie : movies) {
        movie.displayReviews();
    }

    return 0;
}
