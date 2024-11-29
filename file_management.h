#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

// Define the TreeNode structure
struct TreeNode {
    std::string name;
    bool isFolder;
    TreeNode* parent;
    std::vector<TreeNode*> children;
    TreeNode(const std::string& n, TreeNode* p, bool isF); // Updated constructor
};

void addChild(TreeNode* parent, const std::string& name,bool isF);

TreeNode* findChild(TreeNode* parent, const std::string& name);

void listDirectory(TreeNode*node);

void printPath(TreeNode*node);

void deleteNode(TreeNode*node);
#endif // FILE_MANAGEMENT_H