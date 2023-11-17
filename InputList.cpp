#include "InputList.h"

InputList::InputList()
{

}

void InputList::InputSettingsReaderL()
{
	int key;
	for (auto start{ commands.begin() }; start != commands.end(); start++) {
		std::cout << *start << ":";
		key = _getch();
		keyMap[key] = *start;
	}
	std::cout << "\n";
	for (const auto& p : keyMap)
		std::cout << p.first << " " << p.second << std::endl;
}



std::map<int, std::string>* InputList::getKeyList() {
	return &keyMap;
}