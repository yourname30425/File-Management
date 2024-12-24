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

// Hàm đệ quy để liệt kê tất cả thư mục và file từ thư mục hiện tại
void listSubtree(TreeNode* node, const string& indent) {
    // Hiển thị node hiện tại
    cout << indent << (node->isFolder ? "[Folder] " : "[File] ") << node->name << "\n";
    
    // Duyệt qua tất cả các thư mục và file con
    for (TreeNode* child : node->children) {
        listSubtree(child, indent + "  ");  // Thêm indent cho node con
    }
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
    if(parent == nullptr) return; 
    for(TreeNode*child : parent->children)
    {
        if(parent->name == tName)
        { 
        cout<<"Path:";
        printPath(parent);
        cout<<"\n";
        }
        findChildAndprintPath(child,tName);
    }
}

// Hàm đổi tên thư mục
void renameFolder(TreeNode* currentDir, const string& oldName, const string& newName) {
    // Tìm thư mục với tên cũ
    TreeNode* folderNode = findChild(currentDir, oldName);

    if (folderNode != nullptr && folderNode->isFolder) {
        // Tìm thư mục với tên mới, nếu có thông báo lỗi
        TreeNode* existingFolder = findChild(currentDir, newName);
        if (existingFolder != nullptr) {
            cout << "A folder with the new name already exists.\n";
        } else {
            // Đổi tên thư mục
            folderNode->name = newName;
            cout << "Folder renamed to " << newName << "\n";
        }
    } else {
        cout << "No such folder to rename.\n";
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

// Hàm để xóa màn hình terminal
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Lệnh xóa màn hình trên Windows
    #else
        system("clear");  // Lệnh xóa màn hình trên Unix-based systems (Linux, macOS)
    #endif
} 

// Hàm hiển thị công dụng các lệnh
void showHelp() {
    cout<<"\033[32m";
    cout << "\033[31m Welcome to File Explorer Stimulation\n \033[32m";
    cout << "-------------------------------------------\n";
    cout << "\033[33m List of available commands and their usage:\n \033[32m";
    cout << "-------------------------------------------\n";
    cout << "1. cls                 - Clear the terminal screen.\n";
    cout << "2. ls                  - List all files and directories in the current directory.\n";
    cout << "3. lss                 - List all files, directories and their subfiles, subfolders in the current directory.\n";
    cout << "4. pwd                 - Print the current directory path.\n";
    cout << "5. cd <dir>            - Change to directory <dir>. Use '..' to move to parent directory.\n";
    cout << "6. cdd                 - Move to Root\n";
    cout << "7. mkdir <dir>         - Create a new directory with name <dir>.\n";
    cout << "8. touch <file>        - Create a new file with name <file>.\n";
    cout << "9. rm <file>           - Remove a file with name <file>.\n";
    cout << "10. rmdir <dir>        - Remove a directory with name <dir>.\n";
    cout << "11. find <name>        - Find and print the path of a folder/a file with name <name>.\n";
    cout << "12. sort               - Sort the contents of the current directory by name.\n";       
    cout << "13. rename <old> <new> - Rename a file from <old> name to <new> name.\n";
    cout << "14. help               - Show all commands and their usage\n";
    cout << "-------------------------------------------\n";
    cout << "Type any of these commands to perform the action.\n";
    cout<<"\033[0m";

}

// Hàm đệ quy để liệt kê tất cả thư mục và file từ thư mục hiện tại
void listSubtree(TreeNode* node, const string& indent) {
    // Hiển thị node hiện tại
    cout << indent << (node->isFolder ? "[Folder] " : "[File] ") << node->name << "\n";
    
    // Duyệt qua tất cả các thư mục và file con
    for (TreeNode* child : node->children) {
        listSubtree(child, indent + "  ");  // Thêm indent cho node con
    }
}

// Hàm để chuyển đến thư mục gốc (root)
void goToRoot(TreeNode** currentDir) {
    if (*currentDir == nullptr) return;
    
    while ((*currentDir)->parent != nullptr) {
        *currentDir = (*currentDir)->parent;
    }

    cout << "You are now in the root directory.\n";
}
//hàm kiểm tra xem thư mục cha có thư mục con không
bool checkChild(TreeNode* parent, const string& name){
    for(TreeNode* child : parent->children){
        if(child->name == name) return true;
    }
    return false;
}


void quickSort(vector<TreeNode*>& children, int low, int high) {
    if (low < high) {
        // Phân hoạch mảng
        int pivotIndex = partition(children, low, high);

        // Gọi đệ quy sắp xếp các phần bên trái và phải của pivot
        quickSort(children, low, pivotIndex - 1);
        quickSort(children, pivotIndex + 1, high);
    }
}

int partition(vector<TreeNode*>& children, int low, int high) {
    TreeNode* pivot = children[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        // So sánh theo tên
        if (children[j]->name <= pivot->name) {
            ++i;
            swap(children[i], children[j]); // Hoán đổi các phần tử
        }
    }

    // Đưa pivot về đúng vị trí
    swap(children[i + 1], children[high]);
    return i + 1; // Trả về chỉ số pivot
}

void sortChildren(TreeNode* currentDir) {
    if (!currentDir || currentDir->children.empty()) {
        cout << "No items to sort.\n";
        return;
    }

    vector<TreeNode*>& children = currentDir->children;

    // Gọi Quick Sort trên danh sách các phần tử con
    quickSort(children, 0, children.size() - 1);
}
