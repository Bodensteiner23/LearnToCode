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
        std::cout << "----------- Book List -----------" << std::endl;
        for (size_t i = 0; i < booklist.size(); i++) {
            std::cout << "# Book " << i + 1 << " ----------------- #" << std::endl;
            print_book_data(booklist[i].get_book_data());
            std::cout << std::endl;
        }
    }

    void delete_book(std::vector<Book> &booklist) {
        int book_number;
        std::cin >> book_number;

        if (book_number < booklist.size()) {
            booklist.erase(booklist.begin() + book_number - 1);
        } else {
            std::cout << "Invalid Book Number" << std::endl;
        }
    }

    int get_input() {
        while (true) {
            char char_input;
            std::cout << "Input: ";
            std::cin >> char_input;
            std::cout << std::endl;
            // Convert from ASCII to int
            int int_input = char_input - '0';
            if (int_input >= 0 && int_input <= 3 ) {
                return int_input;
            }
            std::cout << "Invalid Input. Try again!" << std::endl;
        }
    }
}


int main() {

    std::vector<Book> BookList;
    Book book1 ("Buch", "Autor", 2000, 2025, 8);
    BookList.push_back(book1);
    Book book2 ("Autor", "Buch", 2000, 2025, 8);
    BookList.push_back(book2);

    while (true) {
        Console::show_menue();
        int input = Console::get_input();
        switch (input) {
            case 1:
                Console::add_book_menue();
            break;
            case 2:
                Console::print_book_list(BookList);
            break;
            case 3:
                Console::delete_book(BookList);
            break;
            default:
                break;
        }



    }
    // Console::show_menue();
    // char type = Console::get_input();
    // BookData data = Console::add_book_menue();
    // std::cout << data.autor_name;

    Console::print_book_list(BookList);
    int input = Console::get_input();

    Console::delete_book(BookList);
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
