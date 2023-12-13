#include <iostream>
#include <string>
using namespace std;
enum ArmyUnitType { Soldier, AirCraft, Tank, Undefined };

class ArmyUnit
{
protected:
	int strength = 0;
	int health = 0;
	int ammu = 0;
	ArmyUnitType unitType = Undefined;

public:
	virtual bool fireAt(ArmyUnit* target)
	{
		if (
			target != nullptr &&
			this->isAlive() &&
			this->ammu > 0 &&
			target->isAlive() &&
			this->canFireAt(target)
			)
		{
			this->ammu--;
			target->takeDamageFrom(this);
		}
	}
	bool isAlive() const { return this->health > 0; }
	virtual bool canFireAt(ArmyUnit* target) = 0;
	bool takeDamageFrom(ArmyUnit* enemy)
	{
		if (this->canTakeDamageFrom(enemy))
		{
			this->health -= min(enemy->strength, this->health);
		}
	}
	virtual bool canTakeDamageFrom(ArmyUnit* enemy) = 0;
};

int main()
{
}