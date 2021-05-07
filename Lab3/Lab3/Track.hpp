#pragma once
#include <list>

class Vehicle;

class Track {
private:
	double cost_;
	double time_;
	int volume_;
public:
	Track();
	~Track() = default;
	Track(std::list<Vehicle> vehicles, int volume);

	double GetCost();
};