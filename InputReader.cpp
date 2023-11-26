#include "InputReader.h"


Move InputReader::read(std::map<int, std::string>* KeyConfig) {
    int key;
    std::cout << "Press to key:\n";
    key = _getch();
    auto it = KeyConfig->find(key);
    if (it != KeyConfig->end()) {
        if (KeyConfig->find(key)->second == "move_up")
            return move_up;
        else if (KeyConfig->find(key)->second == "move_left")
            return move_left;
        else if (KeyConfig->find(key)->second == "move_down")
            return move_down;
        else if (KeyConfig->find(key)->second == "move_right")
            return move_right;
        
       
    }
    if (key == 27)
        return escape;
    return Default;// ���� ������� �� �������
}