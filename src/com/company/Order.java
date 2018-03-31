package com.company;

public class Order{
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