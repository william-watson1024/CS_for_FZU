package org.example;

public enum Suit {
    SPADE("♠"),
    HEART("♥"),
    Club("♣"),
    Diamond("♦");

    private final String symbol;

    Suit(String symbol) {
        this.symbol = symbol;
    }

    @Override
    public String toString() {
        return symbol;
    }
}
