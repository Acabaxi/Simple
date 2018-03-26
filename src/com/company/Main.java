package com.company;
import java.net.*;
import java.io.*;


import com.sun.org.apache.xpath.internal.operations.Mod;
import net.wimpi.modbus.*;
import net.wimpi.modbus.msg.*;
import net.wimpi.modbus.io.*;
import net.wimpi.modbus.net.*;
import net.wimpi.modbus.util.*;

/*
 * XML parser
 */
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;

import org.w3c.dom.*;

import java.io.File;

/*JAVA is cool
 */
class Order{
/**
 * Order class
 *
 */
    int orderNumber;
}

class Unload extends Order{
    /**
     * Unload order
     * @param orderNumber
     */

    int unloadType;
    int destinationRoll;
    int amountUnload;
}

class Parser{

    Parser(){

    }


    public static void parseXML(){

        try {
            File ficheiro = new File("/home/pedro/IdeaProjects/Simple/out/production/Simple/com/company/CommandList");

            if(ficheiro.exists() && !ficheiro.isDirectory()) {
                System.out.println("Existe ficheiro");
            }

            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(ficheiro);

            if(doc.hasChildNodes()){
                NodeList listaNodes;

                /*
                *
                * getChildNodes.item.getChildNodes para selecionar os subnodes (Order) do  node
                * principal (OrderList, necessário para ter um ficheiro XML válido
                *
                */
                listaNodes = doc.getChildNodes().item(0).getChildNodes();
                System.out.println("Nodes totais " + listaNodes.getLength());

                /*
                 * Para cada uma das Orders no ficheiro (count)
                 */
                for(int count = 0; count < listaNodes.getLength(); count++) {

                    Node nodo = listaNodes.item(count);
                    /* Aparentemente um ficheiro XML contém Nodes invisíveis */
                    if (nodo.getNodeType() == Node.ELEMENT_NODE) {
                        System.out.println("Existe " + nodo.getNodeName());

                        /* Atributos vão ser aqueles elementos dentro de uma tag <>
                            <CreatePair Bottom="P1" Top="P2" Quantity="3" > eee</CreatePair>
                            Atributos são:          Bottom  Top  Quantity
                            Valores dos atributos:  P1      P2   3
                         */
                        if (nodo.hasAttributes()) {
                            NamedNodeMap nodeMap = nodo.getAttributes();
                            System.out.println("nodeMap length : " + nodeMap.getLength());
                            /* Para cada um dos atributos.
                                Substituir posteriormente esta rotina de tirar atributos

                             */
                            for (int i = 0; i < nodeMap.getLength(); i++) {
                                Node node = nodeMap.item(i);

                                System.out.println("attr name : " + node.getNodeName());
                                System.out.println("attr value : " + node.getNodeValue());
                            }

                        }
                        /*As Orders vão conter apenas 1 child node, o for countChild é desnecessário, mas whatever

                         */
                        if (nodo.hasChildNodes()) {

                            NodeList nodoChildList = nodo.getChildNodes();
                            System.out.println("sub length : child n odes   " + nodoChildList.getLength());

                            for(int countChild = 0; countChild < nodoChildList.getLength(); countChild++) {

                                Node nodoChild = nodoChildList.item(countChild);
                                if(nodoChild.getNodeType()==Node.ELEMENT_NODE) {

                                    System.out.println(nodoChild.getNodeName());
                                    if(nodoChild.hasAttributes()){
                                        NamedNodeMap nodeChildMap = nodoChild.getAttributes();
                                        System.out.println("Has attributes, count "+nodeChildMap.getLength());

                                        for(int i = 0 ; i < nodeChildMap.getLength(); i++){
                                            Node subNode = nodeChildMap.item(i);
                                            System.out.println("subnode name : " + subNode.getNodeName());
                                            System.out.println("subnode value : " + subNode.getNodeValue());
                                        }

                                    }
                                }
                            }

                        }
                    }
                }

            }
            else
                System.out.println("Nao Tem nodes");


        }catch(Exception e){
            System.out.println("Failed to create Doc builder");
            System.exit(-1);
        }


    }

}

public class Main{


    public static void main(String args[]){

        Parser.parseXML();

        /* The important instances of the classes mentioned before */
        TCPMasterConnection con = null; //the connection
        ModbusTCPTransaction trans = null; //the transaction
        WriteCoilRequest req = null; //the request
        ReadInputDiscretesResponse res = null; //the response


        InetAddress addr = null; //the slave's address
        try {
            addr = InetAddress.getByName("localhost"); //the slave's address
        } catch (UnknownHostException e){
            e.printStackTrace();
            System.exit(1);
        }

        System.out.println(addr.getHostName()+ "  "+addr.getHostAddress());

        int port = 5502;
        int ref = 0; //the reference; offset where to start reading from
        int count = 0; //the number of DI's to read






        con = new TCPMasterConnection(addr);
        con.setPort(port);

        System.out.println(con.getPort());

        try {
            con.connect();
        } catch(Exception langException){

            System.out.println("Failed to connect");
            langException.printStackTrace();
            System.exit(1);
        }



        trans = new ModbusTCPTransaction(con);


        int i;
        for(i=1 ;i < 10; i+=2){
            try {
                req = new WriteCoilRequest(i,true);
                trans.setRequest(req);
                trans.execute();
                System.out.println(i);
            } catch(ModbusException md){
                System.out.println("Failed to send request");
                System.exit(1);
            }
        }


    }

}
