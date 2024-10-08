#include "get_next_line.h"

 int	main(int argc, char *argv[])
{
	//clock_t tic = clock();
	char *buffer;

	// Leer desde archivo si se proporciona un argumento en la línea de comandos
	if (argc == 2)
	{
		// Abrir el archivo para lectura
		int	fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		// Llamar a la función para leer el contenido del archivo
		while ((buffer = get_next_line(fd)) != NULL)
		{
			// Verificar si se asignó memoria correctamente
			if (buffer == NULL)
			{
				fprintf(stderr, "Fallo al asignar memoria para el buffer\n");
				break;
			}

			// Procesar la línea leída
			printf("RECIBIDO: %s", buffer);

			// Liberar la memoria asignada a la línea
			free(buffer);
		}

		// Cerrar el descriptor de archivo
		if (close(fd) == -1)
		{
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
	// Leer desde stdin si no se proporcionzan argumentos en la línea de comandos
	else if (argc == 1)
	{
		printf("Ingrese texto desde stdin:\n");
		while ((buffer = get_next_line(STDIN_FILENO)) != NULL)
		{
			// Verificar si se asignó memoria correctamente
			if (buffer == NULL)
			{
				fprintf(stderr, "Fallo al asignar memoria para el buffer\n");
				break;
			}

			// Procesar la línea leída
			printf("RECIBIDO: %s", buffer);

			// Liberar la memoria asignada a la línea
			free(buffer);
		}
	}
	else
	{
		fprintf(stderr, "Uso: %s [nombre_del_archivo]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//clock_t toc = clock();

	//printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
} 
