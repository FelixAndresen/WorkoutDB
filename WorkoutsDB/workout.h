#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Workout
{
public:
	Workout::Workout();
	Workout::~Workout();
	void GetData();
	std::vector<std::string> CreateSQL();

private:
	// TABLE Workouts
	std::string date_;
	std::string time_;
	std::string gym_;
	std::string mood_;
	double bodyweight_;

	// TABLE exercises_
	std::string program_;
	int dayofprogram_;
	std::vector<std::string> exercises_;
	int numberofexercises_; 
	std::vector<int> sets_;
	std::vector<int> reps_;
	std::vector<double> weight_;
	std::vector<int> kgflag_; // 1 if kilo, 0 if lbs
	std::vector<std::string> modifier_;

	std::vector<std::string> sql_statements_;

};
#endif
