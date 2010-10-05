import java.lang.*;
import java.util.*;
import java.sql.*;

public class pg{

public static void main(String argv[]){
System.out.println("start...");
//init database connection
Connection pdb;
try
{
	Class.forName("org.postgresql.Driver");
}
catch(java.lang.ClassNotFoundException e) {
System.out.println("err:class.forname.");
}
try
{
pdb=DriverManager.getConnection("jdbc:postgresql://localhost/postgres","postgres","osgis");
Statement stmt=pdb.createStatement();
ResultSet rs=stmt.executeQuery("select * from statename");
if(rs!=null)
{
System.out.println("get data from database:");
while(rs.next())
{
System.out.print(rs.getString(1));
System.out.print(rs.getString(2));
System.out.print("");
}
}
rs.close();
stmt.close();
pdb.close();
}
catch(Exception e)
{
	e.printStackTrace();
}
}
}