package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Game {
    static Prize prize;
    static Prize situation;
    static int gamerCount;
    static int zhuangYuanLevel;
    static int lastZhuangYuan;

    void initial(){
        setPrize();
        setGamerCount();
    }
    void setPrize(){
        System.out.print("请设置奖品数\n");
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入一秀的个数：");
        prize.yiXiu= scanner.nextInt();
        System.out.print("请输入二举的个数：");
        prize.erJu= scanner.nextInt();
        System.out.print("请输入三红的个数：");
        prize.sanHong= scanner.nextInt();
        System.out.print("请输入四进的个数：");
        prize.siJing= scanner.nextInt();
        System.out.print("请输入对堂的个数：");
        prize.duiTang= scanner.nextInt();
        System.out.print("请输入状元的个数：");
        prize.zhuangYuan= scanner.nextInt();
        prize.calculateAndUpdateSum();
    }

    public void setGamerCount() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入玩家人数：");
        gamerCount = scanner.nextInt();
    }
    void start(int i){
        System.out.print(i+"号玩家请掷骰子:");
        Scanner scanner = new Scanner(System.in);
        String s= scanner.next();
    }

    List<Integer> play(){
        List<Integer> l = new ArrayList<>();
        Random random = new Random();
        for (int i=1;i<=6;i++){
            l.add(random.nextInt(6)+1);
        }
        return l;
    }

//    List<Integer> play(){
//        List<Integer> l = new ArrayList<>();
//        Scanner scanner = new Scanner(System.in);
//        Random random = new Random();
//        for (int i=1;i<=6;i++){
//            l.add(scanner.nextInt());
//        }
//        return l;
//    }

    public Game() {
        prize=new Prize();
        situation=new Prize();
    }

}
