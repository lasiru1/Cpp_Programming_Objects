#ifndef RANGER_H
#define RANGER_H

#include "Player.h"

class Ranger : public Player
{
public:
	Ranger(std::string, int, int, int, int, int, int);
	void setWarningShot(int oR) { warningShot = oR; }
	virtual int attack() override;
private:
	int warningShot;
};

#endif