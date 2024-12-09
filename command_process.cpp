#include"command_process.h"

using namespace std;

// Xử lý lệnh command từ người dùng
void processCommand(TreeNode** currentDir, const string& command){
    //liệt kê các thư mục và file trong thư mục hiện tại
    if(command == "ls"){
        listDirectory(*currentDir);
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
    //tạo thư mục mới
    else if(command.substr(0,6) == "mkdir "){
        string DirName = command.substr(6);
        addChild(*currentDir,DirName,true);
    }
    //tạo file mới
    else if(command.substr(0,6) == "touch "){
        string FileName = command.substr(6);
        addChild(*currentDir,FileName,false);
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
    else if(command.substr(0,6)== "rmdir"){
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
    else{
        cout<<"Invalid command\n";
    }
}
    //đổi tên file
    void renameFile(TreeNode* currentDir, const string& oldName, const string& newName) {
    // Tìm file với tên cũ
    TreeNode* fileNode = findChild(currentDir, oldName);
    
    if (fileNode != nullptr && !fileNode->isFolder) {
        // Tìm file với tên mới, nếu có thông báo lỗi
        TreeNode* existingFile = findChild(currentDir, newName);
        if (existingFile != nullptr) {
            cout << "A file with the new name already exists.\n";
        } else {
            // Đổi tên file
            fileNode->name = newName;
            cout << "File renamed to " << newName << "\n";
        }
    } else {
        cout << "No such file to rename.\n";
    }
}
