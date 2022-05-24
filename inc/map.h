 #include <string.h>
 int **map = nullptr;
 int row;

int** makemap(int row, int col){
    row = row;
    map = new int* [row];
            for(int i= 0; i < row; i++) {
                map[i] = new int [col];
                memset(map[i], 0, sizeof(int)*col);
            }
    return map;
 }

int** initialMap(int row, int col) {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                map[row/2][col/2] = 3;
                if(i == 0 && j == 0 || i == row -1 && j == col-1 || i == row-1 && j == 0 
                    || i == 0 && j == col-1) {
				    map[i][j] = 2;
			    } else if (i == 0 || i == row-1 || j == 0 || j == col-1) {
				    map[i][j] = 1;
			    }
            }
        }  
        return map; 
    }

int** deleteMap() {
    for(int i = 0; i < row; i++){
        delete[] map[i];
        map[i] = nullptr;        
    }
    delete[] map;
    map = nullptr;

    return 0;
}