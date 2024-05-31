#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std;
int s;
string deviceName = "input";
string projectName = "input";
string bootVer = "input";
string patchVer = "input";
string toolAuth = "input";
string buildDate = "input";
string bootImg = "input";
string apkFile = "input";
string Group = "input";

void MENU(); 
void FLASH_OVER();
void FLASH_FAILED();
void FLASHING();
void REBOOT_BOOTLOADER();
void IN_SYSTEM();
void FASTBOOT_MODE();
void INSTALL_APK();
void OTHERS(); 
bool CheckADBDevices();

int main()
{
    system("color 3f");
    system(("TITLE " + deviceName + "һ��ˢ��Boot���� --By " + toolAuth).c_str());
    cout << endl;
    cout << "     " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "           Rec������Ϣ" << endl;
    cout << "      Boot���� ��" << projectName << endl;
    cout << "      Boot�汾 ��" << bootVer << endl;
    cout << "      Patch�汾��" << patchVer << endl;
    cout << "      ������ͣ�" << deviceName << endl;
    cout << "      �������ߣ�" << toolAuth << endl;
    cout << "      ����ʱ�䣺" << buildDate << endl;
    cout << "      ˢ������Ⱥ��" << Group << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "���س�������..." << endl;
    cin.get();
    system("cls");
    MENU();
    system("pause");
    return 0;
}

void MENU()
{
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "	��ѡ���ܣ�" << endl;
    cout << "	1. �ڿ���״̬��ˢ��" << endl;
    cout << "	2. ��fastbootģʽ��ˢ��" << endl;
    cout << "	3. ��װKernelSUӦ��" << endl;
    cout << "	4. ����״̬" << endl;
    cout << "***********************************************" << endl;
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "��ѡ���˿���״̬������ִ��������Bootloader����.." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            IN_SYSTEM();
            return;
        case 2:
            cout << "��ѡ����fastbootģʽ������ִ��ˢ�����..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            FASTBOOT_MODE();
            return;
        case 3:
            cout << "��ѡ���˰�װKernelSUӦ�ã�����ִ�а�װ����..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            INSTALL_APK(); 
            return;
        case 4:
            cout << "��ѡ��������״̬���뽫�ֻ��л�������״̬��fastbootģʽ��" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            this_thread::sleep_for(chrono::seconds(1));
            OTHERS();
            this_thread::sleep_for(chrono::seconds(6));
            system("cls");
            MENU();
            return;
        default:
            cout << "��Ч��ѡ��������ѡ��" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            MENU();
            return;
        }

        cout << "����������ز˵�" << endl;
        cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

    } while (choice != 0);
    cout << "��лʹ�ã��ټ���" << endl;
    cout << "******************************" << endl;
}

void FLASH_OVER()
{
    system("cls");
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "             ˢдBoot���" << endl;
    cout << endl;
    cout << "            �ֻ�����������ϵͳ" << endl;
    cout << endl;
    cout << "           " << toolAuth << "��л��ʹ�ñ�����" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "           ����������رմ˴��ڣ�" << endl;
    cout << endl;
    system("fastboot reboot");
    cin.get();
    return;
}

void FLASH_FAILED()
{
    system("cls");
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "                   ˢ��ʧ�ܣ�" << endl;
    cout << endl;
    cout << "           1.�����ֻ��ͺ��Ƿ���ȷ" << endl;
    cout << "           2.��ȷ��fastboot�Ƿ�����" << endl;
    cout << "           3.��ѹ���������б�����" << endl;
    cout << "             �������ɹ�������ϵ����" << endl;
    cout << endl;
    cout << "           " << toolAuth << "��л��ʹ�ñ�����" << endl;
    cout << endl;
    cout << "            ����������˳�����" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    return;
}

void FLASHING()
{
    system("cls");
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          ���ڽ���ˢ��Boot����" << endl
         << endl;
    cout << "      �������ʱ��ͣ���ڴ˽��棬���飺��" << endl;
    cout << endl;
    cout << "      ��1.USB���Ƿ���ȷ���ӡ�" << endl;
    cout << "      ��2.���������Ƿ���ȷ��װ��ʶ��" << endl;
    cout << "      ��3.�ֻ��Ƿ����fastbootģʽ��" << endl;
    cout << endl;
    cout << "             ���������ù��ߣ�" << endl;
    cout << "***********************************************" << endl;
    int result = system(("fastboot flash boot " + bootImg).c_str());
    if (result == 0)
    {
        FLASH_OVER();
    }
    else
    {
        FLASH_FAILED();
    }
    return;
}

void REBOOT_BOOTLOADER()
{
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "             �ֻ�������..." << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "   ������ʱ��ͣ���ڴ˽��棬�������ù��ߣ�" << endl;
    int result = system("adb reboot bootloader");
    if (result == 0)
    {
        FLASHING();
    }
    return;
}

void IN_SYSTEM()
{
	system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "            ��ȷ����" << endl;
    cout << "       ��1.�ֻ�bootloaderδ����" << endl;
    cout << "       ��2.�ֻ����ڿ���״̬��" << endl;
    cout << "       ��3.�ֻ�����USB���ԡ�" << endl;
    cout << "       ��4.�������Ѿ���ȷ��װ������" << endl;
    cout << "       ��5.�ֻ���ʾUSB������Ȩʱ��ѡʼ�յ����Ȩ��" << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "  " << "���ڼ���豸�Ƿ���������..." << endl;
    cout << endl;
    cout << "   ������ʱ��ͣ���ڴ˽��棬�����������" << endl;
    cout << "***********************************************" << endl;
    char choice;  
    bool shouldContinue = true;
    while (shouldContinue) {  
        if (CheckADBDevices()) {  
            std::cout << "ADB�豸���ɹ����ѷ��������ӵ��豸��" << std::endl;
            std::cout << "�豸���������������Bootloader..." << std::endl;
			this_thread::sleep_for(chrono::seconds(2));   
            return REBOOT_BOOTLOADER();  
        } else {  
            std::cerr << "ADB�豸���ʧ�ܣ��������ӣ�" << std::endl;  
            char choice;  
            do {  
                std::cout << "�� r ���¼�飬������ q �˳�: ";  
                std::cin >> choice;   
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            } while (choice != 'r' && choice != 'R' && choice != 'q' && choice != 'Q');  
  
            if (choice == 'r' || choice == 'R') {    
            } else if (choice == 'q' || choice == 'Q') {   
                shouldContinue = false;  
            }  
        }  
    }
}

void FASTBOOT_MODE()
{
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "          ��ȷ����" << endl;
    cout << "        ��1.�ֻ�bootloaderδ����" << endl;
    cout << "        ��2.�ֻ�����fastbootģʽ��" << endl;
    cout << "        ��3.�������Ѿ���ȷ��װ������" << endl;
    cout << endl;
    cout << "            �����������������" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    FLASHING();
    return;
}

void OTHERS()
{
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "             ���Ƚ��ֻ�����" << endl;
    cout << endl;
    cout << "               ������״̬��" << endl;
    cout << "                  ����" << endl;
    cout << "             ��fastbootģʽ��" << endl;
    cout << endl;
    cout << "          (�޲�����6����Զ�����)" << endl;
    cout << "***********************************************" << endl;
}

void INSTALL_APK()
{
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " һ��ˢ��Boot����" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          �������ֻ���ȷ���ӵ����ԣ�" << endl;
    cout << endl;
    cout << "          ��ȷ����" << endl;
    cout << "        ��1.�ֻ�������USB���ԡ�" << endl;
    cout << "        ��2.�����Ѱ�װADB������" << endl;
    cout << "        ��3.�ֻ�������Ȩ�˵��Եĵ���Ȩ�ޡ�" << endl;
    cout << "          ��������Ȩ�����ֶ���Ȩ" << endl;
    cout << endl;
    cout << "            �����������������" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    int adbDevicesResult = system("adb devices");  
    if (adbDevicesResult != 0) {  
        std::cerr << "ADB�豸���ʧ�ܣ��������ӣ�" << std::endl;  
        return;  
    }   
    std::string installCommand = "adb install " + apkFile;  
    int installResult = system(installCommand.c_str());  
    if (installResult != 0) {  
        std::cerr << "APK��װʧ�ܣ������ļ�·����ADB���ӣ�" << std::endl;  
    } else {  
        std::cout << "APK��װ�ɹ���" << std::endl;  
    }
    this_thread::sleep_for(chrono::seconds(2));
	system("cls");  
    return MENU();  
}  
bool CheckADBDevices() {  
    std::string adbOutput = "";  
    FILE* pipe = popen("adb devices", "r");  
    if (!pipe) {  
        std::cerr << "Failed to execute adb devices" << std::endl;  
        return false;  
    }  
  
    char buffer[128];  
    while (fgets(buffer, sizeof(buffer), pipe)) {  
        adbOutput += buffer;  
    }  
    pclose(pipe);  
  
    // �����б������  
    std::istringstream iss(adbOutput);  
    std::string line;  
    std::getline(iss, line); // ��ȡ�������б�����У����� "List of devices attached"  
  
    // �����������Ƿ���� "device"  
    bool foundDevice = false;  
    while (std::getline(iss, line)) {  
        if (line.find("device") != std::string::npos) {  
            foundDevice = true;  
            break;  
        }  
        // Ҳ���Լ���Ƿ���� "offline" ����������Ҫ��״̬  
    }  
  
    // ���adbOutput��û���豸��Ϣ������ֻ�б����кͿ��У�������Ϊû���豸  
    if (adbOutput.find("device") == std::string::npos &&  
        adbOutput.find("offline") == std::string::npos) {  
        // ���������Ӷ�����߼�������ֻ�б����кͿ��е����  
        foundDevice = false;  
    }  
  
    return foundDevice;  
} 
