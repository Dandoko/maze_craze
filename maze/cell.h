#ifndef CELL_H
#define CELL_H

class Cell {
private:
	char m_Shape;
public:
	Cell();
	Cell(const Cell&) = delete;
	Cell(char shape);
	virtual ~Cell();

	void printCell();

	virtual bool isWall();
};

#endif