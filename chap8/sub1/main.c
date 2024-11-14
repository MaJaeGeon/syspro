#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    int opt;
    char *e_arg = NULL;

    while ((opt = getopt(argc, argv, "e::ugip")) != -1) {
        switch (opt) {
            case 'e':
                if (optind < argc && argv[optind][0] != '-')  {
                    e_arg = argv[optind++];

                    char* ptr = getenv(e_arg);
                    printf("%s = %s\n", e_arg, ptr);
                } else {
                    char **ptr;
                    extern char **environ;

                    for(ptr = environ; *ptr != 0; ptr++) printf("%s \n", *ptr);
                }
                break;
            case 'u':
                printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid()) -> pw_name);
                printf("My Valid User ID : %d(%s) \n", geteuid(), getpwuid(geteuid()) -> pw_name);
                break;
            case 'g':
                printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid()) -> gr_name);
                printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid()) -> gr_name);
                break;
            case 'i':
                printf("my process number : [%d]\n", getpid());
                break;
            case 'p':
                printf("my parent's process number : [%d]\n", getppid());
                break;
			case ':':
				printf("error");
				break;
        }
    }

    return 0;
}

