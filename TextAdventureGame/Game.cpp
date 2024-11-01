#include <string>
using namespace std;

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
	struct item
	{
		string name;
		float damage;
		string effects;
	};
};




