#include"command_process.h"

using namespace std;

void processCommand(TreeNode* currentDir, const string& command){
    if(command == "ls"){
        listDirectory(currentDir);
    }
    else if(command == "pwd"){
        printPath(currentDir);
        cout<<"\n";
    }
    else if(command.substr(0,3) == "cd "){
        string DirName = command.substr(3);
        if(DirName == ".."){
            if(currentDir->parent != nullptr){
                currentDir = currentDir->parent;
            }
        }else{
            TreeNode* child = findChild(currentDir,DirName);
            if(child != nullptr && child->isFolder){
                currentDir = child;
            }else{
                cout<<"No such directory\n";
            }
        }
    }
    else if(command.substr(0,6) == "mkdir "){
        string DirName = command.substr(6);
        addChild(currentDir,DirName,true);
    }
    else if(command.substr(0,6) == "touch "){
        string FileName = command.substr(6);
        addChild(currentDir,FileName,false);
    }
    else if(command.substr(0,3) == "rm "){
        string FileName = command.substr(3);
        TreeNode* child = findChild(currentDir,FileName);
        if(child != nullptr && !child->isFolder){
            currentDir->children.erase(remove(currentDir->children.begin(),currentDir->children.end(),child),currentDir->children.end());
            delete child;
        }
        else{
            cout<<"No such file\n";
        }
    }
    else if(command.substr(0,6)== "rmdir"){
        string DirName = command.substr(6);
        TreeNode* child = findChild(currentDir,DirName);
        if(child != nullptr && child->isFolder){
            deleteNode(child);
            currentDir->children.erase(remove(currentDir->children.begin(),currentDir->children.end(),child),currentDir->children.end());
        }
        else{
            cout<<"No such directory\n";
        }
    }
    else{
        cout<<"Invalid command\n";
    }
}