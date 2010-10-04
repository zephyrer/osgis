#include<stdlib.h>
#include<stdio.h>
#include<libpq-fe.h>

int main()
{
	int gid;
	char query_string[256];
	PGconn *conn;
	PGresult *res;
	int i;
	conn = PQconnectdb("host=127.0.0.1 port=5432 dbname=postgis user=postgres password=osgis");
	if(PQstatus(conn) == CONNECTION_BAD)
	{
		fprintf(stderr, "Database link error!\n");
		fprintf(stderr,"%s",PQerrorMessage(conn));
		exit(1);		
	}
	printf("Enter a gid :  ");
	scanf("%d",&gid);
	
	sprintf(query_string,"SELECT gid, pinyin,cityname,st_astext(the_geom) FROM cities WHERE gid = %d",gid);
	res = PQexec(conn,query_string);
	if(PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		fprintf(stderr,"Query fail!\n");		
		PQclear(res);
		PQfinish(conn);
		exit(1);		
	}
	if(PQntuples(res)==0)
		printf("Query not result!\n");
	for(i=0;i<PQntuples(res);i++)
		printf("cities information gid pinyin name lonlat: %s %s  %s  %s\n", 
								PQgetvalue(res,i,0),
								PQgetvalue(res,i,1),
								PQgetvalue(res,i,2),
								PQgetvalue(res,i,3));
	PQclear(res);
	PQfinish(conn);
	return 0;	
}



