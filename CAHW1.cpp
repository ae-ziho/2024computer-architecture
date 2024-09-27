#pragma warning(disable :4996)

/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    	 Description:  Homework #01
 *
 *       Version:  1.0
 *       Created:  2000-00-00
 *       Revision:  none
 *       Compiler:  g++
 *
 * 	 Student Name: Jiho Park
 * 	 Student ID: 2176160
 *   	 Organization:  Ewha Womans University
 *
 * =====================================================================================
 */

 /*
  * -------- Please carefully review the following instructions --------
  * When executing this project, ensure that your name and student ID are displayed.
  * Avoid any extraneous print statements; remove debugging-related printf functions before final submission.
  * -->Failure to comply will result in a 20% penalty.
  * Before submitting your assignment, execute the 'make clean' command.
  * Rename the project folder to studentID_yourname (e.g., 1234567_myungkukyoon).
  * Remember to compress the entire project folder; do not compress individual files.
  * -->Failure to do so will incur a 20% penalty. Use a ZIP compression tool; do not utilize the TAR command.
  * The compressed ZIP file should be named studentID_yourname.zip (e.g., 1234567_myungkukyoon.zip).
  * The project must pass all tests within a 5-second timeframe; otherwise, a score of 0% will be assigned.
  */

#include <stdio.h>
#include <stdlib.h>

  //CA: DO NOT CHANGE
const int MAX = 100;
const char* outputFileName = "hw01_output.txt";

//CA: DO NOT CHANGE
int matrixOutput[MAX][MAX] = { 0 };

//CA: DO NOT CHANGE
void print_output_to_file(FILE* fp, int ROW, int COL) {
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            fprintf(fp, "%d ", matrixOutput[y][x]);
        }
        fprintf(fp, "\n");
    }
}

//CA: Please write your code

void matrix_mult(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int X, int Y, int Z) {
    for (int i = 0; i < X; i++) {
        for (int k = 0; k < Z; k++) {
            result[i][k] = 0;
            for (int j = 0; j < Y; j++)
                result[i][k] += A[i][j] * B[j][k];
        }
    }
}

void matrix_add(int C[MAX][MAX], int result[MAX][MAX], int X, int Z) {
    for (int i = 0; i < X; i++) {
        for (int k = 0; k < Z; k++) {
            result[i][k] += C[i][k];
        }
    }
}

int main() {
    //CA: YOUR NAME with Student ID
    printf("Park, Jiho (2176160)\n");

    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        exit(1);
    }

    FILE* fp = fopen(outputFileName, "w");

    int testsets;
    fscanf(inputFile, "%d", &testsets);


    for (int test = 0; test < testsets; test++) {

        int X; int Y; int Z;
        fscanf(inputFile, "%d %d %d", &X, &Y, &Z);

        int A[MAX][MAX];
        int B[MAX][MAX];
        int result[MAX][MAX] = { 0 };
        int C[MAX][MAX];

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                fscanf(inputFile, "%d", &A[i][j]);
            }
        }

        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                fscanf(inputFile, "%d", &B[j][k]);
            }
        }

        for (int i = 0; i < X; i++) {
            for (int k = 0; k < Z; k++) {
                fscanf(inputFile, "%d", &C[i][k]);
            }
        }

        matrix_mult(A, B, result, X, Y, Z);
        matrix_add(C, result, X, Z);

        for (int i = 0; i < X; i++) {
            for (int k = 0; k < Z; k++) {
                matrixOutput[i][k] = result[i][k];
            }
        }
        print_output_to_file(fp, X, Z);

    }

    fclose(inputFile);
    fclose(fp);
    return true;
}



