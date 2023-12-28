#include "CreateField.h"


CreateField::CreateField(GameField* gamefield,PlayerMovement* pmovement, int num_level){
	if (gamefield == nullptr || pmovement == nullptr || num_level < 0 || num_level > MAX_LEVEL) {
		throw "Error in creating a CreateField class object\n";
	}
	this->field = gamefield;
	this->movement = pmovement;
	this->level = num_level;
	Enemy<SeekAndMoveScheme, PushInteractionScheme> enemy(gamefield, pmovement);
	Miroslava = enemy;
	Enemy<RandomMoveScheme, DamageInteractionScheme> enemy1(gamefield, pmovement);
	Radmila = enemy1;
}

void CreateField::createLevel() {
	{											// 1
		for (int y = 0; y <= 4; y++) {
			field->setPassability(0, y, false);
			field->setPassability(1, y, false);    //�������1
		}

		for (int y = 7; y <= 11; y++) {
			field->setPassability(0, y, false);
			field->setPassability(1, y, false);    //�������2
		}


		for (int y = 0; y <= 3; y++) {
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);    //�����
		}

		for (int y = 7; y <= 12; y++) {
			field->setPassability(3, y, false);
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);	//�������3
		}

		for (int y = 13; y <= 15; y++) {
			field->setPassability(4, y, false);
			field->setPassability(5, y, false);    //����
		}

		for (int x = 0; x <= 5; x++) {
			field->setPassability(x, 18, false);
			field->setPassability(x, 19, false);    //���� 2
		}

		for (int y = 0; y <= 19; y++) {
			field->setPassability(6, y, false);
											  //�����
		}
		field->setPassability(6, 16);  //������
		field->setPassability(6, 17);
	}

	{										//2 
		for (int x = 7; x <= 9; x++) {
			field->setPassability(x, 0, false);
			field->setPassability(x, 1, false);    //�����
		}

		for (int x = 7; x <= 11; x++) {
			for (int y = 4; y <= 10; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //�����
			}
		}
		for (int x = 7; x <= 10; x++) {
			for (int y = 13; y <= 15; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //�����2 + �����
			}
		}

		for (int y = 5; y <= 8; y++) {
			field->setPassability(17, y, false);   //���������
		}

		for (int x = 14; x <= 18; x++) {
			field->setPassability(x, 15, false);   //c����
		}

		for (int y = 0; y <= 14; y++) {
			field->setPassability(18, y, false);   //�����
		}

		for (int y = 12; y <= 15; y++) {
			field->setPassability(16, y, false);   //���� 
			field->setPassability(17, y, false);
		}
	}

	{															//3
		for (int y = 0; y <= 5; y++) {
			field->setPassability(28, y, false);   //��� �������� 1
			field->setPassability(29, y, false);
		}

		for (int x = 19; x <= 21; x++) {
			for (int y = 2; y <= 5; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //����
			}
		}
		for (int x = 24; x <= 29; x++) {
			for (int y = 6; y <= 8; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //��� �������� + �����
			}
		}
		field->setPassability(19, 8, false);			// �����
		field->setPassability(20, 8, false);
		
	}

	{													//4
		for (int y = 9; y <= 16; y++) {
			if (y != 10 && y != 11) {
				field->setPassability(24, y, false);   //�����			
			}
		}

	
		for (int x = 25; x <= 29; x++) {
			field->setPassability(x, 13, false);   //�����+�����
			field->setPassability(x, 14, false);
		}
		for (int x = 24; x <= 29; x++) {
			field->setPassability(x, 19, false);   //c���� +�����
			field->setPassability(x, 18, false);

		}

		for (int x = 27; x <= 29; x++) {
			for (int y = 15; y <= 18; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);    //�����
			}
		}

		for (int x = 14; x <= 19; x++) {
			field->setPassability(x, 18, false);   //����
			field->setPassability(x, 19, false);
		}


		field->setPassability(24, 10, true);
		field->setPassability(24, 11, true);


		for (int x = 25; x <= 29; x++) {
			for (int y = 9; y <= 12; y++) {
				field->setPassability(x, y, true);
				
			}
		}
		for (int x = 28; x <= 29; x++) {
			for (int y = 10; y <= 11; y++) {
				field->setPassability(x, y, false);

			}
		}
		field->setPassability(24, 16);
		field->setPassability(25, 15);
		field->setPassability(26, 15);
	}

	field->setStart(5, 5);
	field->setEnd(17, 0);
	movement->setCoordinates(field->getStartX(), field->getStartY());
	Miroslava.setCoord(10, 12);
	Radmila.setCoord(21,9);

	if (this->level == 1) {
		std::cout << "Create 1 level..\n";
		auto* collectPoint = new CollectAPoint(movement);
		
		auto* reducedHealth = new ReducedHealth(movement);
		this->setEventCF(reducedHealth, 15);
		this->setEventCF(collectPoint, SCORE);
		//

		
		/**/
		
	}
	else if (level == 2){
		std::cout << "Create 2 level..\n";
		
		auto* teleport = new Teleport(movement);
		for (int x = 24; x <= 29; x++) {
			for (int y = 9; y <= 12; y++) {
				field->setPassability(x, y, false);
				field->setPassability(x, y, false);
			}
		}
		field->setPassability(27, 6);
		field->setEvent(teleport, 27, 6);

		auto* collectPoint = new CollectAPoint(movement);
		this->setEventCF(collectPoint, SCORE);
		auto* addingHealth = new AddingHealth(movement);
		this->setEventCF(addingHealth, 3);
		auto* reducedHeath = new ReducedHealth(movement);
		this->setEventCF(reducedHeath,15);


		for (int x = 25; x <= 29; x++) {
			for (int y = 9; y <= 12; y++) {
				field->setPassability(x, y, true);

			}
		}
		for (int x = 28; x <= 29; x++) {
			for (int y = 10; y <= 11; y++) {
				field->setPassability(x, y, false);

			}
		}

		auto* doubleScore = new DoubleScore(movement);
		
		for (int x = 25; x <= 27; x++) {
			for (int y = 9; y <= 12; y++) {
				field->setEvent(doubleScore,x, y);

			}
		}
		
	}
	else {
		throw "There is no such level, wait for the update";
	}
}
void CreateField::setEventCF(EventInterface* event, int quantity) {
	
		srand(time(0));
		int flag = 0;
		while (flag < quantity) {
			int coordX = rand() % field->getWidth();
			int coordY = rand() % field->getHeight();
			if (field->getPassability(coordX, coordY) && not(field->isEvent(coordX, coordY))) {
				
					
					field->setEvent(event, coordX, coordY);
					flag++;
				
				
				
			}
		}
	
}

int CreateField::getLevel() {
	return this->level;
}

void CreateField::setLevel(int num_level){
	this->level = num_level;
}


void CreateField::moveEnemyM()
{
	Miroslava.Move();
	Miroslava.Interact();
	Miroslava.printQ();
}

Coord CreateField::getCoordM()
{
	Coord w{ Miroslava.getCoordX(), Miroslava.getCoordY() };
	return w;
}



void CreateField::moveEnemyR()
{
	Radmila.Move();
	Radmila.Interact();
	Radmila.printQ();
}

Coord CreateField::getCoordR()
{
	Coord w{ Radmila.getCoordX(), Radmila.getCoordY() };
	return w;
}

