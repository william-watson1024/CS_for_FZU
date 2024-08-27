package org.example;

//TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击间距中的 <icon src="AllIcons.Actions.Execute"/> 图标。
public class Main {
    public static void main(String[] args) {

        while (true){
        Deck deck = new Deck();
        if (deck.playGame()) {
            System.out.println("恭喜，你赢得了这个游戏！");
        } else {
            System.out.println("抱歉，你输了，再试试看吧？");
        }
        }

    }
}