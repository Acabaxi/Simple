package Communication;

import org.postgresql.Driver;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class JDBC {
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_RESET = "\u001B[0m";

    public static void connect() {
        //"jdbc:postgresql://localhost:5432/testdb"
        String host = "jdbc:postgresql://db.fe.up.pt:5432/up201502825";
        String username = "up201502825";
        String password = "VkgSgU9P8";
        Connection con;

        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try {
            con = DriverManager.getConnection( host, username, password );
            System.out.println(ANSI_BLUE + "-- DataBase connected " + host + "--" + ANSI_RESET);

            //Example Read
            //Example write

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}