package Communication;

import MES.Main;
import MES.Stock;
import Communication.UDPServer;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import java.io.File;

public class CreateXML {

    public static void CreateResponse() {
        try {
            DocumentBuilderFactory dbFactory =
                    DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.newDocument();

            // root element
            Element rootElement = doc.createElement("Current_Stores");
            doc.appendChild(rootElement);

            // WorkPiece element
            Element WorkPiece1 = doc.createElement("WorkPiece");
            Attr attrType1 = doc.createAttribute("type");
            Attr attrQuantity1 = doc.createAttribute("quantity");
            attrType1.setValue("P1");
            attrQuantity1.setValue(Main.stock.getQuantity("P1") + "");
            WorkPiece1.setAttributeNode(attrType1);
            WorkPiece1.setAttributeNode(attrQuantity1);
            rootElement.appendChild(WorkPiece1);

            // WorkPiece element
            Element WorkPiece2 = doc.createElement("WorkPiece");
            Attr attrType2 = doc.createAttribute("type");
            Attr attrQuantity2 = doc.createAttribute("quantity");
            attrType2.setValue("P2");
            attrQuantity2.setValue(Main.stock.getQuantity("P2") + "");
            WorkPiece2.setAttributeNode(attrType2);
            WorkPiece2.setAttributeNode(attrQuantity2);
            rootElement.appendChild(WorkPiece2);

            // WorkPiece element
            Element WorkPiece3 = doc.createElement("WorkPiece");
            Attr attrType3 = doc.createAttribute("type");
            Attr attrQuantity3 = doc.createAttribute("quantity");
            attrType3.setValue("P3");
            attrQuantity3.setValue(Main.stock.getQuantity("P3") + "");
            WorkPiece3.setAttributeNode(attrType3);
            WorkPiece3.setAttributeNode(attrQuantity3);
            rootElement.appendChild(WorkPiece3);

            // WorkPiece element
            Element WorkPiece4 = doc.createElement("WorkPiece");
            Attr attrType4 = doc.createAttribute("type");
            Attr attrQuantity4 = doc.createAttribute("quantity");
            attrType4.setValue("P4");
            attrQuantity4.setValue(Main.stock.getQuantity("P4") + "");
            WorkPiece4.setAttributeNode(attrType4);
            WorkPiece4.setAttributeNode(attrQuantity4);
            rootElement.appendChild(WorkPiece4);

            // WorkPiece element
            Element WorkPiece5 = doc.createElement("WorkPiece");
            Attr attrType5 = doc.createAttribute("type");
            Attr attrQuantity5 = doc.createAttribute("quantity");
            attrType5.setValue("P5");
            attrQuantity5.setValue(Main.stock.getQuantity("P5") + "");
            WorkPiece5.setAttributeNode(attrType5);
            WorkPiece5.setAttributeNode(attrQuantity5);
            rootElement.appendChild(WorkPiece5);

            // WorkPiece element
            Element WorkPiece6 = doc.createElement("WorkPiece");
            Attr attrType6 = doc.createAttribute("type");
            Attr attrQuantity6 = doc.createAttribute("quantity");
            attrType6.setValue("P6");
            attrQuantity6.setValue(Main.stock.getQuantity("P6") + "");
            WorkPiece6.setAttributeNode(attrType6);
            WorkPiece6.setAttributeNode(attrQuantity6);
            rootElement.appendChild(WorkPiece6);

            // WorkPiece element
            Element WorkPiece7 = doc.createElement("WorkPiece");
            Attr attrType7 = doc.createAttribute("type");
            Attr attrQuantity7 = doc.createAttribute("quantity");
            attrType7.setValue("P7");
            attrQuantity7.setValue(Main.stock.getQuantity("P7") + "");
            WorkPiece7.setAttributeNode(attrType7);
            WorkPiece7.setAttributeNode(attrQuantity7);
            rootElement.appendChild(WorkPiece7);

            // WorkPiece element
            Element WorkPiece8 = doc.createElement("WorkPiece");
            Attr attrType8 = doc.createAttribute("type");
            Attr attrQuantity8 = doc.createAttribute("quantity");
            attrType8.setValue("P8");
            attrQuantity8.setValue(Main.stock.getQuantity("P8") + "");
            WorkPiece8.setAttributeNode(attrType8);
            WorkPiece8.setAttributeNode(attrQuantity8);
            rootElement.appendChild(WorkPiece8);

            // WorkPiece element
            Element WorkPiece9 = doc.createElement("WorkPiece");
            Attr attrType9 = doc.createAttribute("type");
            Attr attrQuantity9 = doc.createAttribute("quantity");
            attrType9.setValue("P9");
            attrQuantity9.setValue(Main.stock.getQuantity("P9") + "");
            WorkPiece9.setAttributeNode(attrType9);
            WorkPiece9.setAttributeNode(attrQuantity9);
            rootElement.appendChild(WorkPiece9);

            // write the content into xml file
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(doc);
            StreamResult result = new StreamResult(new File("/home/sobaca/Downloads/stores.xml"));
            transformer.transform(source, result);

            UDPServer.send();
            
            // Output to console for testing
            StreamResult consoleResult = new StreamResult(System.out);
            transformer.transform(source, consoleResult);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}