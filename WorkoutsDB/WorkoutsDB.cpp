#include "stdafx.h"
#include "workout.h"
#include "sqlitehelper.h"
#include <windows.h>


std::string ExePath();


int _tmain(int argc, _TCHAR* argv[])
{
	bool more_workouts_ = true;
	std::string input_string_;
	Workout *workout;

	std::string kPath = ExePath()+ "\\WorkoutDB.db"; // file name with \\
		
	SQLiteDatabase *database = new SQLiteDatabase(kPath);


	while (more_workouts_)
	{
		workout = new Workout();
		workout->GetData();
		
		database->Execute(workout->CreateSQL());
		delete workout;

		// Enter new workout?
		std::cout << "\n==========\nEnter new workout?\n";
		std::getline(std::cin, input_string_);
		std::stringstream(input_string_) >> more_workouts_;
	}
	delete database;
	return 0;
}


std::string ExePath() 
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}