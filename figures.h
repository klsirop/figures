# pragma once
#include <sstream>
#include <string>
#include <memory>
#include <iostream>

class Figure {
public:
	Figure(const std::string& name) : name_(name) {};
	virtual void Print() const = 0;
	virtual std::string GetName() const {
		return name_;
	}

private:
	std::string name_;
};

class Circle : public Figure {
public:
	explicit Circle(int r=0)
	: Figure("Circle")
	, r_(r)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << r_ << std::endl;
	};

private:
	const int r_;
};

class Triangle : public Figure {
public:
	explicit Triangle(int a=0, int b=0, int c=0)
	: Figure("Triangle")
	, a_(a)
	, b_(b)
	, c_(c)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << a_ << " " << b_ << " " << c_ << std::endl;
	};

private:
	const int a_;
	const int b_;
	const int c_;
};

class Rectangle : public Figure {
public:
	explicit Rectangle(int wid=0, int hei=0)
	: Figure("Rectangle")
	, wid_(wid)
	, hei_(hei)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << wid_ << " " << hei_ << std::endl;
	};

private:
	const int wid_;
	const int hei_;
};

class Square : public Rectangle {
public:
	explicit Square(int side)
	: Rectangle(side, side) {};
};
