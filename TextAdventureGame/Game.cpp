#include <string>
#include <iostream>
#pragma once
using namespace std;

void startAgain();

#pragma region structs
struct Item
{
	string name;
	float damage;
	string effects;
	bool weapon;
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
	Enemy enemy;
	Item reward;
};

struct Player
{
	float health;
	float damage;
	Item shield;
	Item Weapon;
	Item potion;
};
#pragma endregion

Player player;
Room room[4][4];
Enemy Enemies[15];
Item Items[15];
int temp;
int k;
int x;
int y;
#pragma region classes
class playerMovement
{
private:
	char input;
	int menuSelect;
public:
	void moveRight()
	{
		x++;
	}
	void moveUp()
	{
		y++;
	}

	void mover()
	{
		cout << endl << "As the dust settles, the room falls still\nSome doors open, allowing you to progress further." << endl;
		cout << "which way will you decide to go?" << endl;
		if (x == 0)
		{
			if (y == 0 || y == 1 || y == 2)
			{
				cout << "\n1.	Straight";
				cout << "\n2.	Right" << endl;
				cin >> menuSelect;
				switch (menuSelect)
				{
				case 0:
					cout << "You continue down the right path" << endl;
					moveRight();
					break;
				case 1:
					cout << "You continue down the path straight ahead" << endl;
					moveUp();
					break;
				case 2:
					cout << "You continue down the right path" << endl;
					moveRight();
					break;
				default:
					cout << "You can't decide so you just go the direction you are facing.\nWhich direction is that?\nWho knows, this whole place is confusing??" << endl;
					moveUp();
					break;
				}
			}
			else if (y == 3)
			{
				cout << "You continue down the right path" << endl;
				moveRight();
			}
		}
		else if (x == 1 || x == 2)
		{
			if (y == 0 || y == 1 || y == 2)
			{
				cout << "\n1.	Straight";
				cout << "\n2.	Right" << endl;
				cin >> menuSelect;
				switch (menuSelect)
				{
				case 0:
					cout << "You continue down the path straight ahead" << endl;
					moveUp();
					break;
				case 1:
					cout << "You continue down the path straight ahead" << endl;
					moveUp();
					break;
				case 2:
					cout << "You continue down the right path" << endl;
					moveRight();
					break;
				default:
					cout << "You can't decide so you just go the direction you are facing.\nWhich direction is that?\nWho knows, this whole place is confusing??" << endl;
					moveUp();
					break;
				}
			}
			else if (y == 3)
			{
				cout << "You continue down the right path" << endl;
				moveRight();
			}
		}
		else if (x == 3)
		{
			if (y == 0 || y == 1 || y == 2)
			{
				cout << "You continue down the path straight ahead" << endl;
				moveUp();
			}
			else if (y == 3)
			{
				cout << "You see the light of day come streaming in through the now open door...\nYou finally made it out!";
				system("pause");
				exit(69);
			}
		}
		startAgain();
	}

	void itemSelect()
	{
		cout << "The foe left behind a " << room[x][y].reward.name << "." << endl;
		if (room[x][y].reward.weapon)
		{
			if (player.Weapon.name == "none")
			{
				cout << "You pick it up." << endl;
				player.Weapon = room[x][y].reward;
			}
			else
			{
				cout << "Would you like to replace your " << player.Weapon.name << " with a " << room[x][y].reward.name << "?" << endl << "y/n" << endl;
				cin >> input;
				if (input == 'y')
				{
					cout << "You pick it up." << endl;
					player.Weapon = room[x][y].reward;
				}
				else if (input == 'n')
				{
					cout << "You decide to keep your current weapon." << endl;
				}
				else
				{
					cout << "You decide to not listen to basic instructions and you're new weapon spontaniously combusts." << endl;
				}
			}
		}
		else if (room[x][y].reward.effects == "Heal")
		{
			if (player.potion.name == "empty bottle" || player.potion.name == "none")
			{
				cout << "You add the " << room[x][y].reward.name << " to your bag." << endl;
				player.potion = room[x][y].reward;
			}
			else
			{
				cout << "You're already carrying a " << room[x][y].reward.name << " in your bag." << endl;
			}
		}
		else
		{
			if (player.shield.name == "none")
			{
				cout << "You pick it up." << endl;
				player.shield = room[x][y].reward;
			}
			else
			{
				cout << "Would you like to replace your " << player.shield.name << " with a " << room[x][y].reward.name << "?" << endl << "y/n" << endl;
				cin >> input;
				if (input == 'y')
				{
					cout << "You pick it up." << endl;
					player.shield = room[x][y].reward;
				}
				else if (input == 'n')
				{
					cout << "You decide to keep your current shield." << endl;
				}
				else
				{
					cout << "You decide to not listen to basic instructions and you're new shield spontaniously combusts." << endl;
				}
			}
		}
		mover();
		cout << endl << endl << "As you look around the new room, you notice something moving around in the shadows" << endl;
		cout << "A " << room[x][y].enemy.name << " lunges out of the darkness to attack you" << endl;
	}
};
playerMovement moves;

class pickers
{
public:
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
			enemy.damage = 10;
			enemy.health = 15;
			enemy.type = "Dead";
			return 
			{
				enemy
			};
			break;
		case 2:
			enemy.name = "Hound";
			enemy.damage = 15;
			enemy.health = 40;
			enemy.type = "Floor";
			return 
			{
				enemy
			};
			break;
		case 3:
			enemy.name = "Zombie";
			enemy.damage = 15;
			enemy.health = 50;
			enemy.type = "Dead";
			return
			{
				enemy
			};
			break;
		case 4:
			enemy.name = "Demon";
			enemy.damage = 20;
			enemy.health = 60;
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
			enemy.name = "Rat";
			enemy.damage = 1;
			enemy.health = 1;
			enemy.type = "Thief";
			return enemy;
			break;
		}
	}
	Item itemPicker(Item item)
	{
		temp = rand() % 7;
		switch (temp)
		{
		case 0:
			item.name = "Flaming shield";
			item.damage = -10;
			item.effects = "Fire";
			item.weapon = false;
			return
			{
				item
			};
			break;
		case 1:
			item.name = "Flaming sword";
			item.damage = 15;
			item.effects = "Fire";
			item.weapon = true;
			return
			{
				item
			};
			break;
		case 2:
			item.name = "Vampiric Shield";
			item.damage = -15;
			item.effects = "Vamp";
			item.weapon = false;
			return
			{
				item
			};
			break;
		case 3:
			item.name = "Holy Bow";
			item.damage = 15;
			item.effects = "Holybow";
			item.weapon = true;
			return
			{
				item
			};
			break;
		case 4:
			item.name = "flamethrower";
			item.damage = 15;
			item.effects = "Firebow";
			item.weapon = true;
			return
			{
				item
			};
			break;
		case 5:
			item.name = "Old Shoe";
			item.damage = 0;
			item.effects = "trash";
			item.weapon = false;
			return
			{
				item
			};
			break;
		case 6:
			item.name = "Heal";
			item.damage = 0;
			item.effects = "Heal";
			item.weapon = false;
			return
			{
				item
			};
			break;
		default:
			return item;
			break;
		}
	}
	void defaultItems(string string)
	{
		if (string == "default")
		{
			player.Weapon.name = "none";
			player.Weapon.damage = 5;
			player.Weapon.effects = "none";
			player.Weapon.weapon = true;
			player.shield.name = "none";
			player.shield.damage = 0;
			player.shield.effects = "none";
			player.shield.weapon = false;
			player.potion.name = "none";
			player.potion.damage = 0;
			player.potion.effects = "none";
			player.potion.weapon = false;
		}
		else if (string == "heal")
		{
			player.potion.name = "empty bottle";
			player.potion.damage = 0;
			player.potion.effects = "none";
			player.potion.weapon = false;
		}
	}
};
pickers picker;

class fights
{
private:
	int menuSelect;
	float baseDamage;
	float totalDamage;

public:
	void fightMenu()
	{
		cout << "\n1.	Attack";
		cout << "\n2.	Heal";
		cout << "\n3.	Romance" << endl;
		cin >> menuSelect;
		switch (menuSelect)
		{
		case 0:
			cout << "\nError!\nPlease select a number from the menu below" << endl;
			break;
		case 1:
			Attack();
			break;
		case 2:
			Heal();
			break;
		case 3:
			cout << "\nWhy would you ever pick this?...\nThat's... really unsettling that you would actually choose this option. Pick again >:(" << endl;
			fightMenu();
			break;
		default:
			cout << "\nError!\nPlease select a number from the menu below" << endl;
			break;
		}
	}

	void Attack()
	{
		baseDamage = player.Weapon.damage;
		if (player.Weapon.effects == "none")
		{
			totalDamage = baseDamage;
		}
		else if (player.Weapon.effects == "Fire")
		{
			if (room[x][y].enemy.type == "Jelly" || room[x][y].enemy.type == "Floor")
			{
				totalDamage = baseDamage * 2;
			}
			else if (room[x][y].enemy.type == "Sky")
			{
				totalDamage = baseDamage / 2;
			}
			else
			{
				totalDamage = baseDamage;
			}
		}
		else if (player.shield.effects == "Holybow")
		{
			if (room[x][y].enemy.name == "Zombie")
			{
				totalDamage = baseDamage * 2;
			}
			else if (room[x][y].enemy.type == "Sky")
			{
				totalDamage = baseDamage * 4;
			}
			else if (room[x][y].enemy.type == "Jelly")
			{
				totalDamage = baseDamage / 8;
			}
			else if (room[x][y].enemy.name == "Skelly")
			{
				totalDamage = baseDamage / 4;
			}
			else if (room[x][y].enemy.type == "Floor")
			{
				totalDamage = baseDamage / 2;
			}
			else
			{
				totalDamage = baseDamage;
			}
		}
		else if (player.shield.effects == "Firebow")
		{
			if (room[x][y].enemy.type == "Jelly" || room[x][y].enemy.type == "Sky")
			{
				totalDamage = baseDamage * 2;
			}
			else if (room[x][y].enemy.type == "Floor")
			{
				totalDamage = baseDamage / 2;
			}
			else
			{
				totalDamage = baseDamage;
			}
		}
		room[x][y].enemy.health = room[x][y].enemy.health - totalDamage;
		cout << "You attack " << room[x][y].enemy.name << " dealing " << totalDamage << " damage." << endl;
		if (room[x][y].enemy.health > 0)
		{
			cout << "The " << room[x][y].enemy.name << " has " << room[x][y].enemy.health << " health remaining." << endl;
			Damaged();
		}
		else if (room[x][y].enemy.health <= 0)
		{
			cout << "You slaughter the " << room[x][y].enemy.name << " and it drops something." << endl;
			moves.itemSelect();
		}
	}

	void Damaged()
	{
		baseDamage = room[x][y].enemy.damage;
		if (player.shield.effects == "none")
		{
			totalDamage = baseDamage;
		}
		else if (player.shield.effects == "Fire")
		{
			if (room[x][y].enemy.type == "Jelly" || room[x][y].enemy.type == "Floor")
			{
				totalDamage = baseDamage / 2;
			}
			else if (room[x][y].enemy.type == "Sky")
			{
				totalDamage = baseDamage * 2;
			}
			else
			{
				totalDamage = baseDamage;
			}
		}
		else if (player.shield.effects == "Vamp")
		{
			if (room[x][y].enemy.type == "Dead" || room[x][y].enemy.type == "Sky")
			{
				totalDamage = baseDamage * 2;
			}
			else if (room[x][y].enemy.type == "Jelly" || room[x][y].enemy.type == "Floor")
			{
				totalDamage = baseDamage * -0.5;
			}
			else
			{
				totalDamage = baseDamage;
			}
		}
		player.health = player.health - totalDamage;
		cout << room[x][y].enemy.name << " dealt " << totalDamage << " damage!" << endl;
		if (player.health <= 0)
		{
			cout << "You unfortunately died a tragic death";
			exit(420);
		}
		else
		{
			cout << "You have " << player.health << "/300 health remaining" << endl;
			fightMenu();
		}
	}

	void Heal()
	{
		if (player.potion.name == "none")
		{
			cout << "You have no potions you goober. Try again" << endl;
			fightMenu();
		}
		else if (player.potion.name == "Heal")
		{
			player.health = 300;
			picker.defaultItems("heal");
			cout << "You drank the potion and your health has been completely restored" << endl;
			Damaged();
		}
		fightMenu();
	}
};
fights fight;

#pragma endregion

void startAgain()
{
	fight.Damaged();
}


void setup()
{
	for (int i = 0; i < 15; i++)
	{
		Enemies[i] = picker.enemyPicker(Enemies[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			room[i][j].enemy = Enemies[k];
			k++;
		}
	}
	k = 0;

	for (int i = 0; i < 15; i++)
	{
		Items[i] = picker.itemPicker(Items[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			room[i][j].reward = Items[k];
			k++;
		}
	}
	k = 0;
	picker.defaultItems("default");
	player.health = 300;
}

int main()
{
		setup();
		cout << "Welcome brave adventurer" << endl;
		cout << "Hopefully that journey wasn't all in vein..." << endl;
		system("pause");
		cout << endl << "As you enter the tomb you feel the air shifting around you," << endl;
		cout << "The door behind you swiftly seals itself behind you" << endl;
		cout << "You're trapped! Let's just hope there's another exit somewhere in this crypt..." << endl;
		system("pause");
		cout << endl << "As you look around the new room, you notice something moving around in the shadows" << endl;
		cout << "A " << room[x][y].enemy.name << " lunges out of the darkness to attack you" << endl;
		fight.Damaged();
}



