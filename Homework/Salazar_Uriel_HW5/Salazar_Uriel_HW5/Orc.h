#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
public:
	Orc(std::string, int, int, int, int, int, int);
	void setOrcRage(int oR) { orcRage = oR; }
	virtual int attack() override;
private:
	int orcRage;
};

#endif