#include "stdafx.h"
#include "sqlitehelper.h"
#include <iostream>

SQLiteDatabase::SQLiteDatabase(std::string _path) 
{
	rc = sqlite3_open(_path.c_str(), &db);
	if (rc){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		std::cin.get();
		exit(0);
	}
	else{
		fprintf(stderr, "Successfully opened database!\n");
	}
}

SQLiteDatabase::~SQLiteDatabase() 
{
	sqlite3_close(db);
}


void SQLiteDatabase::Execute(std::vector<std::string> _sql_statements)
{
	for (int i = 0; i<_sql_statements.size(); ++i)
	{
		rc = sqlite3_exec(db, _sql_statements[i].c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else{
			fprintf(stdout, "Table created successfully\n");
		}
	}
}

int SQLiteDatabase::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}