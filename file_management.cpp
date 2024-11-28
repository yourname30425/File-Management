#include"file_management.h"

using namespace std;

TreeNode::TreeNode(const std::string& n, TreeNode* p,bool isF) : name(n), isFolder(isF), parent(p) {}


void addChild(TreeNode* parent, const std::string& n, bool isF){ {
    TreeNode* child = new TreeNode(n, parent,isF);
    parent->children.push_back(child);
}
TreeNode* findChild(TreeNode* parent, const string& name){
    for(TreeNode* child : parent->children){
        if(child->name == name) return child;
    }
    return nullptr;
}
void listDirectory(TreeNode*node){
    for(TreeNode*TChild : node->children) cout<< (TChild->isFolder? " [Folder] " :" [File] ")<< TChild->name<<"\n";
}
void deleteNode(TreeNode*node){
    if(node->children!=nullptr){
        for(TreeNode*child : node->children){
            deleteNode(child);
        }
    }
    delete node;
}
void printPath(TreeNode*node){
    if(node->parent==nullptr) return;
    printPath(node->parent);
    cout<< node->name<<'/';
}

