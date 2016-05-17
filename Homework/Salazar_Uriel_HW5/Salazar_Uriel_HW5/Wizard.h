#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

class Wizard : public Player
{
public:
	Wizard(std::string, int, int, int, int, int, int);
	void setArcLightning(int oR) { arcLightning = oR; }
	virtual int flamingSphere() override;
	virtual int attack() override;
private:
	int arcLightning;
};

#endif