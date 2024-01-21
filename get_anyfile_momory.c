#include <stdio.h>

long getFileSize(FILE *file) {
    long size;

    // 保存当前文件位置
    long currentPos = ftell(file);

    // 将文件指针移动到文件的末尾
    fseek(file, 0, SEEK_END);

    // 获取当前文件位置（即文件大小）
    size = ftell(file);

    // 将文件指针恢复到之前的位置
    fseek(file, currentPos, SEEK_SET);

    return size;
}

int main() {
    FILE *file = fopen("testtest", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
    } else {
        long size = getFileSize(file);
        printf("文件大小为 %ld 字节\n", size);
        fclose(file);
    }

    return 0;
}

