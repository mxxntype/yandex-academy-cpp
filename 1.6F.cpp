#include <cstddef>
#include <iostream>
#include <vector>

typedef struct t_field {
    size_t rows;
    size_t cols;
    std::vector<std::vector<int>> matrix;
} t_field;

void print_field(const t_field &matrix);
size_t count_neighbour_mines(const t_field &matrix, size_t row, size_t col);

int main(void) {
    t_field field;
    size_t mine_count = 0;

    std::cin >> field.rows >> field.cols >> mine_count;
    field.matrix.resize(field.rows);
    for (size_t row = 0; row < field.rows; row++) field.matrix.at(row).resize(field.cols);

    for (size_t mine_id = 0; mine_id < mine_count; mine_id++) {
        size_t row = 0;
        size_t col = 0;
        std::cin >> row >> col;

        field.matrix.at(row - 1).at(col - 1) = 1;
    }

    print_field(field);

    return 0;
}

void print_field(const t_field &field) {
    for (size_t row = 0; row < field.rows; row++) {
        for (size_t col = 0; col < field.cols; col++) {
            if (field.matrix.at(row).at(col) == 1)
                std::cout << '*';
            else
                std::cout << count_neighbour_mines(field, row, col);
            if (col < field.cols - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

size_t count_neighbour_mines(const t_field &matrix, size_t row, size_t col) {
    size_t count = 0;
    for (int offset_row = -1; offset_row <= 1; offset_row++) {
        for (int offset_col = -1; offset_col <= 1; offset_col++) {
            if (offset_row == 0 && offset_col == 0) continue;

            int _row = (int)row + offset_row;
            int _col = (int)col + offset_col;

            if (_row >= 0 && (size_t)_row < matrix.rows && _col >= 0 && (size_t)_col < matrix.cols) {
                count += matrix.matrix.at(_row).at(_col);
            }
        }
    }
    return count;
}
