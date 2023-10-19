#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"usage: path1 [path2 ...]\n");
        return 1;
    }

    // iterate through the CLI arguments (file paths given)
    for (int i = 1; i < argc; i++) {
        char *file_path = argv[i];
        struct stat file_info;

        // stat displays file or file system status
        if (stat(file_path, &file_info) == 0) {
            if (S_ISREG(file_info.st_mode)) {
                printf("%s: regular file\n", file_path);
            } else if (S_ISDIR(file_info.st_mode)) {
                printf("%s: directory\n", file_path);
            } else if (S_ISLNK(file_info.st_mode)) {
                printf("%s: symbolic link\n", file_path);
            } else if (S_ISCHR(file_info.st_mode)) {
                printf("%s: character special file\n", file_path);
            } else if (S_ISBLK(file_info.st_mode)) {
                printf("%s: block special file\n", file_path);
            } else if (S_ISFIFO(file_info.st_mode)) {
                printf("%s: FIFO/pipe\n", file_path);
            } else if (S_ISSOCK(file_info.st_mode)) {
                printf("%s: socket\n", file_path);
            }
        } else {
            fprintf(stderr, "%s: path error\n", file_path);
        }
    }

    return 0;
}