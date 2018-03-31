package com.company;

import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;

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
//                System.out.println("Nodes totais " + listaNodes.getLength());

                /*
                 * Para cada uma das Orders no ficheiro (count)
                 */
                for(int count = 0; count < listaNodes.getLength(); count++) {

                    Node nodo = listaNodes.item(count);
                    /* Aparentemente um ficheiro XML contém Nodes invisíveis */
                    if (nodo.getNodeType() == Node.ELEMENT_NODE) {
                        System.out.println("Tipo Order " + nodo.getNodeName());

                        /* Atributos vão ser aqueles elementos dentro de uma tag <>
                            <CreatePair Bottom="P1" Top="P2" Quantity="3" > eee</CreatePair>
                            Atributos são:          Bottom  Top  Quantity
                            Valores dos atributos:  P1      P2   3
                         */
                        if (nodo.hasAttributes()) {
                            NamedNodeMap nodeMap = nodo.getAttributes();
//                            System.out.println("nodeMap length : " + nodeMap.getLength());
                            /* Para cada um dos atributos.
                                Substituir posteriormente esta rotina de tirar atributos

                             */
                            for (int i = 0; i < nodeMap.getLength(); i++) {
                                Node node = nodeMap.item(i);

                                System.out.println("Nome atributo: " + node.getNodeName());
                                System.out.println("Valor atributo: " + node.getNodeValue());
                            }

                        }
                        /*As Orders vão conter apenas 1 child node, o for countChild é desnecessário, mas whatever

                         */
                        if (nodo.hasChildNodes()) {

                            NodeList nodoChildList = nodo.getChildNodes();
//                            System.out.println("sub length : child n odes   " + nodoChildList.getLength());

                            for(int countChild = 0; countChild < nodoChildList.getLength(); countChild++) {

                                Node nodoChild = nodoChildList.item(countChild);
                                if(nodoChild.getNodeType()==Node.ELEMENT_NODE) {

                                    System.out.println("    Tipo order " + nodoChild.getNodeName());

                                    if(nodoChild.hasAttributes()){
                                        NamedNodeMap nodeChildMap = nodoChild.getAttributes();
//                                        System.out.println("Has attributes, count "+nodeChildMap.getLength());

                                        for(int i = 0 ; i < nodeChildMap.getLength(); i++){
                                            Node subNode = nodeChildMap.item(i);
                                            System.out.println("        Nome : " + subNode.getNodeName());
                                            System.out.println("        Valor : " + subNode.getNodeValue());
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