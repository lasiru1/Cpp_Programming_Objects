#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
public:
	Fighter(std::string, int, int, int, int, int, int);
	void setBrashStrike(int oR) { brashStrike = oR; }
	virtual int attack() override;
private:
	int brashStrike;
};

#endif