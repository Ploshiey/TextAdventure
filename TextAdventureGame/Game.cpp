#include <string>
#include <iostream>
#pragma once
using namespace std;

#pragma region structs
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
	int number;
	bool cleared;
	Enemy enemy;
	Item reward;
};

struct Player
{
	float health;
	float damage;
	Item heldItem;
	int score;
};
#pragma endregion

#pragma region classes
class playerMovement
{
public:
	int roompoz;

	int moveLeft(int other)
	{
		return
		{
			other - 1
		};
	}
	int moveRight(int other)
	{
		return
		{
			other + 1
		};
	}
	int moveUp(int other)
	{
		return
		{
			other + 4
		};
	}
	int moveDown(int other)
	{
		return
		{
			other - 4
		};
	}
};

#pragma endregion

Room room[4][4];
int currRoom;
int temp;

Enemy Enemies[15];

Enemy enemyPicker(Enemy enemy)
{
	temp = rand() % 6;
	switch (temp)
	{
	case 0:
		
		enemy.name = "Slime";
		enemy.damage = 5;
		enemy.health = 10;
		enemy.type = "Jelly";
		return
		{
			enemy
		};
		break;
	case 1:
		enemy.name = "Skelly";
		enemy.damage = 20;
		enemy.health = 15;
		enemy.type = "Dead";
		return 
		{
			enemy
		};
		break;
	case 2:
		enemy.name = "Hound";
		enemy.damage = 25;
		enemy.health = 40;
		enemy.type = "Floor";
		return 
		{
			enemy
		};
		break;
	case 3:
		enemy.name = "Zombie";
		enemy.damage = 50;
		enemy.health = 30;
		enemy.type = "Dead";
		return
		{
			enemy
		};
		break;
	case 4:
		enemy.name = "Demon";
		enemy.damage = 75;
		enemy.health = 100;
		enemy.type = "Sky";
		return
		{
			enemy
		};
		break;
	case 5:
		enemy.name = "Rat";
		enemy.damage = 1;
		enemy.health = 1;
		enemy.type = "Thief";
		return
		{
			enemy
		};
		break;
	default:
		return enemy;
		break;
	}
}

void setup()
{
	for (int i = 0; i < 15; i++)
	{
		Enemies[i] = enemyPicker(Enemies[i]);
	}
	
	room[0][0].enemy = Enemies[0];
	room[0][1].enemy = Enemies[1];
	room[0][2].enemy = Enemies[2];
	room[0][3].enemy = Enemies[3];
	room[1][0].enemy = Enemies[4];
	room[1][1].enemy = Enemies[5];
	room[1][2].enemy = Enemies[6];
	room[1][3].enemy = Enemies[7];
	room[2][0].enemy = Enemies[8];
	room[2][1].enemy = Enemies[9];
	room[2][2].enemy = Enemies[10];
	room[2][3].enemy = Enemies[11];
	room[3][0].enemy = Enemies[12];
	room[3][1].enemy = Enemies[13];
	room[3][2].enemy = Enemies[14];
}

int main()
{
	setup();
	cout << "Welcome brave adventurer" << endl;
	system("pause");
	cout << "Hopefully that journey wasn't all in vein..." << endl;
	system("pause");
	cout << endl << "As you enter the tomb you feel the air shifting around you," << endl;
	system("pause");
	cout << "The door behind you swiftly seals itself behind you" << endl;
	system("pause");
	cout << "You're trapped! Let's just hope there's another exit somewhere in this crypt..." << endl;
	system("pause");
	cout << endl << "As you look around the room, you notice something moving around in the shadows" << endl;
	if (room[0][0].enemy.type == "Thief")
	{

	}
	system("pause");


	for (int i = 0; i < 15; i++)
	{
		cout << Enemies[i].name << endl;
	}
}



