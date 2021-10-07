//
// Created by 32202733 오현택 on 2021/09/20.
//
#include<iostream>

class Vector {
public:
    int x, y, z;

    void display() const {
        std:: cout<<"\n입력된 벡터 값: "<<x<<"i + "<<y<<"j + "<<z<<"k\n";
    }

    void set_vector() {
        std:: cout <<"\n각 축에 할당할 스칼라 값을 입력하시오. \nx축에 할당한 값: ";
        std::cin >> x;
        std:: cout << "\ny축에 할당한 값: ";
        std::cin >> y;
        std:: cout <<"\nz축에 할당한 값: ";
        std:: cin >> z;
    }

    void modify() {
        int number;
        display();
        std:: cout<<"\n수정하고 싶은 축을 고르십시오.\n1. x축\n2. y축\n3. z축\n";
        std:: cin>> number;
        if(number == 1) {
            std:: cout<<"\n새로운 x축 값을 입력하시오: ";
            std:: cin>>x;
        }
        else if(number == 2) {
            std:: cout<<"\n새로운 y축 값을 입력하시오: ";
            std:: cin>>y;
        }
        else if(number == 3) {
            std:: cout<<"\n새로운 z축 값을 입력하시오: ";
            std:: cin>>z;
        }
        else {
            std:: cout<<"잘못된 입력입니다. 현재 벡터 값이 그대로 유지됩니다.\n";
        }
        display();
    }

    void multiply() {
        int scalar;
        std:: cout<<"\n곱할 스칼라 값을 입력하시오: ";
        std:: cin>>scalar;
        x = x * scalar;
        y = y * scalar;
        z = z * scalar;
        display();
    }

};

int main() {
    Vector i{};
    i.set_vector();
    i.modify();
    i.multiply();
}