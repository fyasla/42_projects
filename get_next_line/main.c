int        main(int argc, char **argv)
{
    int fd;
    int nbfile;
    int    i;
    char *line;
    int    retgnl;
    i = 1;
    if (argc == 1)
        fd = 1;
    else if (argc > 1)
    {
        nbfile = argc;
        while (i != nbfile)
        {
            fd = open(argv[i],O_RDONLY);
            printf("\n\n%s %d %s %s\n\n", "file descriptor", i, ":", argv[i]);
            while ((retgnl = get_next_line(fd, &line)) > 0)
                printf("%d\t%s\n", retgnl, line);
            close(fd);
            i++;
        }
    }
    return (0);
}