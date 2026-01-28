package csd.uoc.gr.A22;

import csd.uoc.gr.A22.Exceptions.KoumparasIsBrokenException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsFullException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsNotBroken;

public abstract class KoumparasADT {

    /**
     *
     * @return true if koumparas is full, false if koumparas is not full
     * @preconditions: none
     * @postconditions: none
     * @throws KoumparasIsFullException
     */
    public abstract void isFull() throws KoumparasIsFullException;

    /**
     *
     * @return true if koumparas is broken, false if koumparas is not broken
     * @preconditions: none
     * @postconditions: true if koumparas is broken
     * @throws KoumparasIsBrokenException
     * @throws KoumparasIsNotBroken
     */
    public abstract void isBroken() throws KoumparasIsBrokenException, KoumparasIsNotBroken;

    /**
     * @preconditions: not broken
     * @postconditions: getNumberOfMoney()
     * @param s is money
     * @throws KoumparasIsFullException
     * @throws KoumparasIsBrokenException
     */
    public abstract void add(Money s) throws KoumparasIsFullException,KoumparasIsBrokenException;

    /**
     * @preconditions: none
     * @postconditions: koumparas is broken
     */
    public abstract void Break();



}
