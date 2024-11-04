#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Student {
    int midterm;
    int final;
};

int main() {
    int numStudents;
    cout << "학생 수를 입력하세요: ";
    cin >> numStudents;

    // 이름을 키로, Student 구조체를 값으로 저장하는 map
    map<string, Student> students;

    // 학생 정보 입력
    for (int i = 0; i < numStudents; i++) {
        string name;
        Student student;

        cout << "학생 " << i + 1 << "의 이름을 입력하세요: ";
        cin >> name;
        cout << "중간 점수를 입력하세요: ";
        cin >> student.midterm;
        cout << "기말 점수를 입력하세요: ";
        cin >> student.final;

        // map에 저장
        students[name] = student;
    }

    // 모든 학생 정보 출력 (map은 자동으로 이름 순서대로 정렬됨)
    cout << "\n학생 목록 (이름 순서):\n";
    for (const auto& [name, student] : students) {
        cout << "이름: " << name
             << ", 중간: " << student.midterm
             << ", 기말: " << student.final << endl;
    }

    // 학생 이름으로 검색
    string searchName;
    cout << "\n검색할 학생의 이름을 입력하세요: ";
    cin >> searchName;

    auto it = students.find(searchName);
    if (it != students.end()) {
        cout << "검색 결과 - 이름: " << it->first
             << ", 중간: " << it->second.midterm
             << ", 기말: " << it->second.final << endl;
    } else {
        cout << "학생을 찾을 수 없습니다." << endl;
    }

    return 0;
}
