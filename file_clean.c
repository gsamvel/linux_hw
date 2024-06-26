#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    const char *filename = argv[1];

    int fd = open(filename, O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        exit(EXIT_FAILURE);
    }

    off_t fileSize = st.st_size;
    off_t bytesWritten = 0;
    while (bytesWritten < fileSize) {
        ssize_t written = write(fd, "\0", 1);
        if (written == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        bytesWritten += written;
    }

    close(fd);
    return 0;
}


