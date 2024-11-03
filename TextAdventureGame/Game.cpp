#include <string>
#include <iostream>
using namespace std;



struct Item
{
	string name;
	float damage;
	string effects;
};

struct Enemy
{
	string name;
	float health;
	float damage;
	string type;
};

struct Room
{
	bool cleared;
	Enemy enemy;
	Item reward;
};

class playerMovement
{
public:
	Room RoomMod[4][4];

	void moveLeft()
	{
		
	}
	void moveRight()
	{

	}
	void moveUp()
	{

	}
	void moveDown()
	{

	}
};

struct Player
{
	float health;
	float damage;
	Item heldItem;
	int score;
};

Room room[4][4];
int temp;

Enemy posEnemies[15];

string namePicker()
{
	temp = rand() % 10;
	switch (temp)
	{
	case 0:
		return "boobs";
		break;
	case 1:
		return "boob";
		break;
	case 2:
		return "boos";
		break;
	case 3:
		return "bo";
		break;
	case 4:
		return "bs";
		break;
	case 5:
		return "bobs";
		break;
	case 6:
		return "oobs";
		break;
	case 7:
		return "obs";
		break;
	case 8:
		return "b";
		break;
	case 9:
		return "boobies";
		break;
	default:
		return "error";
		break;
	}

}

void setup()
{
	for (int i = 0; i < 15; i++)
	{
		posEnemies[i].name = namePicker();
	}
	
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			room[i][j].enemy.damage = rand() % 100 + 300;
		}
	}
}

int main()
{
	setup();
	for (int i = 0; i < 15; i++)
	{
		cout << posEnemies[i].name << endl;
	}
}



