int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize, int** returnColumnSizes) {

    int total = matSize * matColSize[0];

    if (total != r * c || (matSize == r && matColSize[0] == c)) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** result = malloc(r * sizeof(int*));
    *returnColumnSizes = malloc(r * sizeof(int));

    *returnSize = r;

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < total; i++) {
        result[i / c][i % c] = mat[i / matColSize[0]][i % matColSize[0]];
    }

    return result;
}
