#include "ftsh.h"

void 	sh_jcp_put(void *cont)
{
	t_process *proc;

	proc = (t_process*)cont;
	ft_printf("\tPID: %d\n", proc->pid);
}

int 	sh_jcj_print(t_job *job)
{
	ft_printf("Job pgid: [%d] %d\n", job->ind, job->pgid);
	ft_printf("job is back: %d\n", job->bg);
	ft_printf("Processes:\n");
	ft_lstiter(job->process, &sh_jcp_lstput);
	return (OK);
}