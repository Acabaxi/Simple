package MES;

public class UDPTest {
    UDPClient client;

    public void setup(){
        new UDPServer().start();
        client = new UDPClient();
    }

    public void whenCanSendAndReceivePacket_thenCorrect() {
        String echo = client.sendEcho("hello server");
        //assertEquals("hello server", echo);
        echo = client.sendEcho("server is working");
        //assertFalse(echo.equals("hello server"));
    }

    public void tearDown() {
        client.sendEcho("end");
        client.close();
    }
}