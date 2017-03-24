#include <iostream>
#include <string>
#include <algorithm>

//converts integer to roman number string
std::string toRomNum(unsigned int x){
        std::string romNum;
        while(x!=0){
                if(x>=1000){x-=1000;romNum+="M";}
                else if(x>=900){x-=900;romNum+="CM";}
                else if(x>=500){x-=500;romNum+="D";}
                else if(x>=400){x-=400;romNum+="CD";}
                else if(x>=100){x-=100;romNum+="C";}
                else if(x>=90){x-=90;romNum+="XC";}
                else if(x>=50){x-=50;romNum+="L";}
                else if(x>=40){x-=40;romNum+="XL";}
                else if(x>=10){x-=10;romNum+="X";}
                else if(x>=9){x-=9;romNum+="IX";}
                else if(x>=5){x-=5;romNum+="V";}
                else if(x>=4){x-=4;romNum+="IV";}
                else{x-=1;romNum+="I";}
        }
        return romNum;
}

//number that uses each of the symbols I, V, X, L, C, D and M at least once
bool isPandigital(int x){
        std::string romNum=toRomNum(x);
        for(char c : {'M','D','C','L','X','V','I'})
                if(!std::count(romNum.begin(),romNum.end(),c))
                        return 0;
        return 1;
}

//number that is pandigital in Roman numerals and uses each of the symbols I, V, X, L, C, D and M exactly once
bool challengeInput(int x){
        std::string romNum=toRomNum(x);
        for(char c : {'M','D','C','L','X','V','I'})
                if(std::count(romNum.begin(),romNum.end(),c)!=1)
                        return 0;
        return 1;
}

int main(){
        for(int i=0;i<2001;i++){
                if(isPandigital(i)){
                        std::cout<<i<<":"<<toRomNum(i)<<std::endl;
                }
        }
}
