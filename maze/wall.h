#ifndef WALL_H
#define WALL_H

#include "cell.h"

class Wall : public Cell {
private:
	bool m_IsBorder;
public:
	Wall();
	Wall(bool isBorder);
	Wall(const Wall&) = delete;
	virtual ~Wall();

	bool isWall();
	bool getIsBorder();
};

#endif