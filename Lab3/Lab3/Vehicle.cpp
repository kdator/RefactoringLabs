#include "Vehicle.hpp"

#include <tuple>

using std::tuple;
using std::unique_ptr;

Vehicle::Vehicle() {
	vehicleSpeed_ = 0;
	vehicleVolume_ = 0;
	vehiclePrice_ = 0.0f;
	distance_ = 0;
}

Vehicle::Vehicle(std::tuple<int, int, double> vehicleParams, int distance) :
	vehicleSpeed_(get<0>(vehicleParams)),
	vehicleVolume_(get<1>(vehicleParams)),
	vehiclePrice_(get<2>(vehicleParams)),
	distance_(distance) {}

double Vehicle::SumCost(int mass, int dist) {
	return (mass / vehicleVolume_) * SumTime(dist) * vehiclePrice_;
}

double Vehicle::SumTime(int dist) const {
	return dist / vehicleSpeed_;
}

int Vehicle::GetDistance() const { return distance_; };
void Vehicle::SetSpeed(int speed) { vehicleSpeed_ = speed; }
void Vehicle::SetVolume(int volume) { vehicleVolume_ = volume; }
void Vehicle::SetPrice(double price) { vehiclePrice_ = price; }
void Vehicle::SetDistance(int distance) { distance_ = distance; }

/** ------------------------------------------------------------ */

Train::Train() : Vehicle(make_tuple(100, 500, 200), 0) {}

Train::Train(std::tuple<int, int, double> trainParams, int distance) :
	Vehicle(trainParams, distance) {}

/** ------------------------------------------------------------ */

Car::Car() : Vehicle(make_tuple(60, 50, 100), 0) {}

Car::Car(std::tuple<int, int, double> trainParams, int distance) :
	Vehicle(trainParams, distance) {};

/** ------------------------------------------------------------ */

Plane::Plane() : Vehicle(make_tuple(300, 100, 500), 0) {}

Plane::Plane(std::tuple<int, int, double> trainParams, int distance) :
	Vehicle(trainParams, distance) {}


/**
 * @page Builders.
 * @brief Here we have builders.
 */

void CarBuilder::Reset() {
	car_ = std::unique_ptr<Vehicle>(new Car());
}
Vehicle* CarBuilder::GetCar() {
	return car_.get();
}

void CarBuilder::BuildSpeed(int speed) { car_->SetSpeed(speed); }
void CarBuilder::BuildVolume(int volume) { car_->SetVolume(volume); }
void CarBuilder::BuildPrice(double price) { car_->SetPrice(price); }
void CarBuilder::BuildDistance(int distance) { car_->SetDistance(distance); }

/* ---------------------------------- */

void TrainBuilder::Reset() {
	train_ = std::unique_ptr<Vehicle>(new Train());
}
Vehicle* TrainBuilder::GetTrain() {
	return train_.get();
}

void TrainBuilder::BuildSpeed(int speed) { train_->SetSpeed(speed); }
void TrainBuilder::BuildVolume(int volume) { train_->SetVolume(volume); }
void TrainBuilder::BuildPrice(double price) { train_->SetPrice(price); }
void TrainBuilder::BuildDistance(int distance) { train_->SetDistance(distance); }

/* ---------------------------------- */

void PlaneBuilder::Reset() {
	plane_ = std::unique_ptr<Vehicle>(new Plane());
}
Vehicle* PlaneBuilder::GetPlane() {
	return plane_.get();
}

void PlaneBuilder::BuildSpeed(int speed) { plane_->SetSpeed(speed); }
void PlaneBuilder::BuildVolume(int volume) { plane_->SetVolume(volume); }
void PlaneBuilder::BuildPrice(double price) { plane_->SetPrice(price); }
void PlaneBuilder::BuildDistance(int distance) { plane_->SetDistance(distance); }