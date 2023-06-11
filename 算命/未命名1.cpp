#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 
#include <fstream>
#include <string>


using namespace std;

void showMenu()
{
    cout << "便捷算命系统" << endl;
    cout << "选择选项：" << endl;
    cout << "1. 开始" << endl;
    cout << "2. 退出" << endl;
}

void displayFileContent(const std::string& filename) {
    std::ifstream file(filename); // 打开文件
    if (file.is_open()) { // 判断文件是否成功打开
        std::string line;
        while (std::getline(file, line)) { // 逐行读取文件内容
            std::cout << line << std::endl; // 输出每行内容
        }
        file.close(); // 关闭文件
    } else {
        std::cout << "Unable to open file" << std::endl; // 文件打开失败
    }
}

int main()
{
    srand(time(NULL)); // 设置随机数种子

    int option;
    do {
        system("cls"); // 清屏
        showMenu(); // 展示菜单
        cin >> option; // 获取用户选择的选项

        switch (option)
        {
            case 1:
            {
                int count2 = 0, count3 = 0; // 初始化2和3出现的次数为0
                int nums[6]; // 定义一个数组，用于存储随机生成的数字

                for (int j = 0; j < 6; j++) // 展示六个数字
                {
                    int num = rand() % 4 + 1; // 生成1~4之间的随机数
                    nums[j] = num; // 将生成的数字存入数组中

                    switch (num) // 使用switch语句将数字转换为字母
                    {
                        case 1:
                            cout << "— —\n";
                            break;
                        case 2:
                            cout << "— —x\n";
                            count2++; // 2出现的次数加1
                            break;
                        case 3:
                            cout << "---x\n";
                            count3++; // 3出现的次数加1
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                    }
                }

                cout << endl; // 换行

                // 根据2和3出现的次数输出汉字
                int sum = count2 + count3;
                switch (sum)
                {
                    case 0:
                        cout << "按照本卦卦意\n";
                        break;
                    case 1:
                        cout << "按照变爻爻辞\n";
                        break;
                    case 2:
                        cout << "按照上面的变爻爻辞\n";
                        break;
                    case 3:
                        cout << "按照本卦与变卦卦辞\n";
                        if (sum == 3) 
                        {
                          for (int i = 0; i < 6; i++) {
        						 switch (nums[i]) 
                   		 {
                        case 1:
                            cout << "— —\n";
                            break;
                        case 2:
                            cout << "---\n";
                            break;
                        case 3:
                            cout << "— —\n";
                          
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                   		 }
  				  }
                           
                           
                        }
                        break;
                    case 4:
                        cout << "按照不变爻辞中的下爻爻辞\n";
                        break;
                    case 5:
                        cout << "按照不变的爻辞\n";
                        break;
                    case 6:
                        cout << "按照变卦卦意\n";
                        if (sum == 6)
                        {
                            for (int i = 0; i < 6; i++) {
        						 switch (nums[i]) 
                   		 {
                        case 1:
                            cout << "— —\n";
                            break;
                        case 2:
                            cout << "---\n";
                            break;
                        case 3:
                            cout << "— —\n";
                          
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                   		 }
  				  } 
                             
                             
                        }
                        break;
                }
				std::string filename = "gua/114.txt"; // 文件名
    			displayFileContent(filename); // 调用函数显示文件内容
    			return 0;
                

                cout << "按下任意键继续" << endl;
                getch(); // 等待用户按下任意键
                option = 0; // 将选项设置为0，使选择界面再次展示
                break;
            }
            case 2:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    } while (option != 2); // 如果用户选择的不是退出，则继续循环展示菜单

    return 0;
}
