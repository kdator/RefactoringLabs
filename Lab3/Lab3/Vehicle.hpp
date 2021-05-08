#pragma once

#include <tuple>
#include <memory>

using std::unique_ptr;
using std::tuple;
using std::get;
using std::make_tuple;

class Vehicle {
private:
	int vehicleSpeed_;
	int vehicleVolume_;
	double vehiclePrice_;
	int distance_;
public:
	Vehicle();
	Vehicle(std::tuple<int, int, double> vehicleParams, int distance);
	~Vehicle() = default;

	double SumCost(int mass, int dist);
	double SumTime(int dist) const;

	int GetDistance() const;
	void SetSpeed(int speed);
	void SetVolume(int volume);
	void SetPrice(double price);
	void SetDistance(int distance);
};

class Train : public Vehicle {
public:
	Train();
	Train(std::tuple<int, int, double> trainParams, int distance);
};

class Car : public Vehicle {
public:
	Car();
	Car(std::tuple<int, int, double> trainParams, int distance);
};

class Plane : public Vehicle {
public:
	Plane();
	Plane(std::tuple<int, int, double> trainParams, int distance);
};

/** ------------ BUILDERS ------------ */

/**
 * @brief Here we use Builder pattern.
 *			  It is an interface for builders.
 */
class VehicleBuilder {
public:
	virtual ~VehicleBuilder();
	virtual void BuildSpeed(int speed);
	virtual void BuildVolume(int volume);
	virtual void BuildPrice(double price);
	virtual void BuildDistance(int distance);
};

class CarBuilder : public VehicleBuilder {
private:
	unique_ptr<Vehicle> car_;

public:
	void BuildSpeed(int speed) override;
	void BuildVolume(int volume) override;
	void BuildPrice(double price) override;
	void BuildDistance(int distance) override;
	void Reset();
	Vehicle* GetCar();
};

class TrainBuilder : public VehicleBuilder {
private:
	unique_ptr<Vehicle> train_;

public:
	void BuildSpeed(int speed) override;
	void BuildVolume(int volume) override;
	void BuildPrice(double price) override;
	void BuildDistance(int distance) override;
	void Reset();
	Vehicle* GetTrain();
};

class PlaneBuilder : public VehicleBuilder {
private:
	unique_ptr<Vehicle> plane_;

public:
	void BuildSpeed(int speed) override;
	void BuildVolume(int volume) override;
	void BuildPrice(double price) override;
	void BuildDistance(int distance) override;
	void Reset();
	Vehicle* GetPlane();
};
