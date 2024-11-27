#include<iostream>
#include<string>
#include<vetor>

using namespace std;

struct TreeNode{
    string name;
    bool isFolder;
    TreeNode* parent;
    vector<TreeNode*> childent;
    TreeNode(string& n,TreeNode* p):name(n),isFolder(n.find(".")==std::string::npos),parent(p){}
}
void addChild(TreeNode* parent,const string& name){
    TreeNode* child = new TreeNode(name,parent);
    parent->childrent.pushback(child);
}
TreeNode* findChild(TreeNode* parent, const string& name){
    for(TreeNode* child : parent->childent){
        if(child->name == name) return child;
    }
    return nullptr;
}
void listDirectory(TreeNode*node){
    for(TreeNode*TChild : node->child) cout<< (TChild->isFolder? " [Folder] " :" [File] ")<< TChild->name<<"\n";
}
void printPath(TreeNode*node){
    if(node->parent==nullptr) return;
    printPath(node->parent);
    cout<< node->name<<"\";
}

