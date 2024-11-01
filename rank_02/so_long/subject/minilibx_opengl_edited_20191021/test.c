#include <stdlib.h> // For EXIT_FAILURE
#define GL_SILENCE_DEPRECATION
#include "mlx.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "mlx_opengl.h"

void render(void *mlx_ptr, void *win_ptr) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex2f(0.0, 0.5);
    glEnd();
    mlx_opengl_swap_buffers(win_ptr); // Swap buffers
}

int main() {
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx) {
        return (EXIT_FAILURE); // Handle initialization failure
    }

    win = mlx_new_opengl_window(mlx, 800, 600, "MiniLibX OpenGL Test");
    if (!win) {
        return (EXIT_FAILURE); // Handle window creation failure
    }

    // Set up OpenGL
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    // Main loop
    while (1) {
        render(mlx, win); // Render the scene
        mlx_loop(mlx);    // Process events
    }

    return (0); // Successful execution
}

