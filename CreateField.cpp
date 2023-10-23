#include "CreateField.h"


CreateField::CreateField(GameField* gamefield,PlayerMovement* pmovement, int num_level){
	if (gamefield == nullptr || pmovement == nullptr || num_level < 0) {
		throw "Error in creating a CreateField class object\n";
	}
	this->field = gamefield;
	this->movement = pmovement;
	this->level = num_level;
	createLevel(level);
}

void CreateField::createLevel(int level) {
	{											// 1
		for (int y = 0; y <= 4; y++) {
			field->setPassability(0, y, false);
			field->setPassability(1, y, false);    //кровать1
		}

		for (int y = 7; y <= 11; y++) {
			field->setPassability(0, y, false);
			field->setPassability(1, y, false);    //кровать2
		}


		for (int y = 0; y <= 3; y++) {
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);    //комод
		}

		for (int y = 7; y <= 12; y++) {
			field->setPassability(3, y, false);
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);	//кровать3
		}

		for (int y = 13; y <= 15; y++) {
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);    //шкаф
		}

		for (int x = 0; x <= 5; x++) {
			field->setPassability(x, 18, false);
			field->setPassability(x, 19, false);    //шкаф 2
		}

		for (int y = 0; y <= 19; y++) {
			field->setPassability(6, y, false);
											  //стена
		}
		field->setPassability(6, 16);  //проход
		field->setPassability(6, 17);
	}

	{										//2 
		for (int x = 7; x <= 9; x++) {
			field->setPassability(x, 0, false);
			field->setPassability(x, 1, false);    //тумба
		}

		for (int x = 7; x <= 11; x++) {
			for (int y = 4; y <= 10; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //диван
			}
		}
		for (int x = 7; x <= 10; x++) {
			for (int y = 13; y <= 15; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //тумба2 + стена
			}
		}

		for (int y = 5; y <= 8; y++) {
			field->setPassability(17, y, false);   //телевизор
		}

		for (int x = 14; x <= 18; x++) {
			field->setPassability(x, 15, false);   //cтена
		}

		for (int y = 0; y <= 14; y++) {
			field->setPassability(18, y, false);   //стена
		}

		for (int y = 12; y <= 15; y++) {
			field->setPassability(16, y, false);   //стол 
			field->setPassability(17, y, false);
		}
	}

	{															//3
		for (int y = 0; y <= 5; y++) {
			field->setPassability(28, y, false);   //кух гарнитур 1
			field->setPassability(29, y, false);
		}

		for (int x = 19; x <= 21; x++) {
			for (int y = 2; y <= 5; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //стол
			}
		}
		for (int x = 24; x <= 29; x++) {
			for (int y = 6; y <= 8; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //кух гарнитур + стена
			}
		}
		field->setPassability(19, 8, false);			// стена
		field->setPassability(20, 8, false);

	}

	{													//4
		for (int y = 9; y <= 16; y++) {
			field->setPassability(24, y, false);   //стена			
		}

		for (int x = 25; x <= 29; x++) {
			field->setPassability(x, 13, false);   //ванна+стена
			field->setPassability(x, 14, false);
		}
		for (int x = 24; x <= 29; x++) {
			field->setPassability(x, 19, false);   //cтена +ванна
		}

		for (int x = 27; x <= 29; x++) {
			for (int y = 15; y <= 18; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //ванна
			}
		}

		for (int x = 15; x <= 19; x++) {
			field->setPassability(x, 18, false);   //шкаф
			field->setPassability(x, 19, false);
		}
	}

	field->setStart(5, 5);
	field->setEnd(17, 0);


	if (level == 1) {

		auto* addingHealth = new AddingHealth(movement);
		field->setEvent(addingHealth, 9, 19);
		
	}
	else if (level ==2){
		auto* teleport = new Teleport(movement);
		field->setEvent(teleport, 7, 9);
		auto* addingHealth = new AddingHealth(movement);
		field->setEvent(addingHealth, 9, 19);
		auto* reducedHeath = new ReducedHealth(movement);
		field->setEvent(reducedHeath, 23, 10);
		

	}
	
}
