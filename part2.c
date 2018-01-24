#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[]) {

  //ok first lets take in arguments for the matrices dimensions
  //one argument: N
  if (argc == 1) {
    //there was no argument given
    printf("%s\n","no argument was given please execute file with appropriate argument" );
    return 0;
  }

  else{
    //we now have our N!!!!
    int n = 0;
    n = atoi(argv[1]);
    srand(time(0));

  //now lets create the matrices
  //first matrix
  //values should be double
  double matrix1[n][n];
  //second matrix
  double matrix2[n][n];
  //and the third matrix to hold the answer
  double result[n][n];
  //lets now initialize both matrices
  int i;
  int j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      double value = rand() % 10 + 0;
      matrix1[i][j] = value;
    }
  }

  srand(1);
  int x;
  int y;
  for(x = 0; x < n; x++){
    for(y = 0; y < n; y++){
      double value = rand() % 10 + 0;
      matrix2[x][y] = value;
    }
  }

  //now lets open a file to write the results to!!!
  //results = n and time it took to compute
  FILE *fp;
  fp = fopen("lab1p2.txt","a");

  //to get the time i have to start the clock

  //ok so for part two we are going to test the processing time for the following matrix
  //multiplication configurations
  // qwe ( default ) ( 10x )
  // wqe             ( 10x )

  //now lets perform some calculations and time it!!!
  int q; //rows
  int w; //columns
  int e;
  int reps;
  //the first matrices row should be the last thing to change within a cylcy
  //the second matrices column should be the second thing to change
  //and the column of the first and row of the second matrices should change first in tangent
  struct timeval  tv1, tv2;

  for(reps = 0; reps < 25; reps++){
    //lets take the time again
    gettimeofday(&tv1, NULL);
      for(q = 0; q < n; q++){
        for(w = 0; w < n; w++){
          for(e = 0; e < n; e++){
            result[q][w] += matrix1[q][e] * matrix2[e][w];
          }
        }
      }
      //take the time again
      gettimeofday(&tv2, NULL);
      //find time delta
      float microseconds = (float) (tv2.tv_usec - tv1.tv_usec);
      //now lets write our findings ( N and time delta ) to lab1.log
      fprintf(fp, "%d %.2f\n",n,microseconds );
    }
    fprintf(fp, "%s\n","----------" ); // - x10

    int second;
    for(second = 0; second < 25; second++){
      //lets take the time again
      gettimeofday(&tv1, NULL);
      for(q = 0; q < n; q++){
        for(w = 0; w < n; w++){
          for(e = 0; e < n; e++){
            result[w][q] += matrix1[w][e] * matrix2[e][q];
          }
        }
      }
      //take the time again
      gettimeofday(&tv2, NULL);
      //find time delta
      float microseconds = (float) (tv2.tv_usec - tv1.tv_usec);
      //now lets write our findings ( N and time delta ) to lab1.log
      fprintf(fp, "%d %.2f\n",n,microseconds );
    }


  fclose(fp);

  return 0;
}



}
