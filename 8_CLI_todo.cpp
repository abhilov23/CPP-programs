#include <iostream> // For input/output stream
#include <string>   // For using string
#include <list>     // For using lists
#include <ctime>    // For time-related functions
#include <cstdlib>  // For system() and srand()

using namespace std;

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {} //constructor
    ~TodoItem() = default; //destructor

    bool create(std::string new_description) {
        // Generate a random integer between 1 and 100
        id = rand() % 100 + 1; //generating random input for id
        description = new_description; //presigning description
        completed = false; //predefined complete as false
        return true;
    }

    int getId() const { return id; } //for returning id
    std::string getDescription() const { return description; } //for getting description
    bool isCompleted() const { return completed; } //for checking status
    void complete() { completed = true; } 
};

int main() {
    char input_option; // For user input
    std::string version = "v 0.1.0"; // Defining version
    std::list<TodoItem> todoItems;   // Creating a list of Todo items
    std::list<TodoItem>::iterator it; // Iterator for the list

    srand(time(NULL)); // Seed for random number generation

    while (true) {
#ifdef _WIN32
        system("cls"); // Clear the screen (Windows-specific)
#else
        system("clear"); // Alternative for Unix-based systems
#endif
        std::cout << "Todo list version : " << version << endl;
        std::cout << std::endl << std::endl;

        if (todoItems.empty()) {
            std::cout << "Your Todo list is empty! Add your first todo! 🐈🐈🐈" << std::endl;
        } else {
            for (it = todoItems.begin(); it != todoItems.end(); ++it) {
                // Use a ternary operator to display completed status
                std::string completed = it->isCompleted() ? "done" : "not done";

                // Displaying the details of each todo item
                std::cout << it->getId() << " | " 
                          << it->getDescription() << " | " 
                          << completed << endl;
            }
        }

        // Menu for user options
        std::cout << std::endl;
        std::cout << "[a]dd a new todo!" << std::endl;
        std::cout << "[c]omplete a Todo!" << std::endl;
        std::cout << "[q]uit!" << std::endl;
        std::cout << "Choice: ";
        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "Have a great day! 🎉" << std::endl;
            break; // Exit the loop
        } else if (input_option == 'a') {
            std::string new_description;
            std::cout << "Enter the description for the new todo: ";
            std::cin.ignore(); // Ignore the leftover newline from previous input
            std::getline(std::cin, new_description);

            TodoItem newItem;
            newItem.create(new_description);
            todoItems.push_back(newItem);

            std::cout << "New todo added successfully! ✅" << std::endl;
        } else if (input_option == 'c') {
            if (todoItems.empty()) {
                std::cout << "No todo items to complete!" << std::endl;
            } else {
                int todo_id;
                std::cout << "Enter the ID of the todo to mark as complete: ";
                std::cin >> todo_id;

                bool found = false;
                for (it = todoItems.begin(); it != todoItems.end(); ++it) {
                    if (it->getId() == todo_id) {
                        it->complete();
                        std::cout << "Todo marked as complete! ✅" << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Todo with ID " << todo_id << " not found." << std::endl;
                }
            }
        } else {
            std::cout << "Invalid option! Please try again." << std::endl;
        }

        // Pause before refreshing
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}
