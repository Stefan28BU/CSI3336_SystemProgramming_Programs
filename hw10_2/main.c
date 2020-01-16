/**************************************************************************
 * file:               hw10_2.c
 * author:             Yufan Xu
 * assignment:         homework 10_2
 * description:        this program demonstrates a simple command interface
 * date created:       11/1/2018
 * date last modified: 11/1/2018
 * date due:           11/1/2018
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>

int main(int argc, char **argv)
{
    pid_t pid;
    char cmd[100], *env;
    int i, flag;

    struct utsname utn;
    struct passwd *info;
    flag = 1;

    while (flag == 1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "uinfo") == 0 ) {
            pid = fork();

            if (pid == 0) {
                scanf("%s", cmd);
                info = getpwnam(cmd);
                printf("%s\n", info->pw_name);
                printf("real name: %s\n", info->pw_gecos);
                printf("user id: %d\n", info->pw_uid);
                printf("group id: %d\n", info->pw_gid);
            }
            else if (pid > 0 ) {
                wait(NULL);
            }
        }
        else if (cmd[0] == '$') {
            pid = fork();
            if (pid == 0) {
                i = 1;
                while (cmd[i] != '\0') {
                    cmd[i-1] = cmd[i];
                    i++;
                }
                cmd[i-1] = '\0';
                env = getenv(cmd);
                printf("%s\n", env);
            }
            else if (pid > 0) {
                wait(NULL);
            }
        }
        else if (strcmp(cmd, "sysinfo") == 0) {
            pid = fork();
            if (pid == 0) {
                uname(&utn);
                printf("%s\n", utn.nodename);
                printf("%s\n", utn.sysname);
                printf("%s\n", utn.release);
            }
            else if (pid > 0) {
                wait(NULL);
            }
        }
        else if (strcmp(cmd, "quit") == 0) {
            flag = 0;
        }
    }

    return 0;
}
