namespace Lec1
{
#include <iostream>
#include <string>
	using namespace std;

	class A
	{
	protected:
		virtual string doSthg()
		{
			return "Hi";
		}
	};

	class B : public A
	{
	public:
		string doSthg() override
		{
			return "Hello";
		}
	};

	enum ArmyUnitType { SoldierType, AirCraftType, TankType };

	class ArmyUnit
	{
	protected:
		int health = 0;
		int strength = 0;
		int ammu = 0;
		ArmyUnitType unitType;

		ArmyUnit(int health, int strength, int ammu, ArmyUnitType unitType)
			: health(health), strength(strength), ammu(ammu), unitType(unitType)
		{}

	public:
		bool isAlive() const { return health > 0; }
		virtual string toString() const = 0;
		ArmyUnitType getUnitType() const { return unitType; }

	};

	class Tank : public ArmyUnit
	{
	public:
		Tank() : ArmyUnit(1000, 500, 10, TankType)
		{}
		virtual string toString() const
		{
			return "Tank";
		}

	};
}

namespace Lec2
{
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
}

using namespace Lec2;
int main()
{
}