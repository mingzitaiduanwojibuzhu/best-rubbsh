#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 
#include <fstream>
#include <string>


using namespace std;

void showMenu()
{
    cout << "�������ϵͳ" << endl;
    cout << "ѡ��ѡ�" << endl;
    cout << "1. ��ʼ" << endl;
    cout << "2. �˳�" << endl;
}

void displayFileContent(const std::string& filename) {
    std::ifstream file(filename); // ���ļ�
    if (file.is_open()) { // �ж��ļ��Ƿ�ɹ���
        std::string line;
        while (std::getline(file, line)) { // ���ж�ȡ�ļ�����
            std::cout << line << std::endl; // ���ÿ������
        }
        file.close(); // �ر��ļ�
    } else {
        std::cout << "Unable to open file" << std::endl; // �ļ���ʧ��
    }
}

int main()
{
    srand(time(NULL)); // �������������

    int option;
    do {
        system("cls"); // ����
        showMenu(); // չʾ�˵�
        cin >> option; // ��ȡ�û�ѡ���ѡ��

        switch (option)
        {
            case 1:
            {
                int count2 = 0, count3 = 0; // ��ʼ��2��3���ֵĴ���Ϊ0
                int nums[6]; // ����һ�����飬���ڴ洢������ɵ�����

                for (int j = 0; j < 6; j++) // չʾ��������
                {
                    int num = rand() % 4 + 1; // ����1~4֮��������
                    nums[j] = num; // �����ɵ����ִ���������

                    switch (num) // ʹ��switch��佫����ת��Ϊ��ĸ
                    {
                        case 1:
                            cout << "�� ��\n";
                            break;
                        case 2:
                            cout << "�� ��x\n";
                            count2++; // 2���ֵĴ�����1
                            break;
                        case 3:
                            cout << "---x\n";
                            count3++; // 3���ֵĴ�����1
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                    }
                }

                cout << endl; // ����

                // ����2��3���ֵĴ����������
                int sum = count2 + count3;
                switch (sum)
                {
                    case 0:
                        cout << "���ձ�������\n";
                        break;
                    case 1:
                        cout << "���ձ�سس��\n";
                        break;
                    case 2:
                        cout << "��������ı�سس��\n";
                        break;
                    case 3:
                        cout << "���ձ���������Դ�\n";
                        if (sum == 3) 
                        {
                          for (int i = 0; i < 6; i++) {
        						 switch (nums[i]) 
                   		 {
                        case 1:
                            cout << "�� ��\n";
                            break;
                        case 2:
                            cout << "---\n";
                            break;
                        case 3:
                            cout << "�� ��\n";
                          
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                   		 }
  				  }
                           
                           
                        }
                        break;
                    case 4:
                        cout << "���ղ���س���е���سس��\n";
                        break;
                    case 5:
                        cout << "���ղ����س��\n";
                        break;
                    case 6:
                        cout << "���ձ�������\n";
                        if (sum == 6)
                        {
                            for (int i = 0; i < 6; i++) {
        						 switch (nums[i]) 
                   		 {
                        case 1:
                            cout << "�� ��\n";
                            break;
                        case 2:
                            cout << "---\n";
                            break;
                        case 3:
                            cout << "�� ��\n";
                          
                            break;
                        case 4:
                            cout << "---\n";
                            break;
                   		 }
  				  } 
                             
                             
                        }
                        break;
                }
				std::string filename = "gua/114.txt"; // �ļ���
    			displayFileContent(filename); // ���ú�����ʾ�ļ�����
    			return 0;
                

                cout << "�������������" << endl;
                getch(); // �ȴ��û����������
                option = 0; // ��ѡ������Ϊ0��ʹѡ������ٴ�չʾ
                break;
            }
            case 2:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    } while (option != 2); // ����û�ѡ��Ĳ����˳��������ѭ��չʾ�˵�

    return 0;
}
