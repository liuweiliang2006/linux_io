#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
int main(int argc, char **argv)
{
    FILE *fps,*fpd;
    char  buf[BUFSIZE];
    int n=0;

    if(argc<3)
    {
        fprintf(stderr,"usage:%s<source_file> <des_file>",argv[0]);
    }
    fps=fopen(argv[1],"r");
    if(fps == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    

    fpd=fopen(argv[2],"w");
    
    if(fpd == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }
    while((n= fread(buf,1,BUFSIZE,fps))>0)
       fwrite(buf,1,n,fpd);
    
    fclose(fps);
    fclose(fpd);
    exit(0);
}
