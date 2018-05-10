package MES;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Iterator;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.*;

public class Parser {

    public Parser(){}

    @SuppressWarnings({ "unchecked", "null" })
    public Order parseFile(String xml) {
        try {
            XMLInputFactory factory = XMLInputFactory.newInstance();
            InputStream in = new ByteArrayInputStream(xml.getBytes(StandardCharsets.UTF_8));
            XMLEventReader eventReader = factory.createXMLEventReader(in);
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
                            Unload unLoad = new Unload(number, "U");
                            //System.out.println("Do : unLoad");
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
                                    unLoad.setQuantity(Integer.parseInt(attribute.getValue()));
                                }
                            }
                            //System.out.println("type: " + unLoad.getType());
                            //System.out.println("destination: " + unLoad.getDestination());
                            //System.out.println("quantity: " + unLoad.getQuantity());
                            return unLoad;
                        } else if (qName.equalsIgnoreCase("Load")) {
                            Load load = new Load(number, "L");
                            //System.out.println("Do : Load");
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
                            //System.out.println("type: " + load.getType());
                            //System.out.println("from: " + load.getFrom());
                            //System.out.println("quantity: " + load.getQuantity());
                            return load;
                        } else if (qName.equalsIgnoreCase("Transform")) {
                            Transform transform = new Transform(number, "T");
                            //System.out.println("Do : Transform");
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
                                    transform.setQuantity(Integer.parseInt(attribute.getValue()));
                                }
                            }
                            //System.out.println("from: " + transform.getFrom());
                            //System.out.println("to: " + transform.getTo());
                            //System.out.println("quantity: " + transform.getQuantity());
                            return transform;
                        }
                        break;
                }
            }
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
        return null;
    }
}