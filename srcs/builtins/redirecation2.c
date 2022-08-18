#include "../../includes/minishell.h"

void *init_list(int fd_num, int fd_copy)
{
    t_redir_list *redir_lst;

    redir_lst = (t_redir_list *)malloc(sizeof(t_redir_list));
    if(!redir_lst)
        return(NULL);
    redir_lst->fd_num = fd_num;
    redir_lst->str_dup = fd_copy;
    return(ft_lstnew(redir_lst));
}
int redir_lste(t_list *new_list, t_list **redir_lst, int fd_num)
{
    int temp;

    temp = dup(fd_num);
    if(temp == -1 && errno != EBADF)
    {
        printf("error\n");
        return(-1);
    }
    else
    {
        new_list = init_list(fd_num, temp);
        if (!new_list)
        {
            printf("error\n");
            return(-1);
        }
        ft_lstadd_back(redir_lst, new_list);
    }
    return (0);
}
int file_dup(t_redir_list *test, int dup_npr)
{
    dup_npr = dup2(test->str_dup, test->fd_num);
    if(dup_npr == -1)
    {
        printf("error\n");
        return(-1);
    }
    close (test->str_dup);
    return (0);
}

int read_fd_check(t_list **redir_lst, int fd_num)
{
    t_redir_list *test = NULL;
    int dup_nbr;
    t_list *new_list = NULL;

    dup_nbr = 0;
    while(!(*redir_lst))
    {
        printf("sss :%d\n", test->str_dup);
        test = (*redir_lst)->content;
        if (test->fd_num == fd_num)
        {
            printf("test\n");
            return (0);
        }
        if(test->str_dup == 1)
        {
            printf("it is\n");
            file_dup(test, dup_nbr);
        }
        if (test->str_dup == -1)
            close(test->fd_num);
        (*redir_lst) = (*redir_lst)->next;
    }
    if (redir_lste(new_list, redir_lst, fd_num) == -1)
        return(-1);
    return (0);
}