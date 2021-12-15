#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//constant for standard output
const HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);

class Shape
{
private:
	int directR, directC; //for motion

public:
	void setDirection(int directr, int directc) //setter
	{
		directR = directr;
		directC = directc;
	}
	void getDirection(int &directr, int &directc) //getter
	{
		directr = directR;
		directc = directC;
	}

	virtual void animate() = 0;		//pure virtual function

};

// this class sets the rectangle up for drawing
class Rectangle : public Shape
{
private:
	int rowP, colP, color;

public:
	virtual void digitalDraw() = 0; //pure virtual function
	
	//setter and getter function for position
	void setPos(int row, int col)
	{
		rowP = row;
		colP = col;
	}
	void getPos(int &row, int &col)
	{
		row = rowP;
		col = colP;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getColor() const
	{
		return color;
	}
	//pure virtual function working in the child clas
	virtual void animate(); 

};

// the rectangle information
class SpecialRectangle : public Rectangle
{
private:
	int length, width;
public:
	//pure virtual function in the child class
	virtual void digitalDraw();
	SpecialRectangle(int rowP, int colP, int width, int length);
};
