package org.example;

public enum Rank {
    ACE("A"),
    TWO("2"),
    THREE("3"),
    FOUR("4"),
    FIVE("5"),
    SIX("6"),
    SEVEN("7"),
    EIGHT("8"),
    NINE("9"),
    TEN("10"),
    JACK("J"),
    QUEEN("Q"),
    KING("K");

    private final String rankValue;

    Rank(String rankValue) {
        this.rankValue = rankValue;
    }

    @Override
    public String toString() {
        return rankValue;
    }
}