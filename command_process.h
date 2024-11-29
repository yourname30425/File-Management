#ifndef COMMAND_PROCESS_H
#define COMMAND_PROCESS_H

#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "file_management.h"
//hàm xử lý lệnh command từ người dùng
void processCommand(TreeNode** currentDir,const std::string& command);

#endif // COMMAND_PROCESS_H