#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

vector<Book> books;
int nextId = 1;

void addBook() {
    Book book;
    book.id = nextId++;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    books.push_back(book);
    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    for (const auto& book : books) {
        cout << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author << endl;
    }
}

void updateBook() {
    int id;
    cout << "Enter book ID to update: ";
    cin >> id;
    for (auto& book : books) {
        if (book.id == id) {
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Enter new author: ";
            getline(cin, book.author);
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void deleteBook() {
    int id;
    cout << "Enter book ID to delete: ";
    cin >> id;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Management System";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Update Book";
        cout << "\n4. Delete Book";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: updateBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    
    return 0;
}
