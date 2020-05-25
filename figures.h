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
	const std::string name_;
};

class Circle : public Figure {
public:
	explicit Circle(uint r=0)
	: Figure("Circle")
	, r_(r)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << r_ << std::endl;
	};

private:
	const uint r_;
};

class Triangle : public Figure {
public:
	explicit Triangle(uint a=0, uint b=0, uint c=0)
	: Figure("Triangle")
	, a_(a)
	, b_(b)
	, c_(c)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << a_ << " " << b_ << " " << c_ << std::endl;
	};

private:
	const uint a_;
	const uint b_;
	const uint c_;
};

class Rectangle : public Figure {
public:
	explicit Rectangle(uint wid=0, uint hei=0)
	: Figure("Rectangle")
	, wid_(wid)
	, hei_(hei)
	{};

	void Print() const override {
		std::cout << GetName() << ": " << wid_ << " " << hei_ << std::endl;
	};

private:
	const uint wid_;
	const uint hei_;
};

class Square : public Rectangle {
public:
	explicit Square(uint side)
	: Rectangle(side, side) {};
};
