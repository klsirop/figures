#include "figures.h"
#include <vector>
#include <cstring>

using namespace std;

shared_ptr<Figure> CreateFigure(istringstream& is) {
	shared_ptr<Figure> fig;
	string fig_type;

	is >> fig_type;
	if (fig_type == "circle") {
		int r = 0;

		is >> r;
		fig = make_shared<Circle>(r);
	} else if (fig_type == "rectangle") {
		int wid = 0;
		int hei = 0;

		is >> wid >> hei;
		fig = make_shared<Rectangle>(wid, hei);
	} else if (fig_type == "triangle") {
		int a = 0;
		int b = 0;
		int c = 0;

		is >> a >> b >> c;
		fig = make_shared<Triangle>(a, b, c);
	} else if (fig_type == "square") {
		int side = 0;

		is >> side;
		fig = make_shared<Square>(side);
	}
	else {
		throw invalid_argument("Error: unknown figure\n");
	}
	return (fig);
}

void PrintFigure(istringstream& is, vector<shared_ptr<Figure>>& figures) {
	int params;

	is >> params;
	if (params >= 0 && static_cast<uint>(params) < figures.size()) {
		figures[params]->Print();
	} else {
		throw invalid_argument("Error: you did't add this fugure");
	}
}

void Usage(int argc, char **argv) {
	if (argc != 2)
		return ;
	else if (!(strcmp(argv[1], "-usage"))) {
		cout << "\t-usage:\n" <<
				"\tcommand1: 'add figure_type params'\n" <<
				"\tcommand2: 'print index'\n" <<
				"\tfigure_type: circle, rectangle, triangle, square\n" <<
				"\tparams: r (circle); wid, hei (rectangle); a, b, c (triangle); side (square)\n" <<
				"\texample: add circle 5\n" <<
				"\texample: print 0\n" << endl;
	}
}

int main(int argc, char *argv[]) {
	Usage(argc, argv);

	vector<shared_ptr<Figure>> figures;

	cout << "Enter command:\n";
	string line;
	while (getline(cin, line)) {
		istringstream is(line);
		string command;

		is >> command;
		if (command == "add") {
			try {
				figures.push_back(CreateFigure(is));
			} catch (exception &ex) {
				cout << ex.what();
			}
		} else if (command == "print") {
			try {
				PrintFigure(is, figures);
			} catch (exception &ex) {
				cout << ex.what() << endl;
			}
		} else {
			cout << "Error: unknown command\n";
		}
	}

	return (0);
}
