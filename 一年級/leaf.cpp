#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

// 定義仿射變換矩陣和偏移向量
// 在使用結構體時可以只打Transformation，使代碼便簡潔及當需要修改時只需更動這裡即可
typedef struct {
    double matrix[2][2]; //2x2矩陣，用於仿射變換
    double offset[2]; //偏移向量，用於平移變換
    double probability;
} Transformation;

// 定義葉子的仿射變換和概率
Transformation transformations[] = { //在初始化時即給出所有元素，故可省略中括號中的大小
    { { {0.85, 0.04}, {-0.04, 0.85} }, {0, 1.6}, 0.85 },
    { { {0.2, -0.26}, {0.23, 0.22} }, {0, 1.6}, 0.07 },
    { { {-0.15, 0.28}, {0.26, 0.24} }, {0, 0.44}, 0.07 },
    { { {0, 0}, {0, 0.16} }, {0, 0}, 0.01 }
};

//affine transformation(仿射變換函數)
void affine_transform(double* point, Transformation* t) {
    double x_new = t->matrix[0][0] * point[0] + t->matrix[0][1] * point[1] + t->offset[0];
    double y_new = t->matrix[1][0] * point[0] + t->matrix[1][1] * point[1] + t->offset[1];
    point[0] = x_new;
    point[1] = y_new;
}

//選擇變換函數
int choose_transformation() {
    double r = (double)rand() / RAND_MAX;
    double cumulative_probability = 0.0;
    for (int i = 0; i < 4; i++) {
        cumulative_probability += transformations[i].probability;
        if (r <= cumulative_probability) {
            return i;
        }
    }
    return 0;
}

//生成葉子函數
void generate_leaf(int width, int height, int iterations, const char* filename) { //iterations: 迭代次數
    // 初始化圖像數組
    unsigned char* image = (unsigned char*)calloc(width * height, sizeof(unsigned char));
    //calloc: 將分配的內存初始化為零

    // 初始點
    double point[2] = { 0, 0 };

    // 生成點並繪製到圖像中
    for (int i = 0; i < iterations; i++) {
        int t_index = choose_transformation();
        affine_transform(point, &transformations[t_index]);

        // 將點映射到圖像座標系
        int x = (int)((point[0] + 3) / 6 * width);
        int y = (int)((point[1]) / 10 * height);
        if (x >= 0 && x < width && y >= 0 && y < height) {
            image[y * width + x] = 255; // 設置點為白色
        }
    }

    // 將圖像數組保存為PPM文件(PPM為用二進制方式儲存圖像數據，格式簡單，易於解析與生成)
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // 釋放內存
    free(image);
}

int main() {
    // 設置圖像大小和迭代次數
    int width = 800;
    int height = 1000;
    int iterations = 1000000;  //迭代次數

    // 設置隨機數種子
    srand((unsigned int)time(NULL)); //要include <time.h>

    // 生成葉子並保存為文件
    generate_leaf(width, height, iterations, "leaf.ppm");

    return 0;
}