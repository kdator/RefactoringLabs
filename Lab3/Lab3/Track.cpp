#include <list>

#include "Track.hpp"
#include "Vehicle.hpp"

using std::list;

Track::Track(list<Vehicle> vehicles, int volume) {
	for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
		cost_ += (*it).SumCost(volume, (*it).GetDistance());
		time_ += (*it).SumTime((*it).GetDistance());
	}
}

Track::Track() { cost_ = time_ = volume_ = 0; }

double Track::GetCost() { return cost_; }