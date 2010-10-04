#include "stdlib.h"
#include <libpq-fe.h>

char * string_for_query;
PGconn *Conn_pointer;
PGresult *result;

char* pghost = "localhost"; //IP address string is also ok
char* pgport ="5432";
char* pgoptions =NULL;
char* pgtty = NULL;
char* dbName = "postgis";
char* username = "postgres"; //postegres is the username that
char* password = "osgis" ;//set when insalled cannot get directly

#pragma comment(lib,"D:\\Program Files\\PostgreSQL\\9.0\\lib\\libpq.lib")
int main()
{
	Conn_pointer=PQsetdbLogin(pghost, pgport, pgoptions, pgtty, dbName, username, password);
	if (PQstatus(Conn_pointer) == CONNECTION_BAD)
	{
		printf("cannot connect to the database!\n");
		return -1;
	}
	printf ("Connect to database seccess\n");
	return 0;
}