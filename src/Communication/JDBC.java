package Communication;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class JDBC {
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_RESET = "\u001B[0m";

    public static void connect() {
        String host = "db.fe.up.pt:5432";
        String username = "sara";
        String password = "password";

        try {
            Connection con = DriverManager.getConnection( host, username, password );
            System.out.println(ANSI_BLUE + "-- Running Server UDP at " + host + "--" + ANSI_RESET);

            //Example Read
            //Example write

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}