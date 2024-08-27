package org.example;


import java.util.List;

public class Gamer {
    int local;
    List <Integer> point;
    Prize prize;
    boolean chace;

    String check() {
        Ruler ruler = new Ruler();
        ruler.initial(point);
        chace=false;
        if (ruler.checkLiuBeiHong()) {
            return getLiuBeiHong();
        } else if (ruler.checkZhuangYuanJinHua()) {
            return getCheckZhuangYuanJinHua();
        } else if (ruler.checkWuZi()) {
            return getWuzi();
        } else if (ruler.checkZhuangYuan()) {
            return getZhuangYuan();
        } else if (ruler.checkDuiTang()) {
            return getDuiTang();
        } else if (ruler.checkSanHong()) {
            return getSanHong();
        } else if (ruler.checkSiJin()) {
            return getSiJin();
        } else if (ruler.checkErJu()) {
            return getErJu();
        } else if (ruler.checkYiXiu()) {
            return getYiXiu();
        }
        return "无奖，继续努力";
    }

    @Override
    public String toString() {
        return "玩家" + local + prize+"\n";
    }

    public Gamer(int local) {
        this.local = local;
        prize=new Prize();

    }

    public String getYiXiu() {
        if (Game.prize.yiXiu > 0) {
            Game.prize.yiXiu--;
            this.prize.yiXiu++;
            Game.prize.sum--;
            return "一秀！恭喜！";
        } else {
            return "已经没有一秀饼了，抱歉！";
        }
    }

    public String getErJu() {
        if (Game.prize.erJu > 0) {
            Game.prize.erJu--;
            this.prize.erJu++;
            Game.prize.sum--;
            return "二举！恭喜！";
        } else {
            return "已经没有二举了，抱歉！";
        }
    }

    public String getSiJin() {
        if (Game.prize.siJing > 0) {
            Game.prize.siJing--;
            this.prize.siJing++;
            Game.prize.sum--;
            return "四进！恭喜！";
        } else {
            return "已经没有四进了，抱歉！";
        }
    }

    public String getSanHong() {
        if (Game.prize.sanHong > 0) {
            Game.prize.sanHong--;
            this.prize.sanHong++;
            Game.prize.sum--;
            return "三红！恭喜！";
        } else {
            return "已经没有三红了，抱歉！";
        }
    }

    public String getDuiTang() {
        if (Game.prize.duiTang > 0) {
            Game.prize.duiTang--;
            this.prize.duiTang++;
            Game.prize.sum--;
            return "对堂！恭喜！";
        } else {
            return "已经没有对堂了，抱歉！";
        }
    }

    public String getZhuangYuan() {
        if (Game.prize.zhuangYuan > 0) {
            Game.prize.zhuangYuan--;
            this.prize.zhuangYuan++;
            Game.prize.sum--;
            Game.zhuangYuanLevel=1;
            Game.lastZhuangYuan=local;
            return "状元！恭喜！";
        } else {
            return "已经没有状元了，抱歉！";
        }
    }
    public String getLiuBeiHong(){
        this.prize.yiXiu += Game.prize.yiXiu;
        this.prize.erJu += Game.prize.erJu;
        this.prize.sanHong += Game.prize.sanHong;
        this.prize.siJing += Game.prize.siJing;
        this.prize.duiTang += Game.prize.duiTang;
        this.prize.zhuangYuan += Game.prize.zhuangYuan;
        Game.prize.sum = 0;
        chace=true;
        return "六杯红大奖！恭喜！";
    }

    public String getCheckZhuangYuanJinHua(){
            if (Game.prize.zhuangYuan > 0) {
                this.prize.zhuangYuan ++;
                Game.prize.zhuangYuan --;
                Game.prize.sum --;
                Game.zhuangYuanLevel=3;
                Game.lastZhuangYuan=local;
                return "状元插金花！恭喜！";
            } else if (Game.zhuangYuanLevel < 3) {
                Game.zhuangYuanLevel=3;
                chace=true;
                return "追饼！状元插金花！恭喜！";
            }
            return "已经没有状元插金花了，抱歉！";
        }
    public String getWuzi(){
        if (Game.prize.zhuangYuan > 0) {
            this.prize.zhuangYuan ++;
            Game.prize.zhuangYuan --;
            Game.prize.sum --;
            Game.zhuangYuanLevel=2;
            Game.lastZhuangYuan=local;
            return "五子登科！恭喜！";
        } else if (Game.zhuangYuanLevel < 2) {
            Game.zhuangYuanLevel=2;
            chace=true;
            return "追饼！五子登科！恭喜！";
        }
        return "已经没有五子登科了，抱歉！";
    }

}
