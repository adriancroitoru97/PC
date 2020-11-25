//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#include <stdlib.h>

int *init_array(int n);
int **init_matrix(int n, int *v);
char **init_matrix_char(int n, int *v, int **mat);
char **init_matrix_char_2(int n, int *v, char **mat_char);
void free_memory(int n, int *v, int **mat, char **mat_char, char **mat_char_2);

double arithmetic_average(int n, int *v, int **mat);

void task2(int *v, char **mat_char);
void task2_delete(int *v, char **mat_char, int dimension, int line, int index);
void task2_swap(int *v, char **mat_char, int dimension, int line, int index);
void task2_modify(int *v, char **mat_char,
				  int dimension, int line, int index, int new_value);
void print_matrix_char(int n, int *v, char **mat_char);

void task3(int n, int *v, char **mat_char_2,
		   int *line_bh, int *col_bh, int *max_bh);
int task3_search(int n, int *v, char **mat_char_2, int line_bh, int col_bh);

int main(void)
{
	// n - numarul de linii, v - numarul de coloane de pe fiecare linie
	// mat - matricea citita, in format hex
	// mat_char - mat transpus la char -> cate 1 byte pe fiecare pozitie * 4 poz
	// mat_char_2 - bytes din fiecare numar sunt inversati (endianness)
	int n, *v = NULL;
	int **mat = NULL;
	char **mat_char = NULL, **mat_char_2 = NULL;

	scanf("%d", &n);
	v = init_array(n);
	mat = init_matrix(n, v);
	mat_char = init_matrix_char(n, v, mat);

	printf("task 1\n");
	printf("%.8lf\n", arithmetic_average(n, v, mat));

	printf("task 2\n");
	task2(v, mat_char);
	print_matrix_char(n, v, mat_char);

	printf("task 3\n");
	mat_char_2 = init_matrix_char_2(n, v, mat_char);
	int line_bh, col_bh, max_bh = -1; // bh - black hole
	task3(n, v, mat_char_2, &line_bh, &col_bh, &max_bh);
	printf("%d %d %d\n", line_bh, col_bh, max_bh);

	free_memory(n, v, mat, mat_char, mat_char_2);

	return 0;
}

int *init_array(int n)
{
	int *v = NULL;
	v = (int *)malloc(n * sizeof(int));
	if (!v) {
		free(v);
		exit(1);
	}

	return v;
}

int **init_matrix(int n, int *v)
{
	int **mat = NULL;
	mat = (int **)malloc(n * sizeof(int *));
	if (!mat) {
		free(mat);
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		mat[i] = (int *)malloc(v[i] * sizeof(int));
		if (!mat[i]) {
			free(mat[i]);
			exit(1);
		}

		for (int j = 0; j < v[i]; j++)
			scanf("%X", &mat[i][j]);
	}

	return mat;
}

char **init_matrix_char(int n, int *v, int **mat)
{
	char **mat_char = NULL;
	mat_char = (char **)malloc(n * sizeof(char *));
	if (!mat_char) {
		free(mat_char);
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		mat_char[i] = (char *)malloc(v[i] * 4 * sizeof(char));
		if (!mat_char[i]) {
			free(mat_char[i]);
			exit(1);
		}

		for (int j = 0; j < 4 * v[i]; j = j + 4) {
			for (int k = 0; k < 4; k++) {
				char temp = (mat[i][j / 4] >> (((3 - k) * 8))) & 0xFF;
				mat_char[i][j + k] = temp;
			}
		}
	}

	return mat_char;
}

char **init_matrix_char_2(int n, int *v, char **mat_char)
{
	char **mat_char_2 = NULL;
	mat_char_2 = (char **)malloc(n * sizeof(char *));
	if (!mat_char_2) {
		free(mat_char_2);
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		mat_char_2[i] = (char *)malloc(v[i] * 4 * sizeof(char));
		if (!mat_char_2[i]) {
			free(mat_char_2[i]);
			exit(1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4 * v[i]; j = j + 4) {
			int nr = 3;
			char temp[4];
			temp[0] = mat_char[i][j];
			temp[1] = mat_char[i][j + 1];
			temp[2] = mat_char[i][j + 2];
			temp[3] = mat_char[i][j + 3];

			for (int k = 0; k < 4; k++)
				mat_char_2[i][j + k] = temp[nr--];
		}
	}

	return mat_char_2;
}

double arithmetic_average(int n, int *v, int **mat)
{
	int bytes[4];
	int nr_bytes = 0;
	double s_bytes = 0;
	int x; // x - se foloseste pt depozitarea temporara a unui anumit byte

	for (int i = 0; i < v[0]; i++) {
		x = mat[0][i];
		nr_bytes += 4;
		bytes[0] = x & 0xFF;
		bytes[1] = (x >> 8) & 0xFF;
		bytes[2] = (x >> 16) & 0xFF;
		bytes[3] = (x >> 24) & 0xFF;

		for (int j = 0; j < 4; j++)
			if (bytes[j] < 0x80)
				s_bytes += bytes[j];
			else if (bytes[j] >= 0x80 && bytes[j] <= 0xFF)
				s_bytes = s_bytes + (bytes[j] - 0xFF - 0x01);
	}

	for (int i = 1; i < n - 1; i++) {
		x = mat[i][v[i] - 1];
		nr_bytes++;
		bytes[3] = (x >> 24) & 0xFF;

		if (bytes[3] < 0x80)
			s_bytes += bytes[3];
		else if (bytes[3] >= 0x80 && bytes[3] <= 0xFF)
			s_bytes = s_bytes + (bytes[3] - 0xFF - 0x01);
	}

	for (int i = 0; i < v[n - 1]; i++) {
		x = mat[n - 1][i];
		nr_bytes += 4;
		bytes[0] = x & 0xFF;
		bytes[1] = (x >> 8) & 0xFF;
		bytes[2] = (x >> 16) & 0xFF;
		bytes[3] = (x >> 24) & 0xFF;

		for (int j = 0; j < 4; j++)
			if (bytes[j] < 0x80)
				s_bytes += bytes[j];
			else if (bytes[j] >= 0x80 && bytes[j] <= 0xFF)
				s_bytes = s_bytes + (bytes[j] - 0xFF - 0x01);
	}

	for (int i = 1; i < n - 1; i++) {
		x = mat[i][0];
		nr_bytes++;
		bytes[0] = x & 0xFF;

		if (bytes[0] < 0x80)
			s_bytes += bytes[0];
		else if (bytes[0] >= 0x80 && bytes[0] <= 0xFF)
			s_bytes = s_bytes + (bytes[0] - 0xFF - 0x01);
	}

	return (double)s_bytes / nr_bytes;
}

void task2(int *v, char **mat_char)
{
	int k;
	char dimension, action;
	int line, index_data, new_value;

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf(" %c %c", &action, &dimension);
		scanf("%d %d", &line, &index_data);

		if (action == 'M') {
			scanf("%X", &new_value);
			if (dimension == 'C')
				task2_modify(v, mat_char, 1, line, index_data, new_value);
			else if (dimension == 'S')
				task2_modify(v, mat_char, 2, line, index_data, new_value);
			else if (dimension == 'I')
				task2_modify(v, mat_char, 4, line, index_data, new_value);
		} else if (action == 'D') {
			if (dimension == 'C')
				task2_delete(v, mat_char, 1, line, index_data);
			else if (dimension == 'S')
				task2_delete(v, mat_char, 2, line, index_data);
			else if (dimension == 'I')
				task2_delete(v, mat_char, 4, line, index_data);
		} else if (action == 'S') {
			if (dimension == 'C')
				task2_swap(v, mat_char, 1, line, index_data);
			else if (dimension == 'S')
				task2_swap(v, mat_char, 2, line, index_data);
			else if (dimension == 'I')
				task2_swap(v, mat_char, 4, line, index_data);
		}
	}
}

void task2_delete(int *v, char **mat_char, int dimension, int line, int index)
{
	int sub_index = 0; //numara bytes pana se obtine dimensiunea unui bloc
	int index_cnt = 0; //contorizeaza numarul de blocuri
	int ver = 0; //opreste algoritmul cand operatia s-a incheiat

	for (int j = 3; j <= v[line] * 4; j = j + 4) {
		for (int k = j; k > j - 4; k--) {
			sub_index++;
			if (sub_index == dimension) {
				index_cnt++;
				sub_index = 0;

				if (index_cnt == index) {
					if (dimension == 1) {
						mat_char[line][k] = 0;
					} else if (dimension == 2) {
						mat_char[line][k + 1] = 0;
						mat_char[line][k] = 0;
					} else if (dimension == 4) {
						mat_char[line][k + 3] = 0;
						mat_char[line][k + 2] = 0;
						mat_char[line][k + 1] = 0;
						mat_char[line][k] = 0;
					}

					ver = 1;
					break;
				}
			}
		}

		if (ver)
			break;
	}
}

void task2_swap(int *v, char **mat_char, int dimension, int line, int index)
{
	int sub_index = 0, index_cnt = -1;
	char temp[4];
	int ver = 0;

	for (int j = 3; j <= v[line] * 4; j = j + 4) {
		temp[0] = mat_char[line][j];
		temp[1] = mat_char[line][j - 1];
		temp[2] = mat_char[line][j - 2];
		temp[3] = mat_char[line][j - 3];
		for (int k = j; k > j - 4; k--) {
			sub_index++;
			if (sub_index  == dimension) {
				index_cnt++;
				sub_index = 0;

				if (index_cnt == index) {
					if (dimension == 2) {
						char aux = mat_char[line][k];
						mat_char[line][k] = mat_char[line][k + 1];
						mat_char[line][k + 1] = aux;
						ver = 1;
						break;
					} else if (dimension == 4) {
						mat_char[line][k + 3] = temp[3];
						mat_char[line][k + 2] = temp[2];
						mat_char[line][k + 1] = temp[1];
						mat_char[line][k] = temp[0];
						ver = 1;
						break;
					}
					break;
				}
			}
		}
		if (ver)
			break;
	}
}

void task2_modify(int *v, char **mat_char,
				  int dimension, int line, int index, int new_value)
{
	int aux = v[line]; //vechea dimensiune a unei linii
	int dim = index * dimension; //noua dimensiune a unei linii

	if (dim > 4 * v[line]) {
		mat_char[line] = (char *)realloc(mat_char[line], dim + dim % 4);
		if (!mat_char[line]) {
			free(mat_char[line]);
			exit(1);
		}

		v[line] = dim / 4;
		if (dim % 4 != 0)
			v[line]++;

		for (int j = aux * 4; j < 4 * v[line]; j++)
			mat_char[line][j] = 0;
	}

	int sub_index = 0, index_cnt = 0;
	int ver = 0;

	int temp[4]; //memoreaza int ul actual, sub forma celor 4 bytes
	temp[0] = (new_value) & 0xFF;
	temp[1] = (new_value >> 8) & 0xFF;
	temp[2] = (new_value >> 16) & 0xFF;
	temp[3] = (new_value >> 24) & 0xFF;

	for (int j = 3; j <= v[line] * 4; j = j + 4) {
		for (int k = j; k > j - 4; k--) {
			sub_index++;
			if (sub_index == dimension) {
				index_cnt++;
				sub_index = 0;

				if (index_cnt == index) {
					if (dimension == 1) {
						mat_char[line][k] = temp[0];
					} else if (dimension == 2) {
						mat_char[line][k + 1] = temp[0];
						mat_char[line][k] = temp[1];
					} else if (dimension == 4) {
						mat_char[line][k + 3] = temp[0];
						mat_char[line][k + 2] = temp[1];
						mat_char[line][k + 1] = temp[2];
						mat_char[line][k] = temp[3];
					}
					ver = 1;
					break;
				}
			}
		}
		if (ver)
			break;
	}
}

void print_matrix_char(int n, int *v, char **mat_char)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4 * v[i]; j = j + 4) {
			for (int k = 0; k < 4; k++) {
				if (mat_char[i][j + k] >= 0 && mat_char[i][j + k] <= 9)
					printf("0%d", mat_char[i][j + k]);
				else if (mat_char[i][j + k] >= 10 && mat_char[i][j + k] <= 15)
					printf("0%X", (mat_char[i][j + k]) & 0xF);
				else
					printf("%X", (mat_char[i][j + k]) & 0xFF);
			}
			printf(" ");
		}
		printf("\n");
	}
}

void task3(int n, int *v, char **mat_char_2,
		   int *line_bh, int *col_bh, int *max_bh)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4 * v[i]; j++) {
			int x = task3_search(n, v, mat_char_2, i, j);
			if (x > *max_bh) {
				*max_bh = x;
				*line_bh = i;
				*col_bh = j;
			}
		}
	}
}

int task3_search(int n, int *v, char **mat_char_2, int line_bh, int col_bh)
{
	int dim_bh = 0; // dimensiunea black hole-ului

	if (mat_char_2[line_bh][col_bh] == 0) {
		dim_bh++;
		mat_char_2[line_bh][col_bh] = 1;

		if (col_bh - 1 >= 0)
			dim_bh += task3_search(n, v, mat_char_2, line_bh, col_bh - 1);

		if (col_bh + 1 < 4 * v[line_bh])
			dim_bh += task3_search(n, v, mat_char_2, line_bh, col_bh + 1);

		if (line_bh - 1 >= 0 && (4 * v[line_bh - 1] > col_bh))
			dim_bh += task3_search(n, v, mat_char_2, line_bh - 1, col_bh);

		if (line_bh + 1 < n && (4 * v[line_bh + 1] > col_bh))
			dim_bh += task3_search(n, v, mat_char_2, line_bh + 1, col_bh);
	}

	return dim_bh;
}

void free_memory(int n, int *v, int **mat, char **mat_char, char **mat_char_2)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
		free(mat_char[i]);
		free(mat_char_2[i]);
	}
	free(mat);
	free(mat_char);
	free(mat_char_2);
	free(v);
}
