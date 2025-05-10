#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 4096);
    char *ptr = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    memcpy(ptr, "Hello, Shared Memory!", 21);
    close(shm_fd);
    return 0;
}



#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int shm_fd = shm_open("/myshm", O_RDONLY, 0666);
    char *ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("%s\n", ptr);
    close(shm_fd);
    return 0;
}

