#include <iostream>
#include <string>
using namespace std;

namespace Lec1
{
	enum ArmyUnitType { SoldierType, AirCraftType, TankType };

	class ArmyUnit
	{
	protected:
		int strength = 0;
		int health = 0;
		int ammu = 0;
		ArmyUnitType unitType;

	public:
		ArmyUnitType getUnitType() const { return this->unitType; }
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
				return target->takeDamageFrom(this);
			}
			return false;
		}
		bool isAlive() const { return this->health > 0; }
		virtual bool canFireAt(const ArmyUnit* target) const { return true; }
		bool takeDamageFrom(const ArmyUnit* enemy)
		{
			if (this->canTakeDamageFrom(enemy))
			{
				this->health -= min(enemy->strength, this->health);
				return true;
			}
			return false;
		}
		virtual bool canTakeDamageFrom(const ArmyUnit* enemy) const { return true; }
		virtual string toString() const = 0;

		ArmyUnit(int strength, int health, int ammu, ArmyUnitType unitType)
			: strength(strength), health(health), ammu(ammu), unitType(unitType)
		{}
	};

	class Soldier : public ArmyUnit
	{
	public:
		Soldier() :ArmyUnit(100, 1000, 100, SoldierType)
		{}
		virtual string toString() const override { return "Soldier"; }
	};

	class Tank : public ArmyUnit
	{
	public:
		Tank() :ArmyUnit(50000, 5000, 10, TankType)
		{}
		virtual string toString() { return "Tank"; }
		virtual bool canFireAt(const ArmyUnit* target) const override
		{
			return target->getUnitType();
		}
		virtual string toString() const override { return "Tank"; }
	};

	class AirCraft : public ArmyUnit
	{
	public:
		AirCraft() :ArmyUnit(50, 2000, 1000, AirCraftType)
		{}
		virtual string toString() const override { return "Air Craft"; }
	};

	int main()
	{
		ArmyUnit** army = new ArmyUnit * [10];
		int count = 0;
		army[count++] = new Soldier;
		army[count++] = new Soldier;
		army[count++] = new Soldier;
		army[count++] = new Soldier;
		army[count++] = new Soldier;
		army[count++] = new Soldier;
		army[count++] = new Tank;
		army[count++] = new Tank;
		army[count++] = new AirCraft;
		army[count++] = new AirCraft;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (army[i]->fireAt(army[j]))
				{
					cout << army[i]->toString() << i << " fired at " << army[j]->toString() << j << endl;
					if (!army[j]->isAlive())
					{
						cout << army[j]->toString() << "is dead!" << endl;
					}
				}
			}
			cout << string(20, '-') << endl;
		}

		for (int i = 0; i < 10; i++)
		{
			if (army[i]->isAlive())
			{
				cout << army[i]->toString() << i << "is still alive!" << endl;
			}
		}
		return 0;
	}
}

namespace Lec2
{
	enum ArmyUnitType { SoldierType, AirCraftType, TankType, UndefinedType};

	class ArmyUnit
	{
	protected:
		int strength = 0;
		int health = 0;
		int ammu = 0;
		ArmyUnitType unitType;

	public:
		ArmyUnitType getUnitType() const { return this->unitType; }
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
		virtual bool canFireAt(const ArmyUnit* target) const { return true; }
		bool takeDamageFrom(const ArmyUnit* enemy)
		{
			if (this->canTakeDamageFrom(enemy))
			{
				this->health -= min(enemy->strength, this->health);
			}
		}
		virtual bool canTakeDamageFrom(const ArmyUnit* enemy) const { return true; }
		virtual string toString() const = 0;

		ArmyUnit(int strength, int health, int ammu, ArmyUnitType unitType)
			: strength(strength), health(health), ammu(ammu), unitType(unitType)
		{}
	};

	class Soldier : public ArmyUnit
	{
	public:
		Soldier():ArmyUnit(100, 100, 100, SoldierType)
		{}
		virtual string toString() const override { return "Soldier"; }
	};

	class Tank : public ArmyUnit
	{
	public:
		Tank() :ArmyUnit(1000, 500, 10, TankType)
		{}
		virtual string toString() { return "Tank"; }
		virtual bool canFireAt(const ArmyUnit* target) const override
		{
			return target->getUnitType();
		}
	};

	class AirCraft : public ArmyUnit
	{
	public:
		AirCraft() :ArmyUnit(50, 200, 1000, AirCraftType)
		{}
		virtual string toString() { return "Air Craft"; }
	};

	int main()
	{
		return 0;
	}
}

int main()
{
	Lec2::main();
}