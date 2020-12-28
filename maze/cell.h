#ifndef CELL_H
#define CELL_H

class Cell {
private:
	char m_Shape;
public:
	Cell();
	Cell(char shape);
	Cell(const Cell&) = delete;
	virtual ~Cell();

	void printCell();

	virtual bool isWall();
	virtual bool isPath();
};

#endif