#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

  pid_t pid;
  int rv;
  int child;
  int parent;
  int group_sid;
  int status_child;

void parents_child()
{
  
  switch(pid=fork()) 
  {
  case -1:
          perror("fork"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  case 0:
          printf(" CHILD: Это процесс-потомок!\n");
          printf(" CHILD: Мой PID -- %d\n", getpid());
          child = getppid();
          parent = getppid();
          printf("CHILD: Группа %d\n",setsid());
          printf("CHILD: Мой pid  %d\n",pid);
          printf(" CHILD: PID моего родителя -- %d\n",getppid());
          printf(" CHILD: Выход!\n");
          //exit(rv);


          

           
  default:
          printf("rv  %i\n",rv);
          printf("\n PARENT: Это процесс-родитель!\n");
          printf("PARENT: Мой PID %d\n", getpid());
         
          printf("PARENT: PID моего потомка %d\n",pid);
          printf("PARENT: Группа %d\n",setsid());
          group_sid = setsid();
          printf("PARENT: Я жду, пока потомок не вызовет exit()...\n");
          printf("PARENT: Код возврата потомка:%d\n",WEXITSTATUS(pid));
          printf("PARENT: Выход!\n");    
      
status_child = WIFEXITED(0);
if (status_child == 1)
{
 printf("Потомок успешно завершился\n");
}
  }
}


int main ()
{
    parents_child();


  return 0;

}
