#include <iostream>

#define MAX_NAME_LEN 30

//1
class Student {
private:
    char name[MAX_NAME_LEN];
    int assessments[5];
    int assessmentCount = 5;
public:
    Student(const char* nameP, int assessmentsP[], int assessmentsCountP) {
        strcpy_s(name, MAX_NAME_LEN, nameP);
        for (int i = 0; i < assessmentCount; i++) {
            assessments[i] = assessmentsP[i];
        }
    }

    int getAvgAssessment() {
        int sum = assessments[0];
        for (int i = 1; i < assessmentCount;i++) {
            sum += assessments[i];
        }
        return sum / assessmentCount;
    }
};

//2
class Cat {
private: 
    char* nickname;
    int age;
public: 
    void askForFood() {
        while (true) {
            std::cout << "Meow nahu" << '\n';
        }
    }
    void makePurr() {
        std::cout << "Muuur nahu" << '\n';
    }
    void printCat() {
        std::cout << "Name: " << nickname << '\n';
        std::cout << "Age: " << age << '\n';
    }
    //Setters модівфікатори
    void setNickname(const char* newNickname) {
        strcpy_s(nickname, MAX_NAME_LEN, newNickname);
    }
    
    void setAge(int newAge) {
        age = newAge > age ? newAge : age;
    }

    //Gaters інспектори
    const char* const getNickname() {
        return nickname;
    }
    int getAge() {
        return age;
    }
};


int main()
{
    //2
    Cat firstCat = Cat();
        firstCat.setNickname("Kokos");
        firstCat.setAge(3);

        firstCat.printCat();

    Cat secondCat = Cat();
        secondCat.setNickname("Asya");
        secondCat.setAge(2);

        secondCat.printCat();

        std::cout << firstCat.getNickname() << '\n';
        std::cout << firstCat.getAge() << '\n';

    //1
    int assesment[5] = { 10, 12 ,4 , 12 , 8 };

    Student student1 = Student("Mykola Tarasenko", assesment, 5);

    std::cout << student1.getAvgAssessment() << '\n';
}