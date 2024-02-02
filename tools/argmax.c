#include "../s21_matrix.h"

double argmax(int begin, int end, matrix_t *matrix){

    double max = DBL_MIN;

    for (int i = begin; i < end; ++i) {
        if (max < matrix->matrix[begin][i])
            max = matrix->matrix[begin][i];
    }

    return max;
}