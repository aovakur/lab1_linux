#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

  pid_t pid;
  int rv;
  int child_pid;
  int parent;
  int group_sid;
  int status_child;
  int status_parents;
  int parents_pid;

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
          child_pid = getpid();
          printf("CHILD: Группа %d\n",setsid());
          printf("CHILD: Мой pid  %d\n",pid);
          printf(" CHILD: PID моего родителя -- %d\n",getppid());
          printf(" CHILD: Выход!\n");
          
           
  default:
          printf("rv  %i\n",rv);
          printf("\n PARENT: Это процесс-родитель!\n");
          printf("PARENT: Мой PID %d\n", getpid());
          parents_pid=getpid();
          printf("PARENT: PID моего потомка %d\n",pid);
          printf("PARENT: Группа %d\n",setsid());
          group_sid = setsid();
       
  }
}


int main ()
{

    parents_child();
  
  status_parents = WIFEXITED(parents_pid); 
   printf("родитель %d ",status_parents);
   status_parents = WIFEXITED(child_pid);
   printf("потомок %d ",status_child);
 //   printf("Потомок успешно завершился\n");



  return 0;

}
