#ifndef CELL_H
#define CELL_H

class Cell {
private:
	char m_Shape;
	bool m_IsVisited;

public:
	Cell(char shape);
	Cell(const Cell&) = delete;
	virtual ~Cell();

	bool getIsVisited();
	void setIsVisited(bool isVisited);

	void printCell();

	virtual bool isWall();
	virtual bool isPath();
};

#endif