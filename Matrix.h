//
// Created by moyak on 17.02.2023.
//

#ifndef UNTITLED8_MATRIX_H
#define UNTITLED8_MATRIX_H
#include <utility>
#include <vector>
#include <fstream>
#include "Row.h"
class Matrix {
public:
    Matrix() = default;

    void read_matrix_inp(std::istream& in);

    void triangulation();

    void normalize();

    void solve_gauss(std::istream& in, std::ostream& out);

    double determinant_in_diagonalized();

    void print_matrix(std::ostream& out);
    std::vector<double> get_ans();

    Row &operator[](int index) const;


    [[nodiscard]] std::vector<Row> get_data() const {
        return m_data;
    }
    void set_data(std::vector<Row> data) {
        m_data = std::move(data);
    }
private:
    std::vector<Row> m_data;
    int det_signum_changes = 0;
};


#endif //UNTITLED8_MATRIX_H
