# error on success(encounters exit) can be turned off

## it is mlx lib prob

how to supress?

create one file (mlx.supp in the minilibx-linux)

# vim mlx.upp
{
   MLX_X11_Uninit_Write
   Memcheck:Param
   writev(vector[0])
   fun:writev
   obj:/usr/lib/aarch64-linux-gnu/libxcb.so.1.1.0
   obj:/usr/lib/aarch64-linux-gnu/libxcb.so.1.1.0
   fun:xcb_writev
   fun:_XSend
   fun:_XReadEvents
   fun:XWindowEvent
   fun:mlx_int_wait_first_expose
   fun:mlx_new_window
}

## on compilation
valgrind --suppressions=mlx.supp ./so_long maps/valid_map1.ber