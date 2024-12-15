#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>



using namespace std;

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

void findChildAndprintPath(TreeNode* parent, const string& tName);

void renameFolder(TreeNode* currentDir, const string& oldName, const string& newName);

void renameFile(TreeNode* currentDir, const string& oldName, const string& newName);

void clearScreen();

void showHelp();

void listSubtree(TreeNode* node, const string& indent = "");

void goToRoot(TreeNode** currentDir);

#endif // FILE_MANAGEMENT_H