#pragma once

#include "Utilies.hpp"
#include "Vehicle.hpp"
#include "Track.hpp"

using std::string;

enum Type {
	Turbo,
	Standart,
	Economy
};

class Order {
private:
	double cost_;
	int volume_;
	string startPoint_;
	string finishPoint_;
	enum Type type_;
	Track track_;

	Utilies* util_ = Utilies::GetInstance();

public:
	Order();
	Order(Type deliv, string startP, string finishP, int vol);

	int decr(string str);
	int** matrixUpd(Type type);
	int* optim(int** arr, int beginPoint, int endPoint);
	Track best(string startP, string finishP, Type deliv, int volume);
};
