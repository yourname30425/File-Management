#include"command_process.h"

using namespace std;

// Xử lý lệnh command từ người dùng
void processCommand(TreeNode** currentDir, const string& command){
    //liệt kê các thư mục và file trong thư mục hiện tại
    if(command == "ls"){
        listDirectory(*currentDir);
    }

    // lss: Liệt kê toàn bộ thư mục và file từ thư mục hiện tại trở đi
    else if (command == "lss") {
        listSubtree(*currentDir);
    }
    
    //in đường dẫn của thư mục hiện tại
    else if(command == "pwd"){
        printPath(*currentDir);
        cout<<"\n";
    }

    // di chuyển đến thư mục cha hoặc thư mục con
    else if(command.substr(0,3) == "cd "){
        string DirName = command.substr(3);
        if(DirName == ".."){
            if((*currentDir)->parent != nullptr){
                *currentDir = (*currentDir)->parent;
            }
        }else{
            TreeNode* child = findChild(*currentDir,DirName);
            if(child != nullptr && child->isFolder){
                *currentDir = child;
            }else{
                cout<<"No such directory\n";
            }
        }
    }

    // Thoát ra thư mục lớn nhất (root directory)
    else if (command == "cdd") {
        goToRoot(currentDir);
    }

    //tạo thư mục mới
    else if(command.substr(0,6) == "mkdir "){
        string DirName = command.substr(6);
        if (checkChild(*currentDir,DirName)){
            cout<<"Folder already exists\n";
            return;
        }
        else addChild(*currentDir,DirName,true);
    }

    //tạo file mới
    else if(command.substr(0,6) == "touch "){
        string FileName = command.substr(6);
        if (checkChild(*currentDir,FileName)){
            cout<<"Folder already exists\n";
            return;
        }
        else addChild(*currentDir,FileName,false);
    }

    //xóa file
    else if(command.substr(0,3) == "rm "){
        string FileName = command.substr(3);
        TreeNode* child = findChild(*currentDir,FileName);
        if(child != nullptr && !child->isFolder){
            (*currentDir)->children.erase(remove((*currentDir)->children.begin(),(*currentDir)->children.end(),child),(*currentDir)->children.end());
            delete child;
        }
        else{
            cout<<"No such file\n";
        }
    }

    //xóa thư mục
    else if(command.substr(0,6)== "rmdir "){
        string DirName = command.substr(6);
        TreeNode* child = findChild(*currentDir,DirName);
        if(child != nullptr && child->isFolder){
            deleteNode(child);
            (*currentDir)->children.erase(remove((*currentDir)->children.begin(),(*currentDir)->children.end(),child),(*currentDir)->children.end());
        }
        else{
            cout<<"No such directory\n";
        }
    }

    // Xóa màn hình nếu lệnh là "cls"
    else if (command == "cls") {
        clearScreen();  // Xóa màn hình
    }

    else if(command == "help"){
        showHelp();
    }

    // Lệnh đổi tên file hoặc thư mục
    else if (command.substr(0,7) == "rename "){
        stringstream ss(command.substr(7));  // Lấy phần sau "rename "
        string oldName, newName;
        ss >> oldName >> newName;  // Tách tên cũ và tên mới

        // Kiểm tra cú pháp của lệnh rename
        if (oldName.empty() || newName.empty()) {
            cout << "Invalid syntax. Usage: rename <old_name> <new_name>\n";
        } else {
            // Kiểm tra xem đó là đổi tên file hay thư mục
            TreeNode* fileNode = findChild(*currentDir, oldName);
            if (fileNode != nullptr && !fileNode->isFolder) {
                renameFile(*currentDir, oldName, newName);  // Đổi tên file
            } else {
                renameFolder(*currentDir, oldName, newName);  // Đổi tên thư mục
            }
        }
    }


    else{
        cout<<"Invalid command\n";
    }
}
