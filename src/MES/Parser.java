package MES;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Iterator;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.*;

public class Parser {
    @SuppressWarnings({ "unchecked", "null" })
    public Order parseFile(String pathToFile) {
        try {
            XMLInputFactory factory = XMLInputFactory.newInstance();
            InputStream in = new FileInputStream(pathToFile);
            XMLEventReader eventReader =
                    factory.createXMLEventReader(in);
            String number = "number";
            while (eventReader.hasNext()) {
                XMLEvent event = eventReader.nextEvent();
                switch (event.getEventType()) {

                    case XMLStreamConstants.START_ELEMENT:
                        StartElement startElement = event.asStartElement();
                        String qName = startElement.getName().getLocalPart();

                        if (qName.equalsIgnoreCase("Order")) {
                            System.out.println("Order");
                            Iterator<Attribute> attributes = startElement.getAttributes();
                            number = attributes.next().getValue();
                            System.out.println("Number : " + number);

                        } else if (qName.equalsIgnoreCase("Unload")) {
                            Unload unLoad = new Unload(number);
                            System.out.println("unLoad");
                            Iterator<Attribute> attributes = startElement.getAttributes();
                            while (attributes.hasNext()) {
                                Attribute attribute = attributes.next();
                                if (attribute.getName().toString().equals("Type")) {
                                    unLoad.setType(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("Destination")) {
                                    unLoad.setDestination(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("Quantity")) {
                                    unLoad.setQuantity(attribute.getValue());
                                }
                            }
                            System.out.println("type: " + unLoad.getType());
                            System.out.println("destination: " + unLoad.getDestination());
                            System.out.println("quantity: " + unLoad.getQuantity());
                        } else if (qName.equalsIgnoreCase("Load")) {
                            Load load = new Load(number);
                            System.out.println("Load");
                            Iterator<Attribute> attributes = startElement.getAttributes();
                            while (attributes.hasNext()) {
                                Attribute attribute = attributes.next();
                                if (attribute.getName().toString().equals("Type")) {
                                    load.setType(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("From")) {
                                    load.setFrom(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("Quantity")) {
                                    load.setQuantity(attribute.getValue());
                                }
                            }
                        } else if (qName.equalsIgnoreCase("Transform")) {
                            Transform transform = new Transform(number);
                            System.out.println("Transform");
                            Iterator<Attribute> attributes = startElement.getAttributes();
                            while (attributes.hasNext()) {
                                Attribute attribute = attributes.next();
                                if (attribute.getName().toString().equals("From")) {
                                    transform.setFrom(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("To")) {
                                    transform.setTo(attribute.getValue());
                                }
                                if (attribute.getName().toString().equals("Quantity")) {
                                    transform.setQuantity(attribute.getValue());
                                }
                            }
                        }
                        break;
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
        return null;
    }
}