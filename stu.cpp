#include <iostream>
#include <string>
using namespace std;

// 학생 정보를 저장할 구조체
struct Student {
    string name;
    int midterm;
    int final;
};

// 이진 트리 노드를 정의하는 구조체
struct TreeNode {
    Student* student;
    TreeNode* left;
    TreeNode* right;
};

// 새로운 트리 노드를 생성하는 함수
TreeNode* createNode(Student* student) {
    TreeNode* node = new TreeNode();
    node->student = student;
    node->left = node->right = nullptr;
    return node;
}

// 트리에 노드를 삽입하는 함수 (이름을 기준으로 정렬)
TreeNode* insertNode(TreeNode* root, Student* student) {
    if (root == nullptr) {
        return createNode(student);
    }
    if (student->name < root->student->name) {
        root->left = insertNode(root->left, student);
    } else {
        root->right = insertNode(root->right, student);
    }
    return root;
}

// 트리를 중위 순회하며 학생 정보 출력 (이름 오름차순)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << "이름: " << root->student->name
             << ", 중간: " << root->student->midterm
             << ", 기말: " << root->student->final << endl;
        inorderTraversal(root->right);
    }
}

// 학생 이름으로 검색하는 함수
TreeNode* search(TreeNode* root, const string& name) {
    if (root == nullptr || root->student->name == name) {
        return root;
    }
    if (name < root->student->name) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// 메모리 해제 함수
void freeTree(TreeNode* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root->student;  // 학생 데이터 삭제
        delete root;           // 노드 삭제
    }
}

int main() {
    int numStudents;
    cout << "학생 수를 입력하세요: ";
    cin >> numStudents;

    // 동적으로 학생 정보를 저장할 구조체 배열 할당
    Student* students = new Student[numStudents];

    // 학생 정보 입력
    for (int i = 0; i < numStudents; i++) {
        cout << "학생 " << i + 1 << "의 이름을 입력하세요: ";
        cin >> students[i].name;
        cout << "중간 점수를 입력하세요: ";
        cin >> students[i].midterm;
        cout << "기말 점수를 입력하세요: ";
        cin >> students[i].final;
    }

    // 트리에 학생 노드 삽입
    TreeNode* root = nullptr;
    for (int i = 0; i < numStudents; i++) {
        root = insertNode(root, &students[i]);
    }

    // 중위 순회로 학생 정보 출력
    cout << "\n트리 중위 순회 결과:\n";
    inorderTraversal(root);

    // 학생 이름으로 검색
    string searchName;
    cout << "\n검색할 학생의 이름을 입력하세요: ";
    cin >> searchName;
    TreeNode* result = search(root, searchName);

    if (result != nullptr) {
        cout << "검색 결과 - 이름: " << result->student->name
             << ", 중간: " << result->student->midterm
             << ", 기말: " << result->student->final << endl;
    } else {
        cout << "학생을 찾을 수 없습니다." << endl;
    }

    // 메모리 해제
    freeTree(root);
    delete[] students;

    return 0;
}
