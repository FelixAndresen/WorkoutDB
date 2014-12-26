#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <sqlite3.h>
#include <string>
#include <vector>


class SQLiteDatabase
{
public:
	SQLiteDatabase(std::string _path);
	~SQLiteDatabase();

	void Execute(std::vector<std::string> _sql_statements);

private:
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};



#endif