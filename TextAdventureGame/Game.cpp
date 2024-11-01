#include <string>
#include <iostream>
using namespace std;

struct item
	{
		string name;
		float damage;
		string effects;
	};

struct Room
{
	int room[4][4];
	bool cleared;
	struct Enemy
	{
		string name;
		float health;
		float damage;
		string type;
	};
	item reward;
};

struct Player
{
	float health;
	float damage;
	item heldItem;
};

int main()
{
	
}


