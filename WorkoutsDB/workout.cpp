#include "stdafx.h"
#include "workout.h"

Workout::Workout(){}
Workout::~Workout(){}

void Workout::GetData()
{
	std::string input_string_;
	double input_double_;

	std::cout << "--- Workout Database Tool---\n";
	std::cout << "Date (YYYY-MM-DD): ";
	std::getline(std::cin, date_);

	std::cout << "Time (HH:MM): ";
	std::getline(std::cin, time_);

	std::cout << "Gym: ";
	std::getline(std::cin, gym_);

	std::cout << "Mood: ";
	std::getline(std::cin, mood_);

	std::cout << "Bodyweight: ";
	std::getline(std::cin, input_string_);
	std::stringstream(input_string_) >> bodyweight_;

	std::cout << "Program: ";
	std::getline(std::cin, program_);

	std::cout << "Day of program: ";
	std::getline(std::cin, input_string_);
	std::stringstream(input_string_) >> dayofprogram_;

	std::cout << "Number of exercises: ";
	std::getline(std::cin, input_string_);
	std::stringstream(input_string_) >> numberofexercises_;

	std::cout << "\n==========\n";

	for (int i = 0; i < numberofexercises_; ++i)
	{
		std::cout << "Exercise: ";
		std::getline(std::cin, input_string_);
		exercises_.push_back(input_string_);

		std::cout << "Sets: ";
		std::getline(std::cin, input_string_);
		std::stringstream(input_string_) >> input_double_;
		sets_.push_back((int)input_double_);

		std::cout << "Reps: ";
		std::getline(std::cin, input_string_);
		std::stringstream(input_string_) >> input_double_;
		reps_.push_back((int)input_double_);

		std::cout << "Weight: ";
		std::getline(std::cin, input_string_);
		std::stringstream(input_string_) >> input_double_;
		weight_.push_back(input_double_);

		std::cout << "KG (1) / Lbs (0):";
		std::getline(std::cin, input_string_);
		std::stringstream(input_string_) >> input_double_;
		kgflag_.push_back((int)input_double_);

		std::cout << "Modifier:";
		std::getline(std::cin, input_string_);
		modifier_.push_back(input_string_);

		std::cout << "----------\n";
	}
}

std::vector<std::string> Workout::CreateSQL()
{
	// Workouts
	// date_, time_, gym_, mood_, bodyweight_

	std::string sql_workouts_ = "INSERT INTO Workouts(Date, Time";
	std::string workouts_arguments_ = ") VALUES ('" + date_ + "', '" + time_ + "'";

	if (!gym_.empty())
	{
		sql_workouts_ += ", Gym";
		workouts_arguments_ += ", '" + gym_ + "'";
	}

	if (!mood_.empty())
	{
		sql_workouts_ += ", Mood";
		workouts_arguments_ += ", '" + mood_ + "'";
	}

	if (bodyweight_ > 0.0)
	{
		sql_workouts_ += ", Bodyweight";
		workouts_arguments_ += ", " + std::to_string(bodyweight_);
	}

	sql_statements_.push_back(sql_workouts_ + workouts_arguments_ + ");");

	// exercises_
	// date_, program_, DayOfprogram_, Exercise, Sequence, sets_, reps_, weight_, kgflag_

	std::string sql_exercises_ = "INSERT INTO Exercises(Date";
	std::string exercises_arguments_ = ") VALUES ('" + date_ + "'";
	std::string exercise_;


	if (!program_.empty())
	{
		sql_exercises_ += ", Program";
		exercises_arguments_ += ", '" + program_ + "'";
	}

	if (dayofprogram_ > 0.0)
	{
		sql_exercises_ += ", DayOfProgram";
		exercises_arguments_ += ", " + std::to_string(dayofprogram_);
	}

	sql_exercises_ += ", Exercise, Sequence, Sets, Reps, Weight, Kgflag, Modifier";
	for (int i = 0;i < numberofexercises_; ++i)
	{
		exercise_ = ", '" + exercises_[i] + "', " +
			std::to_string(i + 1) + ", " +
			std::to_string(sets_[i]) + ", " +
			std::to_string(reps_[i]) + ", " +
			std::to_string(weight_[i]) + ", " +
			std::to_string(kgflag_[i]) + ", '" +
			modifier_[i];
		
		sql_statements_.push_back(sql_exercises_ + exercises_arguments_ + exercise_ + "');");
	}
	return sql_statements_;
}