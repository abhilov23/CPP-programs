#include <iostream> //for input/output stream
#include <string> //for using list 
#include <list> //for getting the list
#include <ctime> //library for getting time 
#include <cstdlib> // For system() and srand()

using namespace std;

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    // Constructor predefining the values
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // Generate a random integer between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
};

int main() {
    std::string version = "v 0.1.0"; //defining the version
    std::list<TodoItem> todoItems; //creating a list
    std::list<TodoItem>::iterator it; // using a iterator on that list
    
    srand(time(NULL)); // Seed for random number generation

    todoItems.clear();
    TodoItem test; // eclaring an object
    test.create("This is a test");
    todoItems.push_back(test); //putting it in list

    while (1) {
        system("cls"); // Clears the screen (Windows-specific)
        std::cout << "Todo list version : " << version << endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
             //using a ternary operator for applying two conditions, either the task is done or not done.
             std::string completed = it->isCompleted() ? "done" : "not done";

            // Iterator iterating through items in todo
            std::cout << it->getId() << " | " 
                      << it->getDescription() << " | " 
                      << completed << endl;
        }

        break; // Exit the loop
    }

    return 0;
}
