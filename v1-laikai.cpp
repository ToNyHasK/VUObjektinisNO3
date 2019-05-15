#include "functions.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
//Tests
struct studentasTest : testing::Test {
    studentas* allMarks;
    studentas* firstName;
    studentas* secondName;
    studentas* egz;
    studentasTest() {
        allMarks = new studentas;
        firstName = new studentas;
        secondName = new studentas;
        egz = new studentas;
    }
    ~studentasTest() {
        delete allMarks;
        delete firstName;
        delete secondName;
        delete egz;
    }
};
TEST_F(studentasTest, allMarksStudentas) {
   EXPECT_EQ(0, allMarks->getAllMarks());
}
TEST_F(studentasTest, nameStudentas) {
    EXPECT_EQ("Vardas", firstName->getName());
}
TEST_F(studentasTest, surnameStudentas) {
    EXPECT_EQ("Pavarde", secondName->getSurname());
}
TEST_F(studentasTest, egzStudentas) {
    EXPECT_EQ(0, egz->getEgz());
}
int main(int argc, char* argv[]) {

    int pasirinkimas = 1;
    /*cout << "Ar norite, kad faile butu galutinis su vidurkiu, ar su mediana? Virdurkis, spauskite 1, mediana 0\n";

        cin >> pasirinkimas;
        checkInput(pasirinkimas);*/

    vector <studentas> a;

    vector <studentas> protV;

    int index = 0;
   //Antroji strategija
    Timer t;
    createFiles(a, pasirinkimas);
    readFile (index, a);
    sortSbyName(a);
    vargProt(a, protV);
    sortStud(a, pasirinkimas, protV);
    cout << "Elapsed time(whole program, second strategy) with vector: " << t.elapsed() << " s\n";
    a.clear();
    protV.clear();
    t.reset();
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}