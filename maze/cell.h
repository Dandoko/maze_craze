#ifndef CELL_H
#define CELL_H

class Cell {
private:
	char shape;
public:
	Cell();
	Cell(char shape);
	virtual ~Cell();

	void printCell();

	virtual bool isWall();
};

#endif