//
// Created by moyak on 17.02.2023.
//

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Matrix.h"

#define ERROR 0.00001

bool equals(double a, double b) {
    if (std::abs(a - b) < ERROR) {
        return true;
    }
    return false;
}

void Matrix::read_matrix_inp(std::istream &in) {
    int n;
    in >> n;
    for (int i = 1; i <= n; i++) {
        Row raw;
        for (int j = 1; j <= n + 1; j++) {
            double num;
            in >> num;
            raw.add(num);
        }
        (*this).m_data.push_back(raw);
    }
}

Row &Matrix::operator[](int index) const {
    if (index < 0 || index > m_data.size()) {
        throw std::runtime_error("wrong index!");
    } else {
        return (Row &) (m_data[index - 1]);
    }
}


void Matrix::triangulation() {
    for (int j = 1; j < m_data.size(); j++) {
        //find first row with not zero j element
        for (int row_index = j; row_index <= m_data.size(); row_index++) {
            if (!equals((*this)[row_index][j], 0)) {
                if (row_index != j) {
                    (*this)[j] = (*this)[row_index] + (*this)[j];
                }
                break;

            }
        }
        if ((*this)[j][j] == 0) continue;
        for (int i = j + 1; i <= m_data.size(); i++) {
            double koef = (double) (*this)[i][j] / (*this)[j][j];
            (*this)[i] = (*this)[i] - (*this)[j] * koef;
        }
    }
}

//do not save determinant!
void Matrix::normalize() {
    for (int i = 1; i <= m_data.size(); i++) {
        (*this)[i] = (*this)[i] / (*this)[i][i];
    }
}


std::vector<double> Matrix::get_ans() {
    std::vector<double> ans(m_data.size());
    int row_len = (int) (*this)[1].get_size();
    for (int row_idx = (int) m_data.size(); row_idx >= 1; row_idx--) {
        double x = (*this)[row_idx][row_len];
        for (int column = row_len - 1; column > row_idx; column--) {
            x -= ans[column-1] * (*this)[row_idx][column];
        }
        if ((*this)[row_idx][row_idx] != 0) {
            ans[row_idx-1] = x / (*this)[row_idx][row_idx];
        } else {
            ans[row_idx-1] = 0;
        }

    }
    return ans;
}

double Matrix::determinant_in_diagonalized() {
    double det = 1;
    for (int row_idx = 1; row_idx <= m_data.size(); row_idx++) {
        det *= (*this)[row_idx][row_idx];
    }
    if (det_signum_changes % 2 == 1) {
        return -det;
    } else {
        return det;
    }
}

void Matrix::print_matrix(std::ostream &out) {
    for (int row_idx = 1; row_idx <= m_data.size(); row_idx++) {
        for (int column = 1; column <= m_data[1].get_size(); column++) {
            out << std::fixed << std::setprecision(2) << std::setw(7) << (*this)[row_idx][column];
        }
        out << std::endl;
    }
}


void Matrix::solve_gauss(std::istream &in, std::ostream &out) {
    if(m_data.empty()) {
        read_matrix_inp(in);
    }
    print_matrix(out);
    triangulation();
    double det = determinant_in_diagonalized();
    out << "Determinant is: " << det << std::endl;
    normalize();
    print_matrix(out);

    std::vector<double> ans = get_ans();
    out << "Answer is:" << std::endl;
    for (int idx = 0; idx < ans.size(); idx++) {
        out << 'x' << idx + 1 << ": " << ans[idx] << std::endl;
    }
}



