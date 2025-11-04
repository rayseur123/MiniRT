#ifndef MINIRT_KEYHOOK_C_H
#define MINIRT_KEYHOOK_C_H

void	escape(int key_code, t_canvas *c);
int	actions_hook(int key_code, t_canvas *c);
int	hook_close(void *mlx);

#endif //MINIRT_KEYHOOK_C_H