#include "file_management.h"
#include "command_process.h"
#include <iostream>
#include <string>

using namespace std;

    // Create the root of the file system
    string rootName = "root:";
    TreeNode* root = new TreeNode(rootName, nullptr, true);
int main() {
    TreeNode** rootPtr = &root;
    string command;
    while (true) {
        printPath(*rootPtr);
        cout << " > ";
        getline(cin, command);
        if (command == "exit") {
            break;
        }
        processCommand(rootPtr, command); // Process the command
    }

    return 0;
}
