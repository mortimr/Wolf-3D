/*
** wolf.h for wolf in /home/rotaru_i/Coding/LibLap/gfx_wolf3d/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Dec 22 16:17:53 2015 Iulian Rotaru
** Last update Sun Dec 27 20:35:39 2015 Iulian Rotaru
*/

#ifndef WOLF_H_
# define WOLF_H_

typedef struct		s_wolf
{
  t_bunny_pixelarray	*minimap;
  t_bunny_pixelarray	*background;
  t_bunny_pixelarray	*walls;
  t_bunny_pixelarray	*rendu;
  t_bunny_pixelarray	*weapon;
  t_bunny_pixelarray	*no_light;
  t_bunny_window	*win;
  int			tile_size;
  int			x_pos;
  int			y_pos;
  int			*the_keys;
  double		x;
  double		y;
  int			(*op[7])(struct s_wolf*);
  double		angle;
  int			map_height;
  int			map_width;
  int			**tab;
  const bool		*keys;
  t_bunny_music		*music;
  t_bunny_music		*fire;
  t_bunny_effect	*lighting;
  int			music_volume;
  int			snow_move;
  int			left_click;
}			t_wolf;

void			set_max_heap_size(size_t);
double			vecnorm(t_bunny_position*,
				t_bunny_position*);
int			escape_key(t_wolf *wolf);
int			w_key(t_wolf *wolf);
int			a_key(t_wolf *wolf);
int			s_key(t_wolf *wolf);
int			d_key(t_wolf *wolf);
int			space_key(t_wolf *wolf);
t_bunny_response	mouse_move(const t_bunny_position *relative,
				   void *data);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data);
void			background_manager(t_wolf *data);
double			make_radius(double initial);
int			main_condition(double x,
				       double y,
				       t_wolf *wolf);
double			increm_radius(double radius,
				      double *x,
				      double *y);
int			texture_condi(t_wolf *wolf,
				      double x,
				      double y);
void			walls_textures(t_wolf *wolf,
				       double x,
				       double y,
				       int i);
void			walls_manager(t_wolf *wolf);
void			viseur_maker(t_wolf *wolf);
void			add_pix_pos(t_wolf *wolf,
				    t_bunny_pixelarray *pix,
				    t_bunny_position *blit);
double			left_ray(t_wolf *wolf, double radius);
double			right_ray(double radius);
void			angle_minimap(t_wolf *wolf);
void			music_manager(t_wolf *wolf);
int			keys_manager(t_wolf *wolf);
t_bunny_response	loop(void *data);
void			make_first_snow(t_bunny_pixelarray *pix);
int			get_text_data(t_bunny_ini *ini,
				      int height ,
				      int width,
				      unsigned int *ptr);
t_bunny_pixelarray	*get_ini_png(char *name,
				     t_bunny_pixelarray *pix);
int			*get_keys_tab();
void			get_op(t_wolf *wolf);
void			make_bg(t_bunny_pixelarray *pix);
void			*make_square(int x,
				     int y,
				     t_color color,
				     t_wolf *data);
void			add_pix(t_wolf *wolf,
				t_bunny_pixelarray *pix);
void			aff_tab(t_wolf *wolf);
void			initialise_color(t_color *color);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void			tmpline(t_bunny_position *coord,
				double *x,
				double *y,
				double *len);
void			norm_is_amazing(t_bunny_position *pos,
					double *x,
					double *y);
int			my_getnbr(const char *nb);
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *coord,
				t_color *color);
int			minimap_manager(t_wolf *wolf);
void			tekline_one(t_bunny_pixelarray *pix,
				    t_bunny_position *coord,
				    t_wolf *wolf);
void			tekline_three(t_bunny_pixelarray *pix,
				      t_bunny_position *coord,
				      t_wolf *wolf);
void			tekline_two(t_bunny_pixelarray *pix,
				    t_bunny_position *coord,
				    t_wolf *wolf);
void			snow_it(t_bunny_pixelarray *pix,
				int snow_move);
int			failed_reading(char *name,
				       char *scope,
				       char *field,
				       int index);
int			get_char_angle(char **argv,
				       t_wolf *data,
				       t_bunny_ini *ini);
int			alloc_fail();
int			my_strlen(const char *str);
int			argc_error();
int			no_such_file(char *name);
int			big_alloc(t_wolf *data);
int			small_alloc(t_wolf *data,
				    int col);
int			alloc_while(char **argv,
				    t_wolf *data,
				    t_bunny_ini *ini,
				    int *n);
int			alloc_size(char **argv,
				   t_wolf *data,
				   t_bunny_ini *ini);
int			get_tile_size(char **argv,
				      t_wolf *data,
				      t_bunny_ini *ini);
int			check_read(t_bunny_ini *ini,
				   char **argv,
				   int extractor);
int			read_file(int argc,
				  char **argv,
				  t_wolf *data);
void			go(t_bunny_position *curpos,
			   double angle,
			   t_bunny_position *newpos,
			   int move);

#endif /* !WOLF_H_ */
