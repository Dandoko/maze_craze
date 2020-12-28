#ifndef UNIT_H
#define UNIT_H

class Unit {
private:
	char m_Shape;
public:
	Unit(char shape);
	Unit(const Unit&) = delete;
	virtual ~Unit();

	void printUnit();

	virtual bool isSolver();
	virtual bool isCreator();
};

#endif