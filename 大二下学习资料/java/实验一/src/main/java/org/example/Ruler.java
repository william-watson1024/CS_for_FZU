package org.example;

import java.util.List;

public class Ruler {
    int[] bucket;
    void initial(List<Integer> l){
        for(int x:l){
            bucket[x]++;
        }
    }
    boolean checkYiXiu(){
        return bucket[4] == 1;
    }
    boolean checkErJu(){
        return bucket[4] == 2;
    }
    boolean checkSanHong(){
        return bucket[4] == 3;
    }
    boolean checkSiJin(){
        for(int i=1;i<=6;i++){
            if(i!=4&& bucket[i]==4){
                return true;
            }
        }
        return false;
    }
    boolean checkDuiTang(){
        for(int i=1;i<=6;i++){
            if(bucket[i]!=1){
                return false;
            }
        }
        return true;
    }
    boolean checkZhuangYuan(){
        return bucket[4] == 4;
    }
    boolean checkWuZi(){
        for(int i=1;i<=6;i++){
            if(bucket[i]>=5){
                return true;
            }
        }
        return false;
    }
    boolean checkLiuBeiHong(){
        return bucket[4] == 6;
    }
    boolean checkZhuangYuanJinHua(){
        return bucket[4] == 4&&bucket[1]==2;
    }

    public Ruler() {
        bucket= new int[]{0, 0, 0, 0, 0, 0, 0};
    }
}
