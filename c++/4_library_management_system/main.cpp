#include <iostream>
#include <vector>

struct BookData {
    std::string book_name;
    std::string autor_name;
    int publication_year;
    int reading_year;
    int book_grade;
};


class Book {
    BookData data;
public:
    Book(const std::string &name, const std::string &autor, int pub_year, int read_year, int grade);
    // Getters
    BookData get_book_data();
};

Book::Book(const std::string &name, const std::string &autor, const int pub_year, const int read_year, const int grade)
            : data(name, autor, pub_year, read_year, grade) {};

BookData Book::get_book_data() {
    return data;
}



namespace Console {
    void show_menue() {
        std::cout << "----------- Library System -----------" << std::endl;
        std::cout << "1. Add Book"      << std::endl;
        std::cout << "2. Show Books"    << std::endl;
        std::cout << "3. Delete Book"   << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }

    BookData add_book_menue() {
        BookData data;
        std::cout << "Book name: ";
        std::cin >> data.book_name;
        std::cout << "Autor name: ";
        std::cin >> data.autor_name;
        std::cout << "Publication year: ";
        std::cin >> data.publication_year;
        std::cout << "Reading year: ";
        std::cin >> data.reading_year;
        std::cout << "Book grade: ";
        std::cin >> data.book_grade;

        return data;
    }

    void print_book_data(const BookData &data) {
        std::cout << "Book name: " << data.book_name << std::endl;
        std::cout << "Autor name: " << data.autor_name << std::endl;
        std::cout << "Publication year: " << data.publication_year << std::endl;
        std::cout << "Reading year: " << data.reading_year << std::endl;
        std::cout << "Book grade: " << data.book_grade << std::endl;
    }

    void print_book_list(std::vector<Book> booklist) {
        for (size_t i = 0; i < booklist.size(); i++) {
            std::cout << "# Book " << i + 1 << " ----------------- #" << std::endl;
            print_book_data(booklist[i].get_book_data());
        }
    }

    char get_input() {
        while (true) {
            char user_input;
            std::cout << "Input: ";
            std::cin >> user_input;
            // Compare with ASCII Table
            if (user_input >= 48 && user_input <= 51 ) {
                return user_input;
            }
            std::cout << "Invalid Input. Try again!" << std::endl;
        }
    }

}


int main() {

    std::vector<Book> BookList;

    // Console::show_menue();
    // char type = Console::get_input();
    // BookData data = Console::add_book_menue();
    // std::cout << data.autor_name;


    Book book1 ("Buch", "Autor", 2000, 2025, 8);
    BookList.push_back(book1);
    Book book2 ("Autor", "Buch", 2000, 2025, 8);
    BookList.push_back(book2);

    Console::print_book_list(BookList);



    // BookData book_data = book1.get_book_data();
    //
    // std::cout << "Book Name: " << book_data.book_name << std::endl;
    // std::cout << "Autor Name: " << book_data.autor_name << std::endl;
    // std::cout << "Pub Year: " << book_data.publication_year << std::endl;
    // std::cout << "Read Date: " << book_data.reading_date << std::endl;
    // std::cout << "Book Note: " << book_data.book_note << std::endl;


    return 0;
}
