package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Deck {
    private final List<Card> cards;
    private final List<Card> playedCards;

    public Deck() {
        cards = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            for (Rank rank : Rank.values()) {
                cards.add(new Card(suit, rank));
            }
        }
        playedCards = new ArrayList<>();
    }

    public void shuffle() {
        Collections.shuffle(cards);
    }

    public Card deal() {
        if (!cards.isEmpty()) {
            return cards.remove(0);
        } else {
            return null;
        }
    }

    public boolean canCollect(Card currentCard) {
        for (Card playedCard : playedCards) {
            if (playedCard.canCollect(currentCard)) {
                return true;
            }
        }
        return false;
    }

    public boolean collect(Card currentCard) {
        List<Card> toRemove = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean remove=false;
        for (Card playedCard : playedCards) {
            if (playedCard.canCollect(currentCard)&&!remove) {
                System.out.print("你想从"+playedCard+"开始收牌吗？(y/n): ");
                String input = scanner.nextLine().trim().toLowerCase();
                if ("y".equals(input)){
                remove=true;
                }
            }
            if (remove){
                toRemove.add(playedCard);
            }
        }
        playedCards.removeAll(toRemove);

        return !toRemove.isEmpty();
    }

    public boolean playGame() {
        shuffle();

        while (!cards.isEmpty()) {
            System.out.println("剩余牌的数量为："+cards.size()+'\n');
            System.out.println("请确认发牌：");
            Scanner scanner = new Scanner(System.in);
            scanner.nextLine();
            Card dealtCard = deal();
            System.out.println("发牌为: " + dealtCard);
            System.out.println("当前牌的情况是" + playedCards);
            if (canCollect(dealtCard)) {
                System.out.println("你可以选择收牌\n");
                System.out.print("你想收牌吗？(y/n): ");
                String input = scanner.nextLine().trim().toLowerCase();
                if ("y".equals(input)&&collect(dealtCard)) {
                    System.out.println("收牌成功！\n");
                    System.out.println("当前牌的情况是" + playedCards);
                } else {
                    System.out.println("放弃收牌。\n");
                    playedCards.add(dealtCard);
                }
            }else{
                playedCards.add(dealtCard);
            }
        }
        System.out.println("当前牌的情况是" + playedCards);
        return playedCards.isEmpty();
    }
}
