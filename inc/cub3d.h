#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	int				number_of_philosophers;
	int				dead_flag;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	extreme_mutex;
	int				extreme_turn;
	pthread_mutex_t	dead_mutex;
}	t_data;

long	ft_atol(const char *nptr);
int		ft_isdigit(int argc, char **argv);
int		ft_isvalid(int argc, char **argv);
int		ft_parse(int argc, char **argv);
int		ft_init(int argc, char **argv, t_data *data);
long	ft_get_time(void);
void	ft_usleep(int ms);
void	ft_print_status(t_philo *philo, char *status, t_data *data);
int		ft_check_death(t_data *data);
void	ft_eat(t_philo *philo, t_data *data);
void	*ft_philosopher_routine(void *arg);
int		ft_start_simulation(t_data *data);
void	ft_cleanup(t_data *data);
int		ft_is_extreme_case(t_data *data);
void	*ft_extreme_philosopher_routine(void *arg);
int		ft_extreme_eat(t_philo *philo, t_data *data);
int		ft_check_meals_completed(t_data *data);
int		ft_check_philosopher_death(t_data *data);
void	ft_monitor_death(t_data *data);*/

#endif
