#include <iostream>

struct BookData {
    std::string book_name;
    std::string autor_name;
    int publication_year;
    int reading_date;
    int book_note;
};


class Book {
    BookData data;
public:
    Book(const std::string &name, const std::string &autor, int year, int read_date, int note);
    // Getters
    BookData get_book_data();
};

Book::Book(const std::string &name, const std::string &autor, const int year, const int read_date, const int note)
            : data(name, autor, year, read_date, note) {};

BookData Book::get_book_data() {
    return data;
}



int main() {
    Book book1 ("Buch", "Autor", 2000, 2025, 8);
    BookData book_data = book1.get_book_data();

    std::cout << "Book Name: " << book_data.book_name << std::endl;
    std::cout << "Autor Name: " << book_data.autor_name << std::endl;
    std::cout << "Pub Year: " << book_data.publication_year << std::endl;
    std::cout << "Read Date: " << book_data.reading_date << std::endl;
    std::cout << "Book Note: " << book_data.book_note << std::endl;


    return 0;
}
