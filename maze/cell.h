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

	void printCell();

	bool getIsVisited();
	void setIsVisited(bool isVisited);

	virtual bool isWall();
	virtual bool isPath();
};

#endif