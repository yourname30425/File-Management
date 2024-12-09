#include"file_management.h"

using namespace std;

TreeNode::TreeNode(const std::string& n, TreeNode* p,bool isF) : name(n), isFolder(isF), parent(p) {}

// Tạo folder/file trong thư mục cha
void addChild(TreeNode* parent, const std::string& n, bool isF){
    TreeNode* child = new TreeNode(n, parent,isF);
    parent->children.push_back(child);
}
// Tìm thư mục con/file trong thư mục cha
TreeNode* findChild(TreeNode* parent, const string& name){
    for(TreeNode* child : parent->children){
        if(child->name == name) return child;
    }
    return nullptr;
}
// Liệt kê các thư mục và file trong thư mục cha
void listDirectory(TreeNode*node){
    for(TreeNode*TChild : node->children) cout<< (TChild->isFolder? " [Folder] " :" [File] ")<< TChild->name<<"\n";
}
// Xóa thư mục con/file
void deleteNode(TreeNode*node){
    if(!node->children.empty()){
        for(TreeNode*child : node->children){
            deleteNode(child);
        }
    }
    delete node;
}
// In đường dẫn của thư mục hiện tại
void printPath(TreeNode*node){
    if(node==nullptr) return;
    printPath(node->parent);
    cout<< node->name<<"\\";
}
// Duyệt cây thư mục và tìm kiếm tệp/thư mục theo tên
void findChildAndprintPath(TreeNode* parent, const string& tName) {
    if(findChild(parent, tName) == nullptr)
    { 
    //printPath(parent);
    for(TreeNode*child : parent->children)
    {
        if(child->name == tName) 
        printPath(child);
        else findChildAndprintPath(child,tName);
    }
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

