// Created by Cta_Last
#ifndef CLIONPROJECTS_MATRICES_CONSISTENTES_H
#define CLIONPROJECTS_MATRICES_CONSISTENTES_H
#include <stdio.h>
#include <stdlib.h>

//Leer matriz
void leerMat(int n, int m, int matriz[][m]){
    printf("Ingresa los elementos de la matriz: \n");
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++){
            printf("Valor [%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
            fflush(stdin);
        }
    }
}

//Imprimir matriz
void imprimirMat(int n, int m, int matriz[][m]){
    for(int i=0; i<n; i++){
        printf("|");
        for(int j=0; j<m; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

//Suma de matrices
void sumaMat(int n, int m, int matrizA[][m], int matrizB[][m], int matrizR[][m]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrizR[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

//Resta de matrices
void restaMat(int n, int m, int matrizA[][m], int matrizB[][m], int matrizR[][m]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrizR[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

//Multiplicación de matrices
void productoMat(int n, int m, int matrizA[][m], int matrizB[][m], int matrizR[][m]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrizR[i][j] = matrizA[i][j] * matrizB[i][j];
        }
    }
}

//Multiplicar un vector por una matriz
void productoVecMat(int n, int m, int vector[], int matriz[][m], int matrizR[][m]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrizR[i][j] = vector[i] * matriz[i][j];
        }
    }
}

//Suma de columnas
void sumaCol(int n, int m, int matrizA[][m], int matrizB[][m], int matrizR[], int select){
    for(int j=0; j<m; j++){
        matrizR[j] = 0;
        if (select == 1){
            for(int i=0; i<n; i++){
                matrizR[j] += matrizA[i][j];
            }
        } else if (select == 2){
            for(int i=0; i<n; i++){
                matrizR[j] += matrizB[i][j];
            }
        }
    }
}

//Leer matrices por el usuario
void readMat(int n, int m, int matriz[][m], char *InfoMat) {
    FILE *archivo = fopen(InfoMat, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(archivo, "%d", &matriz[i][j]);
        }
    }
    fclose(archivo);
}

//Guardar matriz
void guardarMat(int n, int m, int matriz[][m], char *InfoMat) {
    FILE *archivo = fopen(InfoMat, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar los datos.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(archivo, "%d ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}

//Leer vector
void leerVec(int n, int vector[], char *InfoVec) {
    FILE *archivo = fopen(InfoVec, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%d", &vector[i]);
    }
    fclose(archivo);
}

//Guardar Vector
void guardarVec(int n, int vector[], char *InfoVec) {
    FILE *archivo = fopen(InfoVec, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar los datos.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d ", vector[i]);
    }
    fclose(archivo);
}

#endif