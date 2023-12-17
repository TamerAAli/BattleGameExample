#include <iostream>
#include <string>
using namespace std;

namespace Lec1
{
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

		bool fireAT(ArmyUnit* target)
		{
			if (
				this->isAlive() &&
				this->ammu > 0 &&
				target &&
				target->isAlive() &&
				this->canFireAt(target)
				)
			{
				this->ammu--;
				return target->takeDamage(this);
			}
		}

		bool takeDamage(const ArmyUnit* enemy)
		{
			if (this->canTakeDamageFrom(enemy))
			{
				this->health -= enemy->strength;
				return true;
			}
			return false;
		}

		virtual bool canTakeDamageFrom( const ArmyUnit* potentialEnemy) const = 0;

		virtual bool canFireAt(const ArmyUnit* potentialTarget) const
		{
			return this != potentialTarget;
		}

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
		virtual bool canFireAt(const ArmyUnit* potentialTarget) const override
		{
			return ArmyUnit::canFireAt(potentialTarget) &&
				potentialTarget->getUnitType() != AirCraftType;
		}


		// Inherited via ArmyUnit
		virtual bool canTakeDamageFrom(const ArmyUnit* potentialEnemy) const override
		{
			return true;
		}

	};

	class Soldier : public ArmyUnit
	{
	public:
		Soldier() : ArmyUnit(100, 100, 100, SoldierType)
		{}
		virtual string toString() const
		{
			return "Soldier";
		}

		// Inherited via ArmyUnit
		virtual bool canTakeDamageFrom(const ArmyUnit* potentialEnemy) const override
		{
			return true;
		}
	};

	class AirCraft : public ArmyUnit
	{
	public:
		AirCraft() : ArmyUnit(50, 50, 5000, AirCraftType)
		{}
		virtual string toString() const
		{
			return "AirCraft";
		}

		// Inherited via ArmyUnit
		virtual bool canTakeDamageFrom(const ArmyUnit* potentialEnemy) const override
		{
			return true;
		}
	};
}

namespace Lec2
{
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