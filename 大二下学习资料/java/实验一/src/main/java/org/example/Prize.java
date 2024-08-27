package org.example;

public class Prize {
    int yiXiu;
    int erJu;
    int siJing;
    int sanHong;
    int duiTang;
    int zhuangYuan;
    int sum;
    public void calculateAndUpdateSum() {
        // 计算其他变量的和
        sum = yiXiu + erJu + siJing + sanHong + duiTang + zhuangYuan;
    }

    @Override
    public String toString() {
        return "得奖情况{" +
                "一秀饼=" + yiXiu +
                "个, 二举饼=" + erJu +
                "个, 三红饼=" + sanHong +
                "个, 四进饼=" +  siJing+
                "个, 对堂饼=" + duiTang +
                "个, 状元饼=" + zhuangYuan +
                "个}";
    }

    public Prize() {
    }
}
