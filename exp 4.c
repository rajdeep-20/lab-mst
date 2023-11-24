#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h> // Include this for file-related functions
#include <time.h>
#include <unistd.h> // Include this for close() and read() functions.

int main(int argc, char *argv[]) // Correct the function signature
{
    char buf[100]; // Correct the variable declaration
    struct stat s;
    int fd1, fd2, n;

    if (argc != 3) // Check if the correct number of arguments is provided
    {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY); // Use O_RDONLY for reading
    if (fd1 == -1)
    {
        perror("Error opening source file");
        return 1;
    }

    fd2 = creat(argv[2], 0777); // Use creat to create a new file
    if (fd2 == -1)
    {
        perror("Error creating destination file");
        close(fd1); // Close the source file before exiting
        return 1;
    }

    while ((n = read(fd1, buf, sizeof(buf))) > 0)
    {
        if (write(fd2, buf, n) != n)
        {
            perror("Error writing to destination file");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    close(fd1);
    close(fd2);

    // Retrieve and print file information
    if (stat(argv[2], &s) == -1)
    {
        perror("Error getting file information");
        return 1;
    }

    printf("UID FOR FILE.......> %d\n", s.st_uid);
    printf("FILE ACCESS TIME....> %s", ctime(&s.st_atime));
    printf("FILE MODIFIED TIME..> %s", ctime(&s.st_mtime));
    printf("FILE I-NODE NUMBER..> %ld\n", (long)s.st_ino);
    printf("PERMISSION FOR FILE.> %o\n", s.st_mode);

    return 0;
}