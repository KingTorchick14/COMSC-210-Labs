//lab 18 comsc 210 Zakariya Abdi
#include <iostream>
#include <string>

using namespace std;

// node that stores the movie reviews
struct MovieReviewNode {
    float rating;       
    string comment;      
    MovieReviewNode* next;

    // constructor to initialize the node
    MovieReviewNode(float r, string c) : rating(r), comment(c), next(nullptr) {}
};

// function to add a review to the head of the linked list
void addAtHead(MovieReviewNode*& head, float rating, const string& comment) {
    MovieReviewNode* newNode = new MovieReviewNode(rating, comment);
    newNode->next = head;
    head = newNode;
}

// function to add a review to the tail of the linked list
void addAtTail(MovieReviewNode*& head, float rating, const string& comment) {
    MovieReviewNode* newNode = new MovieReviewNode(rating, comment);
    if (head == nullptr) { 
        head = newNode;
    } else {
        MovieReviewNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// function to traverse the list and display the reviews
void displayReviews(MovieReviewNode* head) {
    MovieReviewNode* temp = head;
    float totalRating = 0;
    int count = 0;

    // Traverses the list
    while (temp != nullptr) {
        cout << "Rating: " << temp->rating << "\nComment: " << temp->comment << "\n\n";
        totalRating += temp->rating;
        count++;
        temp = temp->next;
    }

    // calcs and displays the average rating of the movie
    if (count > 0) {
        double averageRating = static_cast<double>(totalRating) / count;
        cout << "Average Rating: " << averageRating << endl;
    } else {
        cout << "No reviews to display." << endl;
    }
}

int main() {
    MovieReviewNode* head = nullptr; 
    char mode;
    float rating;
    string comment;

    // asks the user for input on whether to add the review to the tail or the head of the list
    cout << "Enter 'H' to add reviews at the head or 'T' to add at the tail: ";
    cin >> mode;
    cin.ignore(); 

    // inputs the movie reviews
    while (true) {
        cout << "Enter movie rating (or -1 to finish): ";
        cin >> rating;
        if (rating == -1) break;  // exits the input loop when user enters in -1
        cin.ignore();  // ignores the newline character after the rating input

        cout << "Enter your comment: ";
        getline(cin, comment);

        // adds the review to the list based on what the user chose
        if (mode == 'H' || mode == 'h') {
            addAtHead(head, rating, comment);
        } else if (mode == 'T' || mode == 't') {
            addAtTail(head, rating, comment);
        } else {
            cout << "Invalid mode selected. Please restart the program." << endl;
            return 1; // exits if mode is invalid
        }
    }

    // outputs the reviews and calcs the average rating
    cout << "\nDisplaying all reviews:\n";
    displayReviews(head);

    return 0;
}
