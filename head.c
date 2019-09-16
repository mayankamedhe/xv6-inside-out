#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
head(int fd, int lines, char* name)
{
  //int n;
  int i=0;
  // char* output = "--";
  // write(1, output, sizeof(output));
  //printf("--%s--\n", name);
  while(i < lines)
  {
    //int n = 
    read(fd, buf, 1);
    write(1, buf, 1);
    if(*buf == '\n')
    {
      i++;
    }
    
    // if ( != n) 
    // {
    //   printf(1, "head: write error\n");
    //   exit();
    // }


    // if(n < 0)
    // {
    // printf(1, "head: read error\n");
    // exit();
    // }

  }
  // while(((n = read(fd, buf, sizeof(buf))) > 0) && i < lines){
  //   if (write(1, buf, n) != n) {
  //     printf(1, "head: write error\n");
  //     exit();
  //   }
  //   if(*buf == '\n')
  //   {
  //     i++;
  //   }
  //   // else
  //   // {
  //   //   printf(1,"CHECK!!!!!!!!!!\n");
  //   //   lines--;
  //   // }
    
  // }
  // if(n < 0){
  //   printf(1, "head: read error\n");
  //   exit();
  // }
}

int
main(int argc, char *argv[])
{
  int fd, i;
  int lines = atoi(argv[1]);
  if(argc <= 1){
    head(0, lines, "0");
    exit();
  }

  for(i = 2; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "head: cannot open %s\n", argv[i]);
      exit();
    }
    printf(1,"--%s--\n", argv[i]);
    head(fd, lines, argv[i]);
    close(fd);
  }
  exit();
}




// #include "types.h"
// #include "stat.h"
// #include "user.h"

// char buf[512];

// void
// cat(int fd)
// {
//   int n;

//   while((n = read(fd, buf, sizeof(buf))) > 0) {
//     if (write(1, buf, n) != n) {
//       printf(1, "cat: write error\n");
//       exit();
//     }
//   }
//   if(n < 0){
//     printf(1, "cat: read error\n");
//     exit();
//   }
// }

// int
// main(int argc, char *argv[])
// {
//   int fd, i;

//   if(argc <= 1){
//     cat(0);
//     exit();
//   }

//   for(i = 1; i < argc; i++){
//     if((fd = open(argv[i], 0)) < 0){
//       printf(1, "cat: cannot open %s\n", argv[i]);
//       exit();
//     }
//     cat(fd);
//     close(fd);
//   }
//   exit();
// }
