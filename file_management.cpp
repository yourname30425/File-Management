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

