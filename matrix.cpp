#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    
    // 행렬의 크기 입력받기
    std::cout << "행렬의 행(row) 수와 열(column) 수를 입력하세요: ";
    std::cin >> rows >> cols;

    // 첫 번째 행렬 생성
    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(cols));
    
    // 두 번째 행렬 생성
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols));

    // 결과 행렬 생성
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    // 첫 번째 행렬 입력
    std::cout << "첫 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix1[i][j];
        }
    }

    // 두 번째 행렬 입력
    std::cout << "두 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix2[i][j];
        }
    }

    // 두 행렬의 합 계산
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 결과 출력
    std::cout << "두 행렬의 합:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
