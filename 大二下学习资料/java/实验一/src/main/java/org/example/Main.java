package org.example;

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        Game game = new Game();
        game.initial();
        List<Gamer> gamers = new ArrayList<>();
        for (int i = 1; i<= Game.gamerCount; i++){
            gamers.add(new Gamer(i));
        }

        int x=-1;
        while (Game.prize.sum!=0){
            x++;
            x=x% Game.gamerCount;
            game.start(gamers.get(x).local);
            gamers.get(x).point=game.play();
            System.out.print("玩家"+gamers.get(x).local+"投出了");
            for(int i:gamers.get(x).point){
                System.out.print(i+",");
            }
            System.out.print(gamers.get(x).check()+"\n");
            if (gamers.get(x).chace){
                gamers.get(x).prize.zhuangYuan++;
                gamers.get(Game.lastZhuangYuan-1).prize.zhuangYuan--;
                Game.lastZhuangYuan=gamers.get(x).local;
            }
        }
        for(Gamer gamer:gamers){
            System.out.printf(gamer.toString());
        }
    }
}