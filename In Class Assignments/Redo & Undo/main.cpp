#include <iostream>
#include <stack>

class typeDoc{

    std::string ui;
    std::stack<std::string> initial_stack;
    std::stack<std::string> redo_stack;

    void typeScript(){
        std::cout << "Enter text: ";
        std::getline(std::cin, ui);
    }

    void redo(){

    }

    void undo(){

    }
};

int main(){


    return 0;
}