#include "minirt.h"

t_vec vec3(float x, float y, float z)
{
	t_vec v = {x, y, z};
	return (v);
}

float get(t_mat m, int i, int j)
{
	if (j == 0) 
		return (m.v[i].x);
	if (j == 1) return m.v[i].y;
	return (m.v[i].z);
}

void set(t_mat *m, int i, int j, float val)
{
	if (j == 0) 
		m->v[i].x = val;
	else if (j == 1) 
		m->v[i].y = val;
	else 
		m->v[i].z = val;
}

void normalize(t_vec *p )
{
    float w = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
	if (w != 0)
	{
		p->x /= w;
		p->y /= w;
		p->z /= w;
	}
}

float determinant(t_mat a, int n)
{
	if (n == 1)
		return (get(a, 0, 0));
	float det = 0;
	int sign = 1;
	for (int c = 0; c < n; c++)
	{
		t_mat sub;
		int subi = 0;
		for (int i = 1; i < n; i++)
		{
			int subj = 0;
			for (int j = 0; j < n; j++)
			{
				if (j == c)
					continue;
				set(&sub, subi, subj, get(a, i, j));
				subj++;
			}
			subi++;
		}
		det += sign * get(a, 0, c) * determinant(sub, n - 1);
		sign = -sign;
	}
	return (det);
}


void cofactor(t_mat a, t_mat *cofac, int n)
{
	for (int q = 0; q < n; q++)
	{
		for (int p = 0; p < n; p++)
		{
			t_mat sub;
			int subi = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == q)
					continue;
				int subj = 0;
				for (int j = 0; j < n; j++)
				{
					if (j == p)
						continue;
					set(&sub, subi, subj, get(a, i, j));
					subj++;
				}
				subi++;
			}
			set(cofac, q, p, powf(-1, q + p) * determinant(sub, n - 1));
		}
	}
}

void transpose(t_mat a, t_mat *at, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			set(at, j, i, get(a, i, j));
}

int inverse(t_mat a, t_mat *inv, int n)
{
	float det = determinant(a, n);
	if (det == 0)
	{
		ft_printf("La matrice n’est pas inversible (det = 0)\n");
		return (0);
	}
	t_mat cofac, cofac_T;
	cofactor(a, &cofac, n);
	transpose(cofac, &cofac_T, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			set(inv, i, j, get(cofac_T, i, j) / det);
	return (1);
}

t_ray	ray_for_pixel(t_camera camera, float px, float py)
{
	float xoffset = (px + 0.5f) * camera.pixel_size;
	float yoffset = (py + 0.5f) * camera.pixel_size;
	float world_x = camera.half_width - xoffset;
	float world_y = camera.half_height - yoffset;
	t_vec pixel_camera = vec3(world_x, world_y, -1);
	// float inv[3][3];
	t_mat inv;
	inverse(camera.transform, &inv, 3);
	t_vec pixel_world = mat_mul_vec(inv, pixel_camera);
	t_vec origin_world = mat_mul_vec(inv, vec3(0, 0, 0));
	t_vec dir = vec_sub(pixel_world, origin_world);
	normalize(&dir);
	t_ray ray;
	ray.origin = origin_world;
	ray.dir = dir;
	return (ray);
}

void	construct_camera(t_camera *camera)
{
	camera->hsize = 201;
	camera->vsize = 101;
	camera->transform = (t_mat){(t_vec){1, 0, 0}, (t_vec){0, 1, 0}, (t_vec){0, 0, 1}}; 
	// camera.transform = identity_matrix;
	//camera.pixel_size = 0.01;
	camera->aspect = camera->hsize / camera->vsize;
	camera->half_view = tanf((float)(camera->fov / 2));
	if (camera->aspect >= 1)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / camera->aspect;
	}
	else if (camera->aspect < 1)
	{
		camera->half_height = camera->half_view ;
		camera->half_width = camera->half_view * camera->aspect;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}

int	false_main(void)
{
	t_camera camera;
	camera.fov = FT_PI / 2;
	construct_camera(&camera);
//	ft_printf("fov: %f\nhalf_view: %f\naspect: %d\nheight: %f\nwidth: %f\npixel_size: %f\n", camera.fov, camera.half_view, camera.aspect, camera.half_height * 2, camera.half_width * 2, camera.pixel_size);
	return (0);
}
